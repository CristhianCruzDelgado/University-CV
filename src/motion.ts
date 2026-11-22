/**
 * Motion for the expanding views. Everything runs on the Web Animations API and
 * animates only `clip-path`, `transform` and `opacity`, so it stays on the
 * compositor and avoids layout work. Reduced-motion users get a crossfade.
 */

/** Exponential ease-out: the view leaves the origin fast and settles softly. */
const EASE_OUT = "cubic-bezier(0.16, 1, 0.3, 1)";
/** Symmetric ease for the collapse, so the return reads as deliberate. */
const EASE_IN_OUT = "cubic-bezier(0.76, 0, 0.24, 1)";

export const OPEN_MS = 720;
export const CLOSE_MS = 520;
const REVEAL_MS = 560;
const REVEAL_STAGGER_MS = 55;
const CONTENT_OUT_MS = 180;
const ORIGIN_RADIUS_PX = 14;

const reducedQuery =
  typeof matchMedia === "function" ? matchMedia("(prefers-reduced-motion: reduce)") : null;

export function prefersReducedMotion(): boolean {
  return reducedQuery?.matches ?? false;
}

/** Whether an origin element can still anchor an animation on screen. */
export function usableOrigin(origin: Element | null): origin is Element {
  if (!origin || !origin.isConnected) return false;
  if (origin.closest("[inert]")) return false;
  const rect = origin.getBoundingClientRect();
  return rect.width > 0 && rect.height > 0;
}

/** Converts a viewport rectangle into a clip-path inset that a full-screen layer can animate to. */
function insetFor(rect: DOMRect): string {
  const vw = window.innerWidth;
  const vh = window.innerHeight;
  const clamp = (value: number, max: number) => Math.min(Math.max(value, 0), max);
  const top = clamp(rect.top, vh);
  const left = clamp(rect.left, vw);
  const right = clamp(vw - rect.right, vw);
  const bottom = clamp(vh - rect.bottom, vh);
  return `inset(${top}px ${right}px ${bottom}px ${left}px round ${ORIGIN_RADIUS_PX}px)`;
}

const FULL_CLIP = "inset(0px 0px 0px 0px round 0px)";

/** Grows a layer out of the origin rectangle until it fills the window. */
export function expand(el: HTMLElement, origin: Element | null): Animation {
  if (prefersReducedMotion()) {
    return el.animate([{ opacity: 0 }, { opacity: 1 }], { duration: 240, easing: "linear" });
  }
  if (usableOrigin(origin)) {
    return el.animate(
      [
        { clipPath: insetFor(origin.getBoundingClientRect()), transform: "scale(0.985)" },
        { clipPath: FULL_CLIP, transform: "scale(1)" },
      ],
      { duration: OPEN_MS, easing: EASE_OUT },
    );
  }
  return el.animate(
    [
      { opacity: 0, transform: "scale(0.97)" },
      { opacity: 1, transform: "scale(1)" },
    ],
    { duration: 480, easing: EASE_OUT },
  );
}

/** Shrinks a layer back into its origin rectangle. Falls back to a fade when the origin is gone. */
export function collapse(el: HTMLElement, origin: Element | null): Animation {
  if (prefersReducedMotion()) {
    return el.animate([{ opacity: 1 }, { opacity: 0 }], {
      duration: 200,
      easing: "linear",
      fill: "forwards",
    });
  }
  if (usableOrigin(origin)) {
    return el.animate(
      [
        { clipPath: FULL_CLIP, transform: "scale(1)" },
        { clipPath: insetFor(origin.getBoundingClientRect()), transform: "scale(0.985)" },
      ],
      { duration: CLOSE_MS, easing: EASE_IN_OUT, fill: "forwards" },
    );
  }
  return el.animate(
    [
      { opacity: 1, transform: "scale(1)" },
      { opacity: 0, transform: "scale(0.97)" },
    ],
    { duration: 320, easing: EASE_IN_OUT, fill: "forwards" },
  );
}

/** Fades the content out quickly so the container can collapse without showing its contents moving. */
export function hideContent(el: HTMLElement): Animation {
  return el.animate([{ opacity: 1 }, { opacity: 0 }], {
    duration: CONTENT_OUT_MS,
    easing: "linear",
    fill: "forwards",
  });
}

/**
 * Staggers `[data-reveal]` elements in after the container has settled. The
 * animations are created with a delay and `fill: both`, so the items stay hidden
 * from the first frame and no flash of content appears before the expansion.
 */
export function reveal(root: HTMLElement): void {
  const items = root.querySelectorAll<HTMLElement>("[data-reveal]");
  if (prefersReducedMotion()) {
    items.forEach((item) => {
      item.animate([{ opacity: 0 }, { opacity: 1 }], {
        duration: 220,
        delay: 80,
        easing: "linear",
        fill: "both",
      });
    });
    return;
  }
  const settleDelay = OPEN_MS * 0.72;
  items.forEach((item, index) => {
    item.animate(
      [
        { opacity: 0, transform: "translate3d(0, 14px, 0)" },
        { opacity: 1, transform: "translate3d(0, 0, 0)" },
      ],
      {
        duration: REVEAL_MS,
        delay: settleDelay + index * REVEAL_STAGGER_MS,
        easing: EASE_OUT,
        fill: "both",
      },
    );
  });
}
