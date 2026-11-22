import type { SubjectLocation } from '../../content/lookup';
import type { Project, Subject } from '../../content/types';
import { PROJECT_FILES_PATH } from '../paths';
import { UI_TEXT } from '../text';
import { homeCrumb, yearCrumb } from './breadcrumbs';
import { createElement, createExternalLink } from './dom';
import type { LayerContent } from './view-types';

/** Class name of the link under each project. */
const PROJECT_LINK_CLASS = 'project-link';

/**
 * Builds the content of a subject: its description and its projects.
 * @param location Subject with the year and semester that contain it.
 * @returns The heading, breadcrumbs and body of the subject view.
 */
export function buildSubjectContent(location: SubjectLocation): LayerContent {
  const { year, semester, subject } = location;
  const body = createElement('div', { className: 'layer-body' });
  body.append(buildSubjectBody(subject));
  return {
    title: subject.name,
    crumbs: [
      homeCrumb(),
      yearCrumb(year),
      { label: semester.name },
      { label: subject.name },
    ],
    body,
  };
}

function buildSubjectBody(subject: Subject): HTMLElement {
  const wrapper = createElement('div', { className: 'subject' });
  wrapper.append(
    createElement('p', {
      className: 'subject-desc',
      text: subject.description,
      reveal: true,
    }),
    buildProjectsSection(subject.projects),
  );
  return wrapper;
}

function buildProjectsSection(projects: readonly Project[]): HTMLElement {
  const section = createElement('section', { className: 'projects' });
  section.append(
    createElement('h3', {
      className: 'projects-title',
      text: UI_TEXT.projects,
      reveal: true,
    }),
  );

  if (projects.length === 0) {
    section.append(
      createElement('p', {
        className: 'placeholder',
        text: UI_TEXT.projectsPending,
        reveal: true,
      }),
    );
    return section;
  }

  const list = createElement('ul', { className: 'projects-list' });
  list.append(...projects.map(buildProjectItem));
  section.append(list);
  return section;
}

function buildProjectItem(project: Project): HTMLLIElement {
  const item = createElement('li', { className: 'project', reveal: true });
  item.append(
    createElement('h4', { className: 'project-title', text: project.title }),
    createElement('p', { className: 'project-summary', text: project.summary }),
  );
  const link = buildProjectLink(project);
  if (link !== undefined) item.append(link);
  return item;
}

/**
 * Builds the link to a project's repository or file. A project with neither
 * shows no link.
 * @param project Project whose link is wanted.
 * @returns The anchor, or undefined when the project has no link or file.
 */
function buildProjectLink(project: Project): HTMLAnchorElement | undefined {
  if (project.link !== undefined) {
    return createExternalLink(
      UI_TEXT.openLink,
      project.link,
      PROJECT_LINK_CLASS,
    );
  }
  if (project.file !== undefined) {
    const href = `${PROJECT_FILES_PATH}${encodeURIComponent(project.file)}`;
    return createExternalLink(UI_TEXT.openFile, href, PROJECT_LINK_CLASS);
  }
  return undefined;
}
