import type { AcademicYear, Semester, Subject } from '../../content/types';
import { UI_TEXT } from '../text';
import { homeCrumb } from './breadcrumbs';
import { createElement } from './dom';
import type { LayerContent, OpenRoute, SemesterReference } from './view-types';

/**
 * Builds the content of an academic year: one column per semester.
 * @param year Year to show.
 * @param openRoute Opens a subject when its card is pressed.
 * @returns The heading, breadcrumbs and body of the year view.
 */
export function buildYearContent(
  year: AcademicYear,
  openRoute: OpenRoute,
): LayerContent {
  const columns = createElement('div', { className: 'semesters' });
  columns.append(
    ...year.semesters.map((semester) =>
      buildSemesterColumn(year.id, semester, openRoute),
    ),
  );

  const body = createElement('div', { className: 'layer-body' });
  body.append(columns);
  return {
    title: year.label,
    crumbs: [homeCrumb(), { label: year.label }],
    body,
  };
}

function buildSemesterColumn(
  yearId: string,
  semester: Semester,
  openRoute: OpenRoute,
): HTMLElement {
  const reference: SemesterReference = { yearId, semesterId: semester.id };
  const column = createElement('section', {
    className: 'semester',
    reveal: true,
  });
  const list = createElement('div', { className: 'semester-list' });

  const cards = semester.subjects.map((subject) =>
    buildSubjectCard(reference, subject, openRoute),
  );
  list.append(
    ...(cards.length > 0 ? cards : [buildPlaceholder(UI_TEXT.subjectsPending)]),
  );

  column.append(
    createElement('h3', { className: 'semester-head', text: semester.name }),
    list,
  );
  return column;
}

function buildSubjectCard(
  reference: SemesterReference,
  subject: Subject,
  openRoute: OpenRoute,
): HTMLButtonElement {
  const card = createElement('button', {
    className: 'subject-card',
    reveal: true,
  });
  card.type = 'button';
  card.append(
    createElement('span', {
      className: 'subject-card-name',
      text: subject.name,
    }),
    createElement('span', {
      className: 'subject-card-desc',
      text: subject.description,
    }),
  );
  card.addEventListener('click', () => {
    openRoute({ kind: 'subject', ...reference, subjectId: subject.id }, card);
  });
  return card;
}

function buildPlaceholder(text: string): HTMLParagraphElement {
  return createElement('p', { className: 'placeholder', text, reveal: true });
}
