import type { LayeredRoute } from '../routing/route';
import { UI_TEXT } from '../text';
import { buildBreadcrumbs } from './breadcrumbs';
import { createElement } from './dom';
import type { LayerContent } from './view-types';

/** The elements of an expanded view that the stack and animations use. */
export interface LayerFrame {
  /** Full-window container, which carries the background and the animation. */
  readonly element: HTMLElement;
  /** Padded column that holds the header and the body. */
  readonly inner: HTMLElement;
  /** Scrollable body, which keeps its scroll position between openings. */
  readonly body: HTMLElement;
}

/**
 * Wraps the content of a view in a dialog frame with breadcrumbs, a close
 * button and a heading.
 * @param kind Kind of route the layer shows.
 * @param content Heading, breadcrumbs and body of the view.
 * @param onClose Called when the close button is pressed.
 * @returns The frame, ready to be added to the page.
 */
export function buildLayerFrame(
  kind: LayeredRoute['kind'],
  content: LayerContent,
  onClose: () => void,
): LayerFrame {
  const titleId = `layer-title-${crypto.randomUUID()}`;
  const element = createElement('section', {
    className: `layer layer-${kind}`,
  });
  element.setAttribute('role', 'dialog');
  element.setAttribute('aria-modal', 'true');
  element.setAttribute('aria-labelledby', titleId);

  const inner = createElement('div', { className: 'layer-inner' });
  inner.append(
    buildLayerTop(content, onClose),
    buildLayerTitle(content.title, titleId),
    content.body,
  );
  element.append(inner);

  return { element, inner, body: content.body };
}

function buildLayerTop(
  content: LayerContent,
  onClose: () => void,
): HTMLElement {
  const top = createElement('div', { className: 'layer-top', reveal: true });
  const close = createElement('button', {
    className: 'layer-close',
    text: UI_TEXT.close,
  });
  close.type = 'button';
  close.addEventListener('click', onClose);
  top.append(buildBreadcrumbs(content.crumbs), close);
  return top;
}

function buildLayerTitle(text: string, id: string): HTMLHeadingElement {
  const title = createElement('h2', {
    className: 'layer-title',
    text,
    reveal: true,
  });
  title.id = id;
  title.tabIndex = -1;
  return title;
}
