import type { AcademicYear } from '../../content/types';
import { HOME_ROUTE, routeToHash } from '../routing/route';
import { UI_TEXT } from '../text';
import { createElement } from './dom';
import type { Crumb } from './view-types';

/**
 * Crumb that links back to the home screen.
 * @returns The home crumb.
 */
export function homeCrumb(): Crumb {
  return { label: UI_TEXT.home, href: routeToHash(HOME_ROUTE) };
}

/**
 * Crumb that links to an academic year.
 * @param year Year the crumb points to.
 * @returns The year crumb.
 */
export function yearCrumb(year: AcademicYear): Crumb {
  return {
    label: year.label,
    href: routeToHash({ kind: 'year', yearId: year.id }),
  };
}

/**
 * Builds the breadcrumb trail, for example Home › 1st Year › Subject name.
 * Crumbs with a link are anchors. The last crumb marks the current page.
 * @param crumbs Crumbs from the home screen down to the current view.
 * @returns A navigation element that holds the trail.
 */
export function buildBreadcrumbs(crumbs: readonly Crumb[]): HTMLElement {
  const nav = createElement('nav', { className: 'crumbs' });
  nav.setAttribute('aria-label', UI_TEXT.breadcrumb);

  const list = createElement('ol', { className: 'crumbs-list' });
  crumbs.forEach((crumb, index) => {
    if (index > 0) list.append(buildSeparator());
    const item = buildCrumbItem(crumb);
    if (index === crumbs.length - 1) item.setAttribute('aria-current', 'page');
    list.append(item);
  });

  nav.append(list);
  return nav;
}

function buildCrumbItem(crumb: Crumb): HTMLLIElement {
  const item = createElement('li', { className: 'crumbs-item' });
  if (crumb.href === undefined) {
    item.append(
      createElement('span', { className: 'crumbs-text', text: crumb.label }),
    );
  } else {
    const link = createElement('a', {
      className: 'crumbs-link',
      text: crumb.label,
    });
    link.href = crumb.href;
    item.append(link);
  }
  return item;
}

function buildSeparator(): HTMLLIElement {
  const separator = createElement('li', {
    className: 'crumbs-separator',
    text: UI_TEXT.crumbSeparator,
  });
  separator.setAttribute('aria-hidden', 'true');
  return separator;
}
