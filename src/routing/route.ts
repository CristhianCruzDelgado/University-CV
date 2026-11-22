import { findYear, locateSubject } from '../../content/lookup';

/** The home screen, with one button per academic year. */
interface HomeRoute {
  readonly kind: 'home';
}

/** An academic year, shown as its two semester columns. */
interface YearRoute {
  readonly kind: 'year';
  readonly yearId: string;
}

/** A subject, shown with its projects. */
interface SubjectRoute {
  readonly kind: 'subject';
  readonly yearId: string;
  readonly semesterId: string;
  readonly subjectId: string;
}

/** A route that opens as an expanded layer over the home screen. */
export type LayeredRoute = YearRoute | SubjectRoute;

/** Any screen the site can show. */
export type Route = HomeRoute | LayeredRoute;

/** Screen shown for unknown hashes and for identifiers that match no content. */
export const HOME_ROUTE: HomeRoute = { kind: 'home' };

const YEAR_PATTERN = /^#\/year\/([^/]+)$/u;
const SUBJECT_PATTERN =
  /^#\/year\/([^/]+)\/semester\/([^/]+)\/subject\/([^/]+)$/u;
const TRAILING_SLASHES_PATTERN = /\/+$/u;

/**
 * Converts a location hash into a route that exists in the content.
 * @param hash Location hash, for example "#/year/1".
 * @returns The matching route, or the home route when nothing matches.
 */
export function parseHash(hash: string): Route {
  const normalised = hash.replace(TRAILING_SLASHES_PATTERN, '');
  const route =
    parseSubjectHash(normalised) ?? parseYearHash(normalised) ?? HOME_ROUTE;
  return resolveRoute(route);
}

/**
 * Returns the route when its content exists, otherwise the home route.
 * @param route Route to check against the content.
 * @returns The same route, or the home route when its content is missing.
 */
function resolveRoute(route: Route): Route {
  return isAvailable(route) ? route : HOME_ROUTE;
}

/**
 * Builds the hash that addresses a route.
 * @param route Route to address.
 * @returns The location hash, for example "#/year/1/semester/1/subject/x".
 */
export function routeToHash(route: Route): string {
  switch (route.kind) {
    case 'home':
      return '#/';
    case 'year':
      return `#/year/${route.yearId}`;
    case 'subject':
      return `#/year/${route.yearId}/semester/${route.semesterId}/subject/${route.subjectId}`;
  }
}

/**
 * Returns the level directly above a route.
 * @param route Route whose parent is wanted.
 * @returns The parent route, or undefined for the home route.
 */
export function parentRoute(route: Route): Route | undefined {
  switch (route.kind) {
    case 'home':
      return undefined;
    case 'year':
      return HOME_ROUTE;
    case 'subject':
      return { kind: 'year', yearId: route.yearId };
  }
}

/**
 * Lists every level above a route, from the top down.
 * @param route Route whose ancestors are wanted.
 * @returns The ancestors, excluding the route itself.
 */
export function ancestorRoutes(route: Route): Route[] {
  const ancestors: Route[] = [];
  let parent = parentRoute(route);
  while (parent !== undefined) {
    ancestors.unshift(parent);
    parent = parentRoute(parent);
  }
  return ancestors;
}

/**
 * Lists the layers that must be open to show a route.
 * @param route Route to show.
 * @returns Every layered route from the top down, ending with the route itself.
 */
export function visibleLevels(route: Route): LayeredRoute[] {
  return [...ancestorRoutes(route), route].filter(isLayeredRoute);
}

function isLayeredRoute(route: Route): route is LayeredRoute {
  return route.kind !== 'home';
}

function parseYearHash(hash: string): YearRoute | undefined {
  const match = YEAR_PATTERN.exec(hash);
  if (match === null) return undefined;
  const [, yearId = ''] = match;
  return { kind: 'year', yearId };
}

function parseSubjectHash(hash: string): SubjectRoute | undefined {
  const match = SUBJECT_PATTERN.exec(hash);
  if (match === null) return undefined;
  const [, yearId = '', semesterId = '', subjectId = ''] = match;
  return { kind: 'subject', yearId, semesterId, subjectId };
}

function isAvailable(route: Route): boolean {
  switch (route.kind) {
    case 'home':
      return true;
    case 'year':
      return findYear(route.yearId) !== undefined;
    case 'subject':
      return (
        locateSubject(route.yearId, route.semesterId, route.subjectId) !==
        undefined
      );
  }
}
