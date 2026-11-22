/**
 * Attribute that marks content to fade in after its container has settled.
 * Views set it, and the reveal animation reads it.
 */
export const REVEAL_ATTRIBUTE = 'data-reveal';

/** Exponential ease-out: leave the origin quickly, then settle softly. */
export const EASE_OUT = 'cubic-bezier(0.16, 1, 0.3, 1)';

/** Symmetric curve for the collapse, so the return reads as deliberate. */
export const EASE_IN_OUT = 'cubic-bezier(0.76, 0, 0.24, 1)';

/** Constant-speed easing for crossfades. */
export const EASE_LINEAR = 'linear';

/** Time for a layer to grow out of its origin. */
export const OPEN_DURATION_MS = 720;

/** Time for a layer to shrink back into its origin. */
export const CLOSE_DURATION_MS = 520;

/** Time for a layer to appear when no origin is available. */
export const FALLBACK_OPEN_DURATION_MS = 480;

/** Time for a layer to disappear when no origin is available. */
export const FALLBACK_CLOSE_DURATION_MS = 320;

/** Time for content to fade out before its container collapses. */
export const CONTENT_FADE_DURATION_MS = 180;

/** Duration of each staggered reveal. */
export const REVEAL_DURATION_MS = 560;

/** Delay between the reveals of consecutive items. */
export const REVEAL_STAGGER_MS = 55;

/** Share of the open duration after which the reveal starts. */
export const REVEAL_START_RATIO = 0.72;

/** Distance that revealed content rises from. */
export const REVEAL_OFFSET_PX = 14;

/** Duration of the crossfade used under reduced motion when a layer opens or closes. */
export const CROSSFADE_OPEN_DURATION_MS = 240;

/** Duration of the crossfade used under reduced motion when a layer closes. */
export const CROSSFADE_CLOSE_DURATION_MS = 200;

/** Duration of each content crossfade under reduced motion. */
export const CROSSFADE_REVEAL_DURATION_MS = 220;

/** Delay before content crossfades in under reduced motion. */
export const CROSSFADE_REVEAL_DELAY_MS = 80;

/** Corner radius of the origin rectangle the layer grows from. */
export const ORIGIN_RADIUS_PX = 14;

/** Scale of a layer at the start of an expansion from its origin. */
export const ORIGIN_SCALE = 0.985;

/** Scale of a layer when it appears or disappears without an origin. */
export const FALLBACK_SCALE = 0.97;
