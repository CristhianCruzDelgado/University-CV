import { ACADEMIC_YEARS } from './years';
import type { AcademicYear, Semester, Subject } from './types';

/** A subject together with the year and semester that contain it. */
export interface SubjectLocation {
  /** The academic year that holds the semester. */
  readonly year: AcademicYear;
  /** The semester that holds the subject. */
  readonly semester: Semester;
  /** The subject itself. */
  readonly subject: Subject;
}

/**
 * Finds an academic year by its identifier.
 * @param yearId Identifier used in the URL, for example "1".
 * @returns The matching year, or undefined when none has that identifier.
 */
export function findYear(yearId: string): AcademicYear | undefined {
  return ACADEMIC_YEARS.find((year) => year.id === yearId);
}

/**
 * Finds a subject and the year and semester around it.
 * @param yearId Identifier of the academic year.
 * @param semesterId Identifier of the semester inside that year.
 * @param subjectId Identifier of the subject inside that semester.
 * @returns The subject and its location, or undefined when any part is missing.
 */
export function locateSubject(
  yearId: string,
  semesterId: string,
  subjectId: string,
): SubjectLocation | undefined {
  const year = findYear(yearId);
  const semester = year?.semesters.find(
    (candidate) => candidate.id === semesterId,
  );
  const subject = semester?.subjects.find(
    (candidate) => candidate.id === subjectId,
  );
  if (year === undefined || semester === undefined || subject === undefined) {
    return undefined;
  }
  return { year, semester, subject };
}
