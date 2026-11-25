import { existsSync, statSync } from 'node:fs';
import { isAbsolute, normalize, resolve, sep } from 'node:path';
import type { Plugin } from 'vite';
import type { AcademicYear, Project, ProjectResource } from '../content/types';
import { ACADEMIC_YEARS } from '../content/years.ts';

/** Parent-folder segment, which would let a path escape the repository. */
const PARENT_SEGMENT = '..';

/** What a resource path must point to. */
type ResourceKind = 'file' | 'directory';

/** A resource path together with the project that declares it. */
interface DeclaredResource {
  readonly kind: ResourceKind;
  readonly path: string;
  readonly owner: string;
}

function listProjectResources(
  project: Project,
  owner: string,
): DeclaredResource[] {
  const toDeclared =
    (kind: ResourceKind) =>
    (resource: ProjectResource): DeclaredResource => ({
      kind,
      path: resource.path,
      owner,
    });
  return [
    ...(project.files ?? []).map(toDeclared('file')),
    ...(project.directories ?? []).map(toDeclared('directory')),
  ];
}

function listYearResources(year: AcademicYear): DeclaredResource[] {
  return year.semesters.flatMap((semester) =>
    semester.subjects.flatMap((subject) =>
      subject.projects.flatMap((project) =>
        listProjectResources(project, `${subject.name} › ${project.title}`),
      ),
    ),
  );
}

function escapesRepository(path: string): boolean {
  return (
    isAbsolute(path) || normalize(path).split(sep).includes(PARENT_SEGMENT)
  );
}

function matchesKind(absolutePath: string, kind: ResourceKind): boolean {
  if (!existsSync(absolutePath)) return false;
  const stats = statSync(absolutePath);
  return kind === 'file' ? stats.isFile() : stats.isDirectory();
}

function describeProblem(
  resource: DeclaredResource,
  repositoryRoot: string,
): string | undefined {
  if (escapesRepository(resource.path)) {
    return `${resource.owner}: "${resource.path}" is outside the repository`;
  }
  if (!matchesKind(resolve(repositoryRoot, resource.path), resource.kind)) {
    return `${resource.owner}: ${resource.kind} "${resource.path}" not found`;
  }
  return undefined;
}

/**
 * Lists every project file or folder in the content that does not exist in
 * the repository, or that is a folder where a file is expected, or the
 * reverse.
 * @param repositoryRoot Absolute path of the repository root.
 * @returns One message per broken path. Empty when every path is valid.
 */
export function findBrokenResources(repositoryRoot: string): string[] {
  return ACADEMIC_YEARS.flatMap(listYearResources)
    .map((resource) => describeProblem(resource, repositoryRoot))
    .filter((problem) => problem !== undefined);
}

/**
 * Fails the build when a project points to a file or folder that is not in
 * the repository, because GitHub would show a 404 page for its link.
 * @param repositoryRoot Absolute path of the repository root.
 * @returns The Vite plugin.
 */
export function validateProjectResources(repositoryRoot: string): Plugin {
  return {
    name: 'validate-project-resources',
    buildStart(): void {
      const problems = findBrokenResources(repositoryRoot);
      if (problems.length > 0) {
        this.error(
          `Broken project resources in content/:\n  ${problems.join('\n  ')}`,
        );
      }
    },
  };
}
