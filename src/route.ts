import { years } from "../content";
import type { AcademicYear, Semester, Subject } from "../content";

export type Route =
  | { kind: "home" }
  | { kind: "year"; year: string }
  | { kind: "subject"; year: string; semester: string; subject: string };

const YEAR_RE = /^#\/year\/([^/]+)$/;
const SUBJECT_RE = /^#\/year\/([^/]+)\/semester\/([^/]+)\/subject\/([^/]+)$/;

/** Parses a location hash. Anything unknown or not found in the content falls back to home. */
export function parseHash(hash: string): Route {
  const clean = hash.replace(/\/+$/, "") || "#";
  const subjectMatch = SUBJECT_RE.exec(clean);
  if (subjectMatch) {
    const [, year = "", semester = "", subject = ""] = subjectMatch;
    const route: Route = { kind: "subject", year, semester, subject };
    return isValid(route) ? route : HOME;
  }
  const yearMatch = YEAR_RE.exec(clean);
  if (yearMatch) {
    const route: Route = { kind: "year", year: yearMatch[1] ?? "" };
    return isValid(route) ? route : HOME;
  }
  return HOME;
}

export const HOME: Route = { kind: "home" };

export function routeToHash(route: Route): string {
  switch (route.kind) {
    case "home":
      return "#/";
    case "year":
      return `#/year/${route.year}`;
    case "subject":
      return `#/year/${route.year}/semester/${route.semester}/subject/${route.subject}`;
  }
}

/** The route one level up, or null for home. */
export function parentOf(route: Route): Route | null {
  switch (route.kind) {
    case "home":
      return null;
    case "year":
      return HOME;
    case "subject":
      return { kind: "year", year: route.year };
  }
}

/** Every ancestor from the top down, excluding the route itself. */
export function ancestorsOf(route: Route): Route[] {
  const chain: Route[] = [];
  let current = parentOf(route);
  while (current) {
    chain.unshift(current);
    current = parentOf(current);
  }
  return chain;
}

/** Stable identifier used to decide which layers stay open between renders. */
export function routeKey(route: Route): string {
  return routeToHash(route);
}

export function findYear(id: string): AcademicYear | undefined {
  return years.find((year) => year.id === id);
}

export function findSemester(route: { year: string; semester: string }): Semester | undefined {
  return findYear(route.year)?.semesters.find((semester) => semester.id === route.semester);
}

export function findSubject(route: { year: string; semester: string; subject: string }): Subject | undefined {
  return findSemester(route)?.subjects.find((subject) => subject.id === route.subject);
}

function isValid(route: Route): boolean {
  switch (route.kind) {
    case "home":
      return true;
    case "year":
      return findYear(route.year) !== undefined;
    case "subject":
      return findSubject(route) !== undefined;
  }
}
