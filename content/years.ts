import type { AcademicYear } from "./types";

/**
 * Single source of truth for the academic path.
 * Ids appear in the URL (`#/year/1/semester/1/subject/example`), so keep them short and stable.
 * Subjects were not supplied yet: only the EXAMPLE subject exists, and the rest of the lists are empty.
 */
export const years: AcademicYear[] = [
  {
    id: "1",
    label: "1st Year (2023–2024)",
    semesters: [
      {
        id: "1",
        name: "First Semester",
        subjects: [
          {
            id: "example",
            name: "EXAMPLE · Subject name",
            description: "[DESCRIPTION PENDING]",
            projects: [
              {
                title: "EXAMPLE · Project title",
                summary: "[DESCRIPTION PENDING]",
              },
            ],
          },
        ],
      },
      {
        id: "2",
        name: "Second Semester",
        subjects: [],
      },
    ],
  },
  {
    id: "2",
    label: "2nd Year (2024–2025)",
    semesters: [
      { id: "1", name: "First Semester", subjects: [] },
      { id: "2", name: "Second Semester", subjects: [] },
    ],
  },
  {
    id: "3",
    label: "3rd Year (2025–2026)",
    semesters: [
      { id: "1", name: "First Semester", subjects: [] },
      { id: "2", name: "Second Semester", subjects: [] },
    ],
  },
  {
    id: "4",
    label: "4th Year (2026–2027)",
    semesters: [
      { id: "1", name: "First Semester", subjects: [] },
      { id: "2", name: "Second Semester", subjects: [] },
    ],
  },
];
