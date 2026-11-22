import { findYear, locateSubject } from '../content/lookup';
import { LayerStack } from './layers/layer-stack';
import { isReachable, keepFocusWithin } from './focus';
import {
  onHistoryChange,
  currentHash,
  pushEntry,
  readParentHash,
  replaceEntry,
  seedEntries,
  stepBack,
} from './routing/history';
import {
  ancestorRoutes,
  HOME_ROUTE,
  parentRoute,
  parseHash,
  routeToHash,
  visibleLevels,
  type LayeredRoute,
  type Route,
} from './routing/route';
import { createElement } from './views/dom';
import { buildHomeView } from './views/home-view';
import { buildLayerFrame, type LayerFrame } from './views/layer-frame';
import { buildSubjectContent } from './views/subject-view';
import type { LayerContent, OpenRoute } from './views/view-types';
import { buildYearContent } from './views/year-view';

const ESCAPE_KEY = 'Escape';
const FIRST_TILE_SELECTOR = '.tile';
const LAYER_TITLE_SELECTOR = '.layer-title';

/**
 * Mounts the site into the root element and wires navigation to the screen.
 * @param root Element that holds the whole application.
 */
export function startApp(root: HTMLElement): void {
  const app = new App(root);
  app.start();
}

/**
 * Owns the current route and keeps the home screen, the layer stack, the
 * browser history and focus in step with it.
 */
class App {
  private readonly home: HTMLElement;
  private readonly stack: LayerStack;
  private currentRoute: Route = HOME_ROUTE;
  private readonly openRoute: OpenRoute = (route, origin) => {
    this.navigate(route, origin);
  };

  /** @param root Element that holds the whole application. */
  constructor(root: HTMLElement) {
    this.home = buildHomeView(this.openRoute);
    const layersHost = createElement('div', { className: 'layers' });
    this.stack = new LayerStack(layersHost, (route) => this.createFrame(route));
    root.append(this.home, layersHost);
  }

  /** Shows the route in the address bar and wires the global listeners. */
  start(): void {
    const target = parseHash(currentHash());
    seedEntries(ancestorRoutes(target).concat(target).map(routeToHash));

    onHistoryChange(() => {
      this.syncWithLocation();
    });
    document.addEventListener('keydown', (event) => {
      this.handleKeydown(event);
    });
    this.show(target, undefined);
  }

  private navigate(route: Route, origin: Element): void {
    const hash = routeToHash(route);
    const currentHashValue = routeToHash(this.currentRoute);
    if (hash === currentHashValue) return;
    pushEntry(hash, currentHashValue);
    this.show(route, origin);
  }

  /** Moves up one level. Uses the back button when it leads to the parent. */
  private goUp(): void {
    const parent = parentRoute(this.currentRoute);
    if (parent === undefined) return;

    const parentHash = routeToHash(parent);
    if (readParentHash() === parentHash) {
      stepBack();
      return;
    }
    replaceEntry(parentHash, null);
    this.show(parent, undefined);
  }

  private syncWithLocation(): void {
    this.show(parseHash(currentHash()), undefined);
  }

  private show(route: Route, origin: Element | undefined): void {
    if (routeToHash(route) === routeToHash(this.currentRoute)) return;
    this.currentRoute = route;

    const closedOpener = this.stack.reconcile(visibleLevels(route), origin);
    this.home.inert = !this.stack.isEmpty();
    this.focusTargetFor(closedOpener)?.focus({ preventScroll: true });
  }

  /**
   * Chooses where focus goes after a change. It returns to the element that
   * opened a closed layer, otherwise into the top layer, otherwise to home.
   * @param closedOpener Element that opened the layer that just closed.
   * @returns The element to focus, if one exists.
   */
  private focusTargetFor(
    closedOpener: Element | undefined,
  ): HTMLElement | undefined {
    if (closedOpener instanceof HTMLElement && isReachable(closedOpener)) {
      return closedOpener;
    }
    const top = this.stack.topElement();
    if (top !== undefined) {
      return top.querySelector<HTMLElement>(LAYER_TITLE_SELECTOR) ?? undefined;
    }
    return (
      this.home.querySelector<HTMLElement>(FIRST_TILE_SELECTOR) ?? undefined
    );
  }

  private createFrame(route: LayeredRoute): LayerFrame {
    return buildLayerFrame(route.kind, this.contentFor(route), () => {
      this.goUp();
    });
  }

  private contentFor(route: LayeredRoute): LayerContent {
    if (route.kind === 'year') {
      const year = findYear(route.yearId);
      if (year === undefined) {
        throw new Error(`Unknown academic year: ${route.yearId}`);
      }
      return buildYearContent(year, this.openRoute);
    }

    const location = locateSubject(
      route.yearId,
      route.semesterId,
      route.subjectId,
    );
    if (location === undefined) {
      throw new Error(`Unknown subject: ${route.subjectId}`);
    }
    return buildSubjectContent(location);
  }

  private handleKeydown(event: KeyboardEvent): void {
    if (this.stack.isEmpty()) return;

    if (event.key === ESCAPE_KEY) {
      event.preventDefault();
      this.goUp();
      return;
    }
    const top = this.stack.topElement();
    if (top !== undefined) keepFocusWithin(event, top);
  }
}
