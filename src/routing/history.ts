/**
 * Thin wrapper around the browser history. Each entry records the hash of its
 * parent level, so the Escape key can go up one level with the back button.
 */

/** Data stored with each history entry. */
interface HistoryState {
  /** Hash of the parent level, or null when the entry has no parent. */
  readonly up: string | null;
}

/**
 * Reads the current location hash.
 * @returns The hash, or an empty string when the URL has none.
 */
export function currentHash(): string {
  return window.location.hash;
}

/**
 * Replaces the current history entry without adding one.
 * @param hash Hash to show in the address bar.
 * @param up Hash of the parent level, or null.
 */
export function replaceEntry(hash: string, up: string | null): void {
  window.history.replaceState(createState(up), '', hash);
}

/**
 * Adds a history entry for a deeper level.
 * @param hash Hash of the new level.
 * @param up Hash of the level it was opened from.
 */
export function pushEntry(hash: string, up: string): void {
  window.history.pushState(createState(up), '', hash);
}

/**
 * Turns a deep link into one history entry per level, so the back button
 * climbs one level at a time instead of leaving the site.
 * @param hashes Hashes from the home screen down to the target.
 */
export function seedEntries(hashes: readonly string[]): void {
  const [first, ...deeper] = hashes;
  if (first === undefined) return;

  replaceEntry(first, null);
  let parent = first;
  for (const hash of deeper) {
    pushEntry(hash, parent);
    parent = hash;
  }
}

/**
 * Reads the parent hash recorded with the current history entry.
 * @returns The parent hash, or null when none was recorded.
 */
export function readParentHash(): string | null {
  const state: unknown = window.history.state;
  return isHistoryState(state) ? state.up : null;
}

/** Moves one entry back in the browser history. */
export function stepBack(): void {
  window.history.back();
}

/**
 * Calls a listener whenever the user navigates through history, including
 * the back button and direct edits to the hash.
 * @param listener Called after each history change.
 */
export function onHistoryChange(listener: () => void): void {
  window.addEventListener('popstate', listener);
}

function createState(up: string | null): HistoryState {
  return { up };
}

function isHistoryState(state: unknown): state is HistoryState {
  if (typeof state !== 'object' || state === null || !('up' in state)) {
    return false;
  }
  return state.up === null || typeof state.up === 'string';
}
