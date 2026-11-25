/** Namespace that SVG elements must be created in. */
const SVG_NAMESPACE = 'http://www.w3.org/2000/svg';

/** Square drawing area shared by every icon, in SVG user units. */
const ICON_VIEW_BOX = '0 0 16 16';

/** Class name of every icon, so they share size and stroke in CSS. */
const ICON_CLASS = 'icon';

/** A page with a folded top-right corner. */
const FILE_ICON_PATHS = ['M3.5 1.5h6l3 3v10h-9z', 'M9.5 1.5v3h3'];

/** A folder with a tab on its top-left edge. */
const FOLDER_ICON_PATHS = ['M1.5 3.5h4.5l1.5 1.5h7v8.5h-13z'];

/** Icons available to the views. */
export type IconName = 'file' | 'folder';

const ICON_PATHS: Readonly<Record<IconName, readonly string[]>> = {
  file: FILE_ICON_PATHS,
  folder: FOLDER_ICON_PATHS,
};

/**
 * Draws an outline icon in the current text colour. It is decorative, so
 * assistive technology skips it and reads the text next to it.
 * @param name Icon to draw.
 * @returns The SVG element.
 */
export function createIcon(name: IconName): SVGSVGElement {
  const svg = document.createElementNS(SVG_NAMESPACE, 'svg');
  svg.setAttribute('viewBox', ICON_VIEW_BOX);
  svg.setAttribute('class', `${ICON_CLASS} ${ICON_CLASS}-${name}`);
  svg.setAttribute('aria-hidden', 'true');
  svg.setAttribute('focusable', 'false');
  for (const pathData of ICON_PATHS[name]) {
    const path = document.createElementNS(SVG_NAMESPACE, 'path');
    path.setAttribute('d', pathData);
    svg.append(path);
  }
  return svg;
}
