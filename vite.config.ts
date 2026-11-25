import { cpSync, existsSync } from 'node:fs';
import { resolve } from 'node:path';
import { defineConfig, type Plugin } from 'vite';
import { validateProjectResources } from './tools/validate-resources.ts';

/** Build output folder. GitHub Pages serves it from the main branch. */
const OUTPUT_DIRECTORY = 'docs';

/** Folder with project files, copied into the build. */
const ASSETS_DIRECTORY = 'assets';

/** Folder whose files are copied to the site root, such as `.nojekyll`. */
const PUBLIC_DIRECTORY = 'public';

/**
 * Copies `assets/` into the build, so `./assets/...` URLs resolve on Pages.
 * A missing folder is skipped, because the assets arrive over time.
 * @returns The Vite plugin.
 */
function copyAssets(): Plugin {
  return {
    name: 'copy-assets',
    apply: 'build',
    closeBundle(): void {
      const source = resolve(import.meta.dirname, ASSETS_DIRECTORY);
      if (!existsSync(source)) return;
      cpSync(
        source,
        resolve(import.meta.dirname, OUTPUT_DIRECTORY, ASSETS_DIRECTORY),
        { recursive: true, force: true },
      );
    },
  };
}

// Vite reads its configuration through a default export, which is the one
// place this project allows it. The rule that forbids default exports is
// disabled for this file only, in eslint.config.mjs.
export default defineConfig({
  base: './',
  publicDir: PUBLIC_DIRECTORY,
  plugins: [validateProjectResources(import.meta.dirname), copyAssets()],
  build: {
    outDir: OUTPUT_DIRECTORY,
    emptyOutDir: true,
    assetsDir: ASSETS_DIRECTORY,
  },
});
