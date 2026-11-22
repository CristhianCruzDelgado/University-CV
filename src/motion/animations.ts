import {
  CLOSE_DURATION_MS,
  CONTENT_FADE_DURATION_MS,
  CROSSFADE_CLOSE_DURATION_MS,
  CROSSFADE_OPEN_DURATION_MS,
  CROSSFADE_REVEAL_DELAY_MS,
  CROSSFADE_REVEAL_DURATION_MS,
  EASE_IN_OUT,
  EASE_LINEAR,
  EASE_OUT,
  FALLBACK_CLOSE_DURATION_MS,
  FALLBACK_OPEN_DURATION_MS,
  FALLBACK_SCALE,
  OPEN_DURATION_MS,
  ORIGIN_RADIUS_PX,
  ORIGIN_SCALE,
  REVEAL_ATTRIBUTE,
  REVEAL_DURATION_MS,
  REVEAL_OFFSET_PX,
  REVEAL_START_RATIO,
  REVEAL_STAGGER_MS,
} from './constants';

const REDUCED_MOTION_QUERY = '(prefers-reduced-motion: reduce)';
const FULL_WINDOW_CLIP = 'inset(0px 0px 0px 0px round 0px)';
const SCALE_AT_REST = 'scale(1)';

/** Opacity-only frames used when the user prefers reduced motion. */
const FADE_IN_FRAMES: Keyframe[] = [{ opacity: 0 }, { opacity: 1 }];
const FADE_OUT_FRAMES: Keyframe[] = [{ opacity: 1 }, { opacity: 0 }];

/** Frames for a layer that appears without an origin: a short scale-up. */
const FALLBACK_IN_FRAMES: Keyframe[] = [
  { opacity: 0, transform: `scale(${FALLBACK_SCALE})` },
  { opacity: 1, transform: SCALE_AT_REST },
];

/** Frames for a layer that disappears without an origin: a short scale-down. */
const FALLBACK_OUT_FRAMES: Keyframe[] = [
  { opacity: 1, transform: SCALE_AT_REST },
  { opacity: 0, transform: `scale(${FALLBACK_SCALE})` },
];

/** Frames for content that rises into place after its container settles. */
const RISE_IN_FRAMES: Keyframe[] = [
  {
    opacity: 0,
    transform: `translate3d(0, ${REVEAL_OFFSET_PX}px, 0)`,
  },
  { opacity: 1, transform: 'translate3d(0, 0, 0)' },
];

/**
 * Tells whether the user asked the system to reduce motion.
 * @returns True when the reduced-motion preference is set.
 */
function prefersReducedMotion(): boolean {
  return window.matchMedia(REDUCED_MOTION_QUERY).matches;
}

/**
 * Tells whether an origin element can anchor an animation on screen.
 * @param origin Element that the layer grows from or shrinks into.
 * @returns True when the element is connected, visible and not inert.
 */
function isUsableOrigin(origin: Element | undefined): origin is Element {
  if (origin?.isConnected !== true) return false;
  if (origin.closest('[inert]') !== null) return false;
  const rect = origin.getBoundingClientRect();
  return rect.width > 0 && rect.height > 0;
}

/**
 * Grows a layer from the rectangle of its origin until it fills the window.
 * @param element Full-window layer to animate.
 * @param origin Element that was pressed, or undefined for a deep link.
 */
export function expandLayer(
  element: HTMLElement,
  origin: Element | undefined,
): void {
  if (prefersReducedMotion()) {
    element.animate(FADE_IN_FRAMES, {
      duration: CROSSFADE_OPEN_DURATION_MS,
      easing: EASE_LINEAR,
    });
    return;
  }
  if (isUsableOrigin(origin)) {
    element.animate(originFrames(origin.getBoundingClientRect(), 'open'), {
      duration: OPEN_DURATION_MS,
      easing: EASE_OUT,
    });
    return;
  }
  element.animate(FALLBACK_IN_FRAMES, {
    duration: FALLBACK_OPEN_DURATION_MS,
    easing: EASE_OUT,
  });
}

/**
 * Shrinks a layer back into the rectangle of its origin.
 * @param element Full-window layer to animate.
 * @param origin Element that opened the layer, or undefined when it has none.
 * @returns The running animation, so the caller can remove the layer after it.
 */
export function collapseLayer(
  element: HTMLElement,
  origin: Element | undefined,
): Animation {
  if (prefersReducedMotion()) {
    return element.animate(FADE_OUT_FRAMES, {
      duration: CROSSFADE_CLOSE_DURATION_MS,
      easing: EASE_LINEAR,
      fill: 'forwards',
    });
  }
  if (isUsableOrigin(origin)) {
    return element.animate(
      originFrames(origin.getBoundingClientRect(), 'close'),
      { duration: CLOSE_DURATION_MS, easing: EASE_IN_OUT, fill: 'forwards' },
    );
  }
  return element.animate(FALLBACK_OUT_FRAMES, {
    duration: FALLBACK_CLOSE_DURATION_MS,
    easing: EASE_IN_OUT,
    fill: 'forwards',
  });
}

/**
 * Fades the content of a layer out before its container collapses.
 * @param content Element that holds the layer's content.
 * @returns The running animation.
 */
export function fadeOutContent(content: HTMLElement): Animation {
  return content.animate(FADE_OUT_FRAMES, {
    duration: CONTENT_FADE_DURATION_MS,
    easing: EASE_LINEAR,
    fill: 'forwards',
  });
}

/**
 * Staggers in every element marked for reveal inside a container. Items stay
 * hidden from the first frame because the animations use `fill: both`.
 * @param container Element whose marked descendants should reveal.
 */
export function revealContent(container: HTMLElement): void {
  const reduced = prefersReducedMotion();
  const items = container.querySelectorAll<HTMLElement>(
    `[${REVEAL_ATTRIBUTE}]`,
  );
  items.forEach((item, index) => {
    if (reduced) {
      item.animate(FADE_IN_FRAMES, reducedRevealTiming());
    } else {
      item.animate(RISE_IN_FRAMES, fullRevealTiming(index));
    }
  });
}

function originFrames(rect: DOMRect, direction: 'open' | 'close'): Keyframe[] {
  const fromOrigin: Keyframe = {
    clipPath: insetFromRect(rect),
    transform: `scale(${ORIGIN_SCALE})`,
  };
  const toFullWindow: Keyframe = {
    clipPath: FULL_WINDOW_CLIP,
    transform: SCALE_AT_REST,
  };
  return direction === 'open'
    ? [fromOrigin, toFullWindow]
    : [toFullWindow, fromOrigin];
}

function insetFromRect(rect: DOMRect): string {
  const top = clampToViewport(rect.top, window.innerHeight);
  const left = clampToViewport(rect.left, window.innerWidth);
  const right = clampToViewport(
    window.innerWidth - rect.right,
    window.innerWidth,
  );
  const bottom = clampToViewport(
    window.innerHeight - rect.bottom,
    window.innerHeight,
  );
  return `inset(${top}px ${right}px ${bottom}px ${left}px round ${ORIGIN_RADIUS_PX}px)`;
}

function clampToViewport(value: number, limit: number): number {
  return Math.min(Math.max(value, 0), limit);
}

function reducedRevealTiming(): KeyframeAnimationOptions {
  return {
    duration: CROSSFADE_REVEAL_DURATION_MS,
    delay: CROSSFADE_REVEAL_DELAY_MS,
    easing: EASE_LINEAR,
    fill: 'both',
  };
}

function fullRevealTiming(index: number): KeyframeAnimationOptions {
  return {
    duration: REVEAL_DURATION_MS,
    delay: OPEN_DURATION_MS * REVEAL_START_RATIO + index * REVEAL_STAGGER_MS,
    easing: EASE_OUT,
    fill: 'both',
  };
}
