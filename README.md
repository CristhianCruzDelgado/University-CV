# University-CV

This repository contains an online academic CV for Cristhian Cruz Delgado, a
student at the Universidad de La Laguna. It is a static website built with
TypeScript and Vite, and it is published with GitHub Pages from the `docs/`
folder of the `main` branch. Visitors open the four academic years, browse the
subjects of each semester, and open each subject to see its projects, with
links to GitHub repositories or to files.

Each year has a first and a second semester column, and each subject is a card. 
Pressing a card opens the subject and its projects. Every view expands from the
element that was pressed, and closing it returns to that same place.

The site is for desktop browsers. Every view fits the window with no page-level
scroll.

## Stack

- TypeScript in strict mode, with vanilla DOM and no UI framework.
- Vite builds `src/` into `docs/`, which GitHub Pages serves.
- Hash routing, such as `#/year/1/semester/1/subject/example`, so deep links and
  the browser back button work on GitHub Pages.
- Transitions use the browser's Web Animations API, with `clip-path`,
  `transform` and `opacity`. No animation library is used.

## Project layout

```
content/              Content: the single source of truth
  types.ts            Interfaces for projects, subjects, semesters and years
  years.ts            Academic years, semesters and subjects
  profile.ts          Name, degree and period shown on the home screen
  lookup.ts           Finds years and subjects by identifier
src/
  main.ts             Entry point: styles and startup
  app.ts              Owns the current route and keeps the views in step
  focus.ts            Focus return and keyboard focus trap
  paths.ts            Relative paths to assets
  text.ts             Interface text
  routing/            Hash parsing (route.ts) and browser history (history.ts)
  layers/             Stack of expanded views and their open and close state
  motion/             Animation timings (constants.ts) and animations
  views/              Builders for the home, year and subject views
  styles/             One stylesheet per component
public/.nojekyll      Copied to docs/ on every build (see Troubleshooting)
assets/
  projects/           Files linked from projects, such as PDFs
docs/                 Built site, committed and served by GitHub Pages
```

## Install

Requires Node.js 22 or later.

```bash
npm install
```

## Edit the content

All content lives in `content/`. Nothing else needs to change to add a subject.

1. **Subject descriptions and projects.** Edit `content/years.ts`. Replace each
   `"[DESCRIPTION PENDING]"` with the author's text. Keep a description to two
   lines at most.
2. **Add a subject.** Add an object to the `subjects` array of the right
   semester:

   ```ts
   {
     id: 'algorithms',
     name: 'Algorithms',
     description: 'Two lines at most.',
     projects: [
       {
         title: 'Project title',
         summary: 'Short summary.',
         link: 'https://github.com/owner/repository',
       },
       { title: 'Report', summary: 'Short summary.', file: 'report.pdf' },
     ],
   },
   ```

   Give a project either a `link` or a `file`. A `file` is the name of a file
   in `assets/projects/`.

3. **Remove the example.** Delete the subject whose name starts with `EXAMPLE`.
4. **Profile.** Edit `content/profile.ts` if the name, degree or period changes.

The identifiers (`id`) of years, semesters and subjects appear in the URL. If
you change one, the deep links that point to it change too.

## Scripts

| Script              | What it does                                         |
| ------------------- | ---------------------------------------------------- |
| `npm run dev`       | Starts the development server.                       |
| `npm run build`     | Builds the site into `docs/`.                        |
| `npm run typecheck` | Checks the TypeScript types in strict mode.          |
| `npm run lint`      | Lints the TypeScript code with ESLint.               |
| `npm run format`    | Formats the files with Prettier.                     |
| `npm run check`     | Runs `typecheck`, `lint` and `build`, in that order. |

Run `npm run check` before every commit. It must finish without errors or
warnings.

## Build

```bash
npm run build
```

The build writes the site to `docs/`, copies `assets/` and `public/` into it,
and empties `docs/` first. Commit `docs/` together with `src/` and `content/`,
because GitHub Pages serves the committed files.

## Publish to GitHub Pages

1. Run `npm run check`. It must pass.
2. Commit `src/`, `content/`, `assets/`, `public/` and `docs/`, then push to
   `main`.
3. In the repository on GitHub, open **Settings → Pages**. Under **Build and
   deployment**, set:
   - **Source:** Deploy from a branch
   - **Branch:** `main`
   - **Folder:** `/docs`
4. Click **Save**. After a short wait, the site is at
   `https://<user>.github.io/University-CV/`.

## Keyboard and accessibility

- Tab moves through the controls. Focus is always visible.
- Enter or Space opens a tile or a subject card.
- Escape closes the current view and returns to its parent.
- The browser back button moves up one level. A deep link opens every parent
  view, so the back button keeps working.
- When a view opens, focus moves into it. When it closes, focus returns to the
  element that opened it.
- With `prefers-reduced-motion`, the transitions become a crossfade.
