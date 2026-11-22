import { REVEAL_ATTRIBUTE } from '../motion/constants';

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
