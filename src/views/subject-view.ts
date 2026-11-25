import type { SubjectLocation } from '../../content/lookup';
import type { Project, ProjectResource, Subject } from '../../content/types';
import { buildDirectoryUrl, buildFileUrl, getPathName } from '../paths';
import { UI_TEXT } from '../text';
import { homeCrumb, yearCrumb } from './breadcrumbs';
import { createElement, createExternalLink } from './dom';
import { createIcon, type IconName } from './icons';
import type { LayerContent } from './view-types';

/** Class name of the external link under each project. */
const PROJECT_LINK_CLASS = 'project-link';

/** Class name of every file or folder link. */
const RESOURCE_CLASS = 'resource';

/** Class name of the text that names the kind of resource to screen readers. */
const VISUALLY_HIDDEN_CLASS = 'visually-hidden';

/** How each kind of resource is drawn, named and linked. */
interface ResourceKind {
  readonly icon: IconName;
  readonly spokenPrefix: string;
  readonly buildUrl: (path: string) => string;
}

const FILE_KIND: ResourceKind = {
  icon: 'file',
  spokenPrefix: UI_TEXT.fileResource,
  buildUrl: buildFileUrl,
};

const DIRECTORY_KIND: ResourceKind = {
  icon: 'folder',
  spokenPrefix: UI_TEXT.directoryResource,
  buildUrl: buildDirectoryUrl,
};

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
  if (project.link !== undefined) {
    item.append(
      createExternalLink(UI_TEXT.openLink, project.link, PROJECT_LINK_CLASS),
    );
  }
  const resources = buildResourceList(project);
  if (resources !== undefined) item.append(resources);
  return item;
}

/**
 * Lists the files and then the folders of a project. A project with neither
 * shows no list.
 * @param project Project whose resources are wanted.
 * @returns The list, or undefined when the project has no resources.
 */
function buildResourceList(project: Project): HTMLUListElement | undefined {
  const links = [
    ...(project.files ?? []).map((file) => buildResourceItem(file, FILE_KIND)),
    ...(project.directories ?? []).map((directory) =>
      buildResourceItem(directory, DIRECTORY_KIND),
    ),
  ];
  if (links.length === 0) return undefined;
  const list = createElement('ul', { className: 'resources' });
  list.append(...links);
  return list;
}

function buildResourceItem(
  resource: ProjectResource,
  kind: ResourceKind,
): HTMLLIElement {
  const label = resource.label ?? getPathName(resource.path);
  const anchor = createExternalLink(
    '',
    kind.buildUrl(resource.path),
    `${RESOURCE_CLASS} ${RESOURCE_CLASS}-${kind.icon}`,
  );
  anchor.title = resource.path;
  anchor.append(
    createIcon(kind.icon),
    createElement('span', {
      className: VISUALLY_HIDDEN_CLASS,
      text: kind.spokenPrefix,
    }),
    createElement('span', { className: 'resource-label', text: label }),
  );
  const item = createElement('li', { className: 'resources-item' });
  item.append(anchor);
  return item;
}
