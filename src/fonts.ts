/**
 * Argentum Sans, the official typeface, loaded from `assets/fonts/`.
 * The file names are a convention: add the WOFF2 files under these names.
 * If a file is missing, the request fails quietly and the CSS fallback stack applies.
 */
const FACES: ReadonlyArray<{ weight: string; file: string }> = [
  { weight: "400", file: "ArgentumSans-Regular.woff2" },
  { weight: "700", file: "ArgentumSans-Bold.woff2" },
];

export function loadFonts(): void {
  if (typeof FontFace === "undefined") return;

  for (const face of FACES) {
    try {
      const font = new FontFace("Argentum Sans", `url("./assets/fonts/${face.file}") format("woff2")`, {
        weight: face.weight,
        display: "swap",
      });
      font
        .load()
        .then((loaded) => document.fonts.add(loaded))
        .catch(() => undefined);
    } catch {
      // Constructing the face can fail on unusual browsers; the fallback stack still applies.
    }
  }
}
