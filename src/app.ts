import {
  ancestorsOf,
  findYear,
  HOME,
  parentOf,
  parseHash,
  routeToHash,
  type Route,
} from "./route";
import { collapse, expand, hideContent, reveal } from "./motion";
import {
  buildCrumbs,
  buildHome,
  buildSubjectView,
  buildYearView,
  type LayerView,
  type Open,
} from "./views";

/** One open expanded view. Layers stack: a year sits over home, a subject over its year. */
type Layer = {
  key: string;
  route: Route;
  /** Full-window container: carries the background and the clip-path animation. */
  el: HTMLElement;
  /** Padded content column: fades out before the container collapses. */
  inner: HTMLElement;
  /** Scroll container for the view's content. */
  body: HTMLElement;
  /** The element that opened this layer; focus returns to it on close. */
  opener: Element | null;
};

let host: HTMLElement;
let home: HTMLElement;
let layersHost: HTMLElement;
let layers: Layer[] = [];
let currentRoute: Route = HOME;
let currentKey = "";
let titleCounter = 0;

/** Remembers each layer's scroll position so reopening restores it. */
const scrollMemo = new Map<string, number>();

const open: Open = (route, origin) => navigate(route, origin);

/**
 * Mounts the app. Deep links are expanded into their full chain of history
 * entries, so the browser back button climbs one level at a time and never
 * leaves the site while a parent level exists.
 */
export function startApp(root: HTMLElement): void {
  host = root;
  host.replaceChildren();

  home = buildHome(open);
  layersHost = document.createElement("div");
  layersHost.className = "layers";
  host.append(home, layersHost);

  document.addEventListener("keydown", onKeydown);
  window.addEventListener("popstate", () => sync(parseHash(location.hash), null));

  boot();
}

function boot(): void {
  const target = parseHash(location.hash);
  const chain = [...ancestorsOf(target), target];
  const first = chain[0] ?? HOME;

  history.replaceState({ up: null }, "", routeToHash(first));
  for (let index = 1; index < chain.length; index++) {
    const previous = chain[index - 1] ?? HOME;
    const current = chain[index] ?? HOME;
    history.pushState({ up: routeToHash(previous) }, "", routeToHash(current));
  }

  sync(target, null);
}

/** Opens a route from a user action. `origin` is the element that expands. */
function navigate(route: Route, origin: Element | null): void {
  const hash = routeToHash(route);
  if (hash === routeToHash(currentRoute)) return;
  history.pushState({ up: routeToHash(currentRoute) }, "", hash);
  sync(route, origin);
}

/** Moves up one level: a history step when the parent is the previous entry, otherwise a replace. */
function goUp(): void {
  const parent = parentOf(currentRoute);
  if (!parent) return;
  const parentHash = routeToHash(parent);
  if (readUp() === parentHash) {
    history.back();
    return;
  }
  history.replaceState({ up: null }, "", parentHash);
  sync(parent, null);
}

function readUp(): string | null {
  const state: unknown = history.state;
  if (state !== null && typeof state === "object" && "up" in state) {
    const up = (state as { up: unknown }).up;
    return typeof up === "string" ? up : null;
  }
  return null;
}

/** Applies a route to the screen. Duplicate routes are ignored. */
function sync(route: Route, origin: Element | null): void {
  const key = routeToHash(route);
  if (key === currentKey) return;
  currentKey = key;
  currentRoute = route;
  render(route, origin);
}

function render(route: Route, origin: Element | null): void {
  const levels = [...ancestorsOf(route), route].filter((level) => level.kind !== "home");

  let common = 0;
  while (
    common < layers.length &&
    common < levels.length &&
    layers[common]?.key === routeToHash(levels[common] ?? HOME)
  ) {
    common++;
  }

  const closing = layers.splice(common);
  for (const layer of closing) closeLayer(layer);

  for (let index = common; index < levels.length; index++) {
    const level = levels[index] ?? HOME;
    openLayer(level, index === common ? origin : null);
  }

  updateInert();

  const returnTo = closing[0]?.opener ?? null;
  if (returnTo instanceof HTMLElement && isReachable(returnTo)) {
    returnTo.focus({ preventScroll: true });
  } else {
    focusTop();
  }
}

function viewFor(route: Route): LayerView | null {
  switch (route.kind) {
    case "home":
      return null;
    case "year": {
      const year = findYear(route.year);
      return year ? buildYearView(year, open) : null;
    }
    case "subject":
      return buildSubjectView(route);
  }
}

function openLayer(route: Route, opener: Element | null): void {
  const view = viewFor(route);
  if (!view) return;

  const key = routeToHash(route);
  const titleId = `layer-title-${++titleCounter}`;

  const el = document.createElement("section");
  el.className = `layer layer--${route.kind}`;
  el.setAttribute("role", "dialog");
  el.setAttribute("aria-modal", "true");
  el.setAttribute("aria-labelledby", titleId);

  const inner = document.createElement("div");
  inner.className = "layer__inner";

  const top = document.createElement("div");
  top.className = "layer__top";
  top.dataset["reveal"] = "";
  const close = document.createElement("button");
  close.type = "button";
  close.className = "layer__close";
  close.textContent = "Close";
  close.addEventListener("click", goUp);
  top.append(buildCrumbs(view.crumbs), close);

  const title = document.createElement("h2");
  title.className = "layer__title";
  title.id = titleId;
  title.tabIndex = -1;
  title.textContent = view.title;
  title.dataset["reveal"] = "";

  inner.append(top, title, view.body);
  el.append(inner);
  layersHost.append(el);

  const layer: Layer = { key, route, el, inner, body: view.body, opener };
  layers.push(layer);

  view.body.scrollTop = scrollMemo.get(key) ?? 0;
  expand(el, opener);
  reveal(inner);
}

function closeLayer(layer: Layer): void {
  scrollMemo.set(layer.key, layer.body.scrollTop);
  layer.el.inert = true;
  hideContent(layer.inner);
  const animation = collapse(layer.el, layer.opener);
  animation.finished.catch(() => undefined).then(() => layer.el.remove());
}

/** Only the top layer is interactive. Home and the layers under it are inert while any layer is open. */
function updateInert(): void {
  home.inert = layers.length > 0;
  layers.forEach((layer, index) => {
    layer.el.inert = index !== layers.length - 1;
  });
}

function isReachable(node: Element): boolean {
  return node.isConnected && node.closest("[inert]") === null;
}

function focusTop(): void {
  const top = layers[layers.length - 1];
  if (top) {
    top.el.querySelector<HTMLElement>(".layer__title")?.focus({ preventScroll: true });
    return;
  }
  home.querySelector<HTMLElement>(".tile")?.focus({ preventScroll: true });
}

function onKeydown(event: KeyboardEvent): void {
  if (layers.length === 0) return;
  if (event.key === "Escape") {
    event.preventDefault();
    goUp();
    return;
  }
  if (event.key === "Tab") keepFocusInTopLayer(event);
}

/** Keeps Tab and Shift+Tab inside the open dialog, since the layers below are inert. */
function keepFocusInTopLayer(event: KeyboardEvent): void {
  const top = layers[layers.length - 1];
  if (!top) return;
  const focusables = [
    ...top.el.querySelectorAll<HTMLElement>(
      'a[href], button:not([disabled]), [tabindex]:not([tabindex="-1"])',
    ),
  ];
  const first = focusables[0];
  const last = focusables[focusables.length - 1];
  if (!first || !last) return;

  const active = document.activeElement;
  const inside = active !== null && top.el.contains(active);
  if (event.shiftKey && (!inside || active === first)) {
    event.preventDefault();
    last.focus();
  } else if (!event.shiftKey && (!inside || active === last)) {
    event.preventDefault();
    first.focus();
  }
}
