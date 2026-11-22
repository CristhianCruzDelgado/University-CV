import { cp, stat, writeFile } from "node:fs/promises";
import { resolve } from "node:path";
import { defineConfig, type Plugin } from "vite";

const ROOT = resolve(import.meta.dirname);
const OUT_DIR = "docs";

/**
 * Copies `assets/` (brand marks, fonts, project files) into the built site so
 * that the runtime paths `./assets/...` resolve on GitHub Pages. Missing
 * folders are skipped, so the build never fails because an asset is absent.
 * Also writes `.nojekyll` so GitHub Pages serves every file as is.
 */
function copyAssets(): Plugin {
  return {
    name: "copy-assets-and-nojekyll",
    apply: "build",
    async closeBundle() {
      const source = resolve(ROOT, "assets");
      const target = resolve(ROOT, OUT_DIR, "assets");
      try {
        await stat(source);
        await cp(source, target, { recursive: true, force: true });
      } catch {
        // No assets folder yet: nothing to copy.
      }
      await writeFile(resolve(ROOT, OUT_DIR, ".nojekyll"), "");
    },
  };
}

export default defineConfig({
  base: "./",
  publicDir: false,
  plugins: [copyAssets()],
  build: {
    outDir: OUT_DIR,
    emptyOutDir: true,
    assetsDir: "assets",
    sourcemap: false,
  },
});
