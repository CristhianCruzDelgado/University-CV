import { PROFILE } from '../../content/profile';
import type { AcademicYear } from '../../content/types';
import { ACADEMIC_YEARS } from '../../content/years';
import { UI_TEXT } from '../text';
import { createElement, createExternalLink } from './dom';
import type { OpenRoute } from './view-types';

/** Splits a label such as "1st Year (2023–2024)" into name and period. */
const YEAR_LABEL_PATTERN = /^(.*?)\s*\((.*)\)$/u;

/**
 * Builds the home screen: the author's name, then one button per year.
 * @param openRoute Opens a year when its button is pressed.
 * @returns The home element.
 */
export function buildHomeView(openRoute: OpenRoute): HTMLElement {
  const home = createElement('main', { className: 'home' });
  home.append(buildHomeHeader(), buildYearNav(openRoute));
  return home;
}

function buildHomeHeader(): HTMLElement {
  const header = createElement('header', { className: 'home-header' });
  const meta = `${PROFILE.degree}${UI_TEXT.metaSeparator}${PROFILE.period}`;
  header.append(
    createExternalLink(
      PROFILE.university,
      PROFILE.universityUrl,
      'home-university',
    ),
    createElement('h1', { className: 'home-name', text: PROFILE.name }),
    createElement('p', { className: 'home-meta', text: meta }),
  );
  return header;
}

function buildYearNav(openRoute: OpenRoute): HTMLElement {
  const nav = createElement('nav', { className: 'home-years' });
  nav.setAttribute('aria-label', UI_TEXT.academicYears);
  nav.append(...ACADEMIC_YEARS.map((year) => buildYearTile(year, openRoute)));
  return nav;
}

function buildYearTile(
  year: AcademicYear,
  openRoute: OpenRoute,
): HTMLButtonElement {
  const tile = createElement('button', { className: 'tile' });
  tile.type = 'button';
  tile.dataset.year = year.id;

  const { name, period } = splitYearLabel(year.label);
  tile.append(
    createElement('span', { className: 'tile-name', text: name }),
    createElement('span', { className: 'tile-period', text: period }),
  );
  tile.addEventListener('click', () => {
    openRoute({ kind: 'year', yearId: year.id }, tile);
  });
  return tile;
}

function splitYearLabel(label: string): { name: string; period: string } {
  const match = YEAR_LABEL_PATTERN.exec(label);
  return {
    name: match?.[1] ?? label,
    period: match?.[2] ?? '',
  };
}
