/** A project the author produced for a subject. Give either a link or a file. */
export type Project = {
  title: string;
  summary: string;
  /** External link, for example a GitHub repository. */
  link?: string;
  /** Path relative to `assets/projects/`, for example "report.pdf". */
  file?: string;
};

export type Subject = {
  id: string;
  name: string;
  /** Two lines at most. Use "[DESCRIPTION PENDING]" until the author writes it. */
  description: string;
  projects: Project[];
};

export type Semester = {
  id: string;
  name: string;
  subjects: Subject[];
};

export type AcademicYear = {
  id: string;
  label: string;
  semesters: Semester[];
};
