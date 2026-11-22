import { routeToHash, type LayeredRoute } from '../routing/route';
import {
  collapseLayer,
  expandLayer,
  fadeOutContent,
  revealContent,
} from '../motion/animations';
import type { LayerFrame } from '../views/layer-frame';

/** A layer that is open on the stack, with what its lifecycle needs. */
interface OpenLayer extends LayerFrame {
  /** Route hash, used to tell whether a layer stays open. */
  readonly key: string;
  /** Element that opened the layer. Focus returns to it on close. */
  readonly opener: Element | undefined;
}

/**
 * Keeps the stack of expanded layers in step with the current route. A year
 * sits over the home screen, and a subject sits over its year. Layers that
 * stay open are never rebuilt, so their state survives the navigation.
 */
export class LayerStack {
  private readonly host: HTMLElement;
  private readonly createFrame: (route: LayeredRoute) => LayerFrame;
  private readonly layers: OpenLayer[] = [];
  private readonly scrollMemory = new Map<string, number>();

  /**
   * @param host Element that receives the layers.
   * @param createFrame Builds the frame of a layer for a route.
   */
  constructor(
    host: HTMLElement,
    createFrame: (route: LayeredRoute) => LayerFrame,
  ) {
    this.host = host;
    this.createFrame = createFrame;
  }

  /**
   * Tells whether any layer is open.
   * @returns True when the home screen is the only visible level.
   */
  isEmpty(): boolean {
    return this.layers.length === 0;
  }

  /**
   * Returns the outermost element of the layer on top of the stack.
   * @returns The top layer element, or undefined when the stack is empty.
   */
  topElement(): HTMLElement | undefined {
    return this.layers.at(-1)?.element;
  }

  /**
   * Makes the open layers match the requested levels. Layers that differ are
   * closed, and the missing ones are opened. Only the first new layer grows
   * from `origin`, because it is the element the user pressed.
   * @param levels Layers that must be open, from the bottom up.
   * @param origin Element the user pressed, or undefined for a deep link.
   * @returns The element that focus should return to, if any layer closed.
   */
  reconcile(
    levels: readonly LayeredRoute[],
    origin: Element | undefined,
  ): Element | undefined {
    const kept = this.sharedPrefixLength(levels);
    const closing = this.layers.splice(kept);
    closing.forEach((layer) => {
      this.closeLayer(layer);
    });

    levels.slice(kept).forEach((level, index) => {
      this.openLayer(level, index === 0 ? origin : undefined);
    });

    this.refreshInert();
    return closing[0]?.opener;
  }

  private sharedPrefixLength(levels: readonly LayeredRoute[]): number {
    let length = 0;
    while (length < this.layers.length && length < levels.length) {
      const level = levels[length];
      if (level === undefined) break;
      if (this.layers[length]?.key !== routeToHash(level)) break;
      length++;
    }
    return length;
  }

  private openLayer(route: LayeredRoute, opener: Element | undefined): void {
    const frame = this.createFrame(route);
    const key = routeToHash(route);
    this.host.append(frame.element);
    this.layers.push({ ...frame, key, opener });

    frame.body.scrollTop = this.scrollMemory.get(key) ?? 0;
    expandLayer(frame.element, opener);
    revealContent(frame.inner);
  }

  private closeLayer(layer: OpenLayer): void {
    this.scrollMemory.set(layer.key, layer.body.scrollTop);
    layer.element.inert = true;
    fadeOutContent(layer.inner);
    const animation = collapseLayer(layer.element, layer.opener);
    animation.addEventListener('finish', () => {
      layer.element.remove();
    });
  }

  /** Only the top layer stays interactive. The layers below are inert. */
  private refreshInert(): void {
    const topIndex = this.layers.length - 1;
    this.layers.forEach((layer, index) => {
      layer.element.inert = index !== topIndex;
    });
  }
}
