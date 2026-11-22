import type { AcademicYear, Semester, Subject } from './types';

/**
 * Placeholder shown until the author writes a description. Replace it in
 * the content, never invent text in its place.
 */
const PENDING_DESCRIPTION = '[DESCRIPTION PENDING]';

/** Example subject that shows the layout. The author replaces it. */
const EXAMPLE_SUBJECT: Subject = {
  id: 'example',
  name: 'EXAMPLE · Subject name',
  description: PENDING_DESCRIPTION,
  projects: [
    {
      title: 'EXAMPLE · Project title',
      summary: PENDING_DESCRIPTION,
    },
  ],
};

/** Semesters for years whose subjects have not been supplied yet. */
const SEMESTERS_WITHOUT_SUBJECTS: readonly Semester[] = [
  { id: '1', name: 'First Semester', subjects: [] },
  { id: '2', name: 'Second Semester', subjects: [] },
];

/**
 * Single source of truth for the academic path. Ids appear in the URL, so
 * changing one changes the deep links that point to it.
 */
export const ACADEMIC_YEARS: readonly AcademicYear[] = [
  {
    id: '1',
    label: '1st Year (2023–2024)',
    semesters: [
      { id: '1', name: 'First Semester', subjects: [EXAMPLE_SUBJECT] },
      { id: '2', name: 'Second Semester', subjects: [] },
    ],
  },
  {
    id: '2',
    label: '2nd Year (2024–2025)',
    semesters: SEMESTERS_WITHOUT_SUBJECTS,
  },
  {
    id: '3',
    label: '3rd Year (2025–2026)',
    semesters: SEMESTERS_WITHOUT_SUBJECTS,
  },
  {
    id: '4',
    label: '4th Year (2026–2027)',
    semesters: SEMESTERS_WITHOUT_SUBJECTS,
  },
];
