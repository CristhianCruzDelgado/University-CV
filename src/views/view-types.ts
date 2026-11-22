import type { Route } from '../routing/route';

/** Opens a route, expanding from the element that was pressed. */
export type OpenRoute = (route: Route, origin: Element) => void;

/** One link, or plain text, in the breadcrumb trail. */
export interface Crumb {
  /** Text shown for the crumb. */
  readonly label: string;
  /** Hash to follow. Omit it for a level that has no route. */
  readonly href?: string;
}

/** The content of an expanded view, without its frame. */
export interface LayerContent {
  /** Heading shown at the top of the layer. */
  readonly title: string;
  /** Breadcrumb trail from the home screen to this view. */
  readonly crumbs: readonly Crumb[];
  /** Scrollable body of the view. */
  readonly body: HTMLElement;
}

/** Identifies a semester by the year that contains it. */
export interface SemesterReference {
  /** Identifier of the academic year. */
  readonly yearId: string;
  /** Identifier of the semester inside that year. */
  readonly semesterId: string;
}
