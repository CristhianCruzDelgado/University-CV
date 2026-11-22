import { REVEAL_ATTRIBUTE } from '../motion/constants';

/** Relations for links that open in a new tab. */
const EXTERNAL_LINK_REL = 'noopener noreferrer';

/** Optional settings for {@link createElement}. */
interface ElementOptions {
  /** Class name, written in lowercase kebab-case. */
  readonly className?: string;
  /** Text content. Set through `textContent`, so it is never parsed as HTML. */
  readonly text?: string;
  /** Marks the element to fade in after its container settles. */
  readonly reveal?: boolean;
}

/**
 * Creates an element with the given class, text and reveal marker.
 * @param tag Tag name of the element to create.
 * @param options Class, text and reveal settings.
 * @returns The new element.
 */
export function createElement<K extends keyof HTMLElementTagNameMap>(
  tag: K,
  options: ElementOptions = {},
): HTMLElementTagNameMap[K] {
  const element = document.createElement(tag);
  if (options.className !== undefined) {
    element.className = options.className;
  }
  if (options.text !== undefined) {
    element.textContent = options.text;
  }
  if (options.reveal === true) {
    element.setAttribute(REVEAL_ATTRIBUTE, '');
  }
  return element;
}

/**
 * Creates a link that opens in a new tab, without giving the new page access
 * to this one.
 * @param text Visible text of the link.
 * @param href Target of the link.
 * @param className Class name of the link.
 * @returns The anchor element.
 */
export function createExternalLink(
  text: string,
  href: string,
  className: string,
): HTMLAnchorElement {
  const anchor = createElement('a', { className, text });
  anchor.href = href;
  anchor.target = '_blank';
  anchor.rel = EXTERNAL_LINK_REL;
  return anchor;
}
