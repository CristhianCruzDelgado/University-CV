import { FONT_FILES_PATH } from './paths';

/** Family name used in the stylesheet. */
const ARGENTUM_FAMILY = 'Argentum Sans';

/** One weight of the typeface and the file that holds it. */
interface FontFaceSource {
  /** CSS font weight of the file. */
  readonly weight: string;
  /** File name inside `assets/fonts/`. */
  readonly fileName: string;
}

const ARGENTUM_FACES: readonly FontFaceSource[] = [
  { weight: '400', fileName: 'ArgentumSans-Regular.woff2' },
  { weight: '700', fileName: 'ArgentumSans-Bold.woff2' },
];

/**
 * Loads Argentum Sans from `assets/fonts/`. A missing file is reported in the
 * console, and the stylesheet's fallback font stays in use.
 */
export function loadArgentumSans(): void {
  if (typeof FontFace === 'undefined') {
    console.warn('FontFace is unsupported; the fallback font is used.');
    return;
  }
  ARGENTUM_FACES.forEach((face) => {
    void loadFace(face);
  });
}

async function loadFace(face: FontFaceSource): Promise<void> {
  const source = `url("${FONT_FILES_PATH}${face.fileName}") format("woff2")`;
  try {
    const font = new FontFace(ARGENTUM_FAMILY, source, {
      weight: face.weight,
      display: 'swap',
    });
    document.fonts.add(await font.load());
  } catch (error: unknown) {
    console.warn(`Could not load ${face.fileName}; using the fallback.`, error);
  }
}
