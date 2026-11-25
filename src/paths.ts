/**
 * Address of this repository on GitHub. Project files and folders link into
 * it, so renaming the repository only needs a change here.
 */
export const REPOSITORY_URL =
  'https://github.com/CristhianCruzDelgado/University-CV';

/** Branch whose files the project links open. */
const REPOSITORY_BRANCH = 'main';

/** GitHub view that shows a single file. */
const FILE_VIEW = 'blob';

/** GitHub view that lists the contents of a folder. */
const DIRECTORY_VIEW = 'tree';

const PATH_SEPARATOR = '/';

/**
 * Encodes each segment of a repository path, so names with spaces or accents
 * still produce valid URLs while the separators stay readable.
 */
function encodeRepositoryPath(path: string): string {
  return path
    .split(PATH_SEPARATOR)
    .filter((segment) => segment.length > 0)
    .map(encodeURIComponent)
    .join(PATH_SEPARATOR);
}

function buildRepositoryUrl(view: string, path: string): string {
  const encodedPath = encodeRepositoryPath(path);
  return `${REPOSITORY_URL}/${view}/${REPOSITORY_BRANCH}/${encodedPath}`;
}

/**
 * Builds the GitHub URL that shows a file of this repository.
 * @param path File path relative to the repository root.
 * @returns The URL of the file on GitHub.
 */
export function buildFileUrl(path: string): string {
  return buildRepositoryUrl(FILE_VIEW, path);
}

/**
 * Builds the GitHub URL that lists a folder of this repository.
 * @param path Folder path relative to the repository root.
 * @returns The URL of the folder on GitHub.
 */
export function buildDirectoryUrl(path: string): string {
  return buildRepositoryUrl(DIRECTORY_VIEW, path);
}

/**
 * Returns the last segment of a repository path: the file or folder name.
 * @param path Path relative to the repository root.
 * @returns The name shown when a resource has no label.
 */
export function getPathName(path: string): string {
  const segments = path.split(PATH_SEPARATOR).filter((part) => part !== '');
  return segments.at(-1) ?? path;
}
