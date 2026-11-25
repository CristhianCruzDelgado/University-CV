/** A file or folder of this repository that a project points to. */
export interface ProjectResource {
  /** Path relative to the repository root, for example "assets/report.pdf". */
  readonly path: string;
  /** Visible text. When missing, the file or folder name is shown. */
  readonly label?: string;
}

/** A project the author produced for a subject. */
export interface Project {
  /** Short project title. */
  readonly title: string;
  /** One or two sentences describing the project. */
  readonly summary: string;
  /** External link, for example a GitHub repository. */
  readonly link?: string;
  /** Files of this repository, opened on GitHub. */
  readonly files?: readonly ProjectResource[];
  /** Folders of this repository, opened on GitHub. */
  readonly directories?: readonly ProjectResource[];
}

/** A subject taught in one semester, with the projects built for it. */
export interface Subject {
  /** Short identifier used in the URL. Unique within its semester. */
  readonly id: string;
  /** Full subject name. */
  readonly name: string;
  /** Two lines at most. */
  readonly description: string;
  /** Projects shown on the subject view. */
  readonly projects: readonly Project[];
}

/** One semester column of an academic year. */
export interface Semester {
  /** Identifier used in the URL, "1" or "2". */
  readonly id: string;
  /** Semester name shown in the column header. */
  readonly name: string;
  /** Subjects shown as cards in the column. */
  readonly subjects: readonly Subject[];
}

/** One academic year, shown as two semester columns. */
export interface AcademicYear {
  /** Identifier used in the URL, "1" to "4". */
  readonly id: string;
  /** Year label shown on the home tile and the year view. */
  readonly label: string;
  /** The two semesters of the year, in order. */
  readonly semesters: readonly Semester[];
}

/** Identity shown in the home header. */
export interface Profile {
  /** Full name of the author. */
  readonly name: string;
  /** Name of the university, written in full. */
  readonly university: string;
  /** Official website of the university, opened from the home header. */
  readonly universityUrl: string;
  /** Degree the author is studying. */
  readonly degree: string;
  /** Years covered by the degree, for example "2023–2027". */
  readonly period: string;
}
