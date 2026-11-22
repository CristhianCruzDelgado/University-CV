/** Selector for every control that can receive keyboard focus. */
const FOCUSABLE_SELECTOR =
  'a[href], button:not([disabled]), [tabindex]:not([tabindex="-1"])';

const TAB_KEY = 'Tab';

/**
 * Moves focus to an element without scrolling the page.
 * @param element Element to focus.
 */
function focusWithoutScroll(element: HTMLElement): void {
  element.focus({ preventScroll: true });
}

/**
 * Tells whether an element can receive focus right now.
 * @param element Element to check.
 * @returns True when it is connected and not inside an inert subtree.
 */
export function isReachable(element: Element): boolean {
  return element.isConnected && element.closest('[inert]') === null;
}

/** The first and last focusable controls of a dialog. */
interface FocusBounds {
  /** Dialog that holds the controls. */
  readonly container: HTMLElement;
  /** First control in the dialog, in document order. */
  readonly first: HTMLElement;
  /** Last control in the dialog, in document order. */
  readonly last: HTMLElement;
}

/**
 * Keeps Tab and Shift+Tab inside a dialog. Focus wraps from the last control
 * to the first, and back again, because the layers below are inert.
 * @param event Keyboard event to handle.
 * @param container Dialog that must keep focus.
 */
export function keepFocusWithin(
  event: KeyboardEvent,
  container: HTMLElement,
): void {
  if (event.key !== TAB_KEY) return;

  const bounds = focusBoundsOf(container);
  if (bounds === undefined) return;

  const target = wrapTarget(event, bounds);
  if (target === undefined) return;
  event.preventDefault();
  focusWithoutScroll(target);
}

function focusBoundsOf(container: HTMLElement): FocusBounds | undefined {
  const focusables = Array.from(
    container.querySelectorAll<HTMLElement>(FOCUSABLE_SELECTOR),
  );
  const first = focusables[0];
  const last = focusables.at(-1);
  if (first === undefined || last === undefined) return undefined;
  return { container, first, last };
}

/**
 * Chooses the control that Tab should wrap to, if the browser would leave
 * the dialog. Returns undefined when the browser's own Tab order is fine.
 * @param event Keyboard event for the Tab key.
 * @param bounds First and last controls of the dialog.
 * @returns The control to focus instead, or undefined.
 */
function wrapTarget(
  event: KeyboardEvent,
  bounds: FocusBounds,
): HTMLElement | undefined {
  const active = document.activeElement;
  const isInside = active !== null && bounds.container.contains(active);
  if (event.shiftKey) {
    return !isInside || active === bounds.first ? bounds.last : undefined;
  }
  return !isInside || active === bounds.last ? bounds.first : undefined;
}
