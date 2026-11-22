import { profile, years } from "../content";
import type { AcademicYear, Project, Semester, Subject } from "../content";
import { findSemester, findSubject, findYear, routeToHash, type Route } from "./route";

/** Opens a route, expanding from the element that was pressed. */
export type Open = (route: Route, origin: Element) => void;

export type Crumb = { label: string; href?: string };

export type LayerView = {
  title: string;
  crumbs: Crumb[];
  body: HTMLElement;
};

const PENDING_SUBJECTS = "[SUBJECTS PENDING]";
const PENDING_PROJECTS = "[PROJECTS PENDING]";

function el<K extends keyof HTMLElementTagNameMap>(
  tag: K,
  className?: string,
  text?: string,
): HTMLElementTagNameMap[K] {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
}

/** Splits "1st Year (2023–2024)" into its name and its period, so each can be styled. */
function splitYearLabel(label: string): { name: string; period: string } {
  const match = /^(.*?)\s*\((.*)\)$/.exec(label);
  if (!match) return { name: label, period: "" };
  return { name: match[1] ?? label, period: match[2] ?? "" };
}

/** Home: the author's name, then one large button per academic year. */
export function buildHome(open: Open): HTMLElement {
  const home = el("main", "home");
  home.id = "home";

  const header = el("header", "home__header");
  header.append(
    el("p", "home__university", profile.university),
    el("h1", "home__name", profile.name),
    el("p", "home__meta", `${profile.degree} · ${profile.period}`),
  );

  const nav = el("nav", "home__years");
  nav.setAttribute("aria-label", "Academic years");

  for (const year of years) {
    const { name, period } = splitYearLabel(year.label);
    const tile = el("button", "tile");
    tile.type = "button";
    tile.dataset["year"] = year.id;
    tile.append(el("span", "tile__name", name), el("span", "tile__period", period));
    tile.addEventListener("click", () => open({ kind: "year", year: year.id }, tile));
    nav.append(tile);
  }

  home.append(header, nav);
  return home;
}

/** A year: two full-height semester columns, each listing its subject cards. */
export function buildYearView(year: AcademicYear, open: Open): LayerView {
  const body = el("div", "layer__body");
  const columns = el("div", "semesters");

  for (const semester of year.semesters) {
    columns.append(buildSemesterColumn(year, semester, open));
  }

  body.append(columns);
  return {
    title: year.label,
    crumbs: [{ label: "Home", href: routeToHash({ kind: "home" }) }, { label: year.label }],
    body,
  };
}

function buildSemesterColumn(year: AcademicYear, semester: Semester, open: Open): HTMLElement {
  const column = el("section", "semester");
  column.dataset["reveal"] = "";
  const head = el("h3", "semester__head", semester.name);
  const list = el("div", "semester__list");

  if (semester.subjects.length === 0) {
    const placeholder = el("p", "placeholder", PENDING_SUBJECTS);
    placeholder.dataset["reveal"] = "";
    list.append(placeholder);
  }

  for (const subject of semester.subjects) {
    const card = el("button", "subject-card");
    card.type = "button";
    card.dataset["reveal"] = "";
    card.append(
      el("span", "subject-card__name", subject.name),
      el("span", "subject-card__desc", subject.description),
    );
    card.addEventListener("click", () =>
      open(
        { kind: "subject", year: year.id, semester: semester.id, subject: subject.id },
        card,
      ),
    );
    list.append(card);
  }

  column.append(head, list);
  return column;
}

/** A subject: its full name and description, then its projects. */
export function buildSubjectView(
  route: { year: string; semester: string; subject: string },
): LayerView | null {
  const year = findYear(route.year);
  const semester = findSemester(route);
  const subject = findSubject(route);
  if (!year || !semester || !subject) return null;

  const body = el("div", "layer__body");
  body.append(buildSubjectBody(subject));

  return {
    title: subject.name,
    crumbs: [
      { label: "Home", href: routeToHash({ kind: "home" }) },
      { label: year.label, href: routeToHash({ kind: "year", year: year.id }) },
      { label: semester.name },
      { label: subject.name },
    ],
    body,
  };
}

function buildSubjectBody(subject: Subject): HTMLElement {
  const wrap = el("div", "subject");
  const description = el("p", "subject__desc", subject.description);
  description.dataset["reveal"] = "";
  wrap.append(description);

  const section = el("section", "projects");
  const heading = el("h3", "projects__title", "Projects");
  heading.dataset["reveal"] = "";
  section.append(heading);

  if (subject.projects.length === 0) {
    const placeholder = el("p", "placeholder", PENDING_PROJECTS);
    placeholder.dataset["reveal"] = "";
    section.append(placeholder);
  } else {
    const list = el("ul", "projects__list");
    for (const project of subject.projects) {
      list.append(buildProject(project));
    }
    section.append(list);
  }

  wrap.append(section);
  return wrap;
}

function buildProject(project: Project): HTMLElement {
  const item = el("li", "project");
  item.dataset["reveal"] = "";
  item.append(el("h4", "project__title", project.title), el("p", "project__summary", project.summary));

  if (project.link) {
    const link = el("a", "project__link", "Open link");
    link.href = project.link;
    link.target = "_blank";
    link.rel = "noopener noreferrer";
    item.append(link);
  } else if (project.file) {
    const link = el("a", "project__link", "Open file");
    link.href = `./assets/projects/${encodeURIComponent(project.file)}`;
    link.target = "_blank";
    link.rel = "noopener";
    item.append(link);
  }
  return item;
}

/** Breadcrumb trail: Home › 1st Year › First Semester › Subject name. Ancestors are links, the current item is not. */
export function buildCrumbs(crumbs: Crumb[]): HTMLElement {
  const nav = el("nav", "crumbs");
  nav.setAttribute("aria-label", "Breadcrumb");
  const list = el("ol", "crumbs__list");

  crumbs.forEach((crumb, index) => {
    const item = el("li", "crumbs__item");
    const isLast = index === crumbs.length - 1;
    if (crumb.href && !isLast) {
      const link = el("a", "crumbs__link", crumb.label);
      link.href = crumb.href;
      item.append(link);
    } else {
      const current = el("span", "crumbs__current", crumb.label);
      if (isLast) current.setAttribute("aria-current", "page");
      item.append(current);
    }
    list.append(item);
    if (!isLast) {
      const separator = el("li", "crumbs__sep", "›");
      separator.setAttribute("aria-hidden", "true");
      list.append(separator);
    }
  });

  nav.append(list);
  return nav;
}
