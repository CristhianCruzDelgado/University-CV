# University-CV

Online academic CV of Cristhian Cruz Delgado, student at the Universidad de La Laguna, 2023–2027.

The site maps the academic path as four years, each with a first and second semester column. Every subject is a card. Pressing a card opens the subject, with its projects. Each view expands from the element that was pressed, and closing it returns to the same place.

Desktop browsers only. Every view fits the window with no page-level scroll.

## Stack

- TypeScript in strict mode, with vanilla DOM and no UI framework.
- Vite builds `src/` into `docs/`, which GitHub Pages serves.
- Hash routing (`#/year/1/semester/1/subject/example`), so deep links and the browser back button work on GitHub Pages.
- Transitions use the Web Animations API with `clip-path`, `transform` and `opacity`. There are no animation libraries.

## Project layout

```
content/         All text and data (the single source of truth)
  types.ts       Types: Project, Subject, Semester, AcademicYear
  years.ts       The four academic years, their semesters and subjects
  profile.ts     Name, degree and period shown on the home page
src/             TypeScript and CSS
  app.ts         Layer stack, routing, focus, Escape and back navigation
  views.ts       Builders for the home, year and subject views
  motion.ts      Expand, collapse and reveal animations
  route.ts       Hash parsing and content lookup
  fonts.ts       Argentum Sans loading
  styles.css     Palette, layout and styles
assets/
  brand/         Official university logo files
  fonts/         Argentum Sans WOFF2 files
  projects/      Files referenced by projects, such as PDFs
docs/            Built site (committed, served by GitHub Pages)
```

## Editing the content

All content lives in `content/`.

1. **Descriptions and projects.** Edit `content/years.ts`. Replace each `"[DESCRIPTION PENDING]"` with the author's text. Keep subject descriptions to two lines at most.
2. **Adding subjects.** Add an object to the `subjects` array of the right semester:

   ```ts
   {
     id: "algorithms",            // short, unique within the semester; it appears in the URL
     name: "Algorithms",
     description: "Two lines at most.",
     projects: [
       { title: "Project title", summary: "Short summary.", link: "https://github.com/..." },
       { title: "Report", summary: "Short summary.", file: "report.pdf" },
     ],
   },
   ```

   A `file` is a path inside `assets/projects/`. Use either `link` or `file`.
3. **Remove the example.** Delete the subject whose name starts with `EXAMPLE` once the real content is in place.
4. **Profile.** Replace `[DEGREE NAME]` in `content/profile.ts`.

The `id` values of years (`"1"` to `"4"`), semesters (`"1"` and `"2"`) and subjects appear in the URL, so changing them changes deep links.

## Brand assets

- **Logo.** Place the official horizontal mark from the university's visual identity in `assets/brand/`. The home header does not show it yet: once the file exists, add a single `<img>` to the header in `buildHome()` (`src/views.ts`) and reference it as `./assets/brand/<file>`. Show it only once on the site, and do not redraw, recolour or distort it.
- **Typeface.** Place the Argentum Sans files in `assets/fonts/` as `ArgentumSans-Regular.woff2` and `ArgentumSans-Bold.woff2`. The file names are set in `src/fonts.ts`. If the files are missing, the page uses a generic sans-serif fallback and the build still succeeds.

## Develop, check and build

Requires Node.js 22 or later.

```bash
npm install          # first time only
npm run dev          # local development server
npm run typecheck    # TypeScript in strict mode
npm run build        # writes the site to docs/
npm run preview      # serves docs/ locally, the way GitHub Pages will
```

After every change, run `npm run typecheck` and `npm run build`, then commit both `src/` and `docs/`.

## Publish to GitHub Pages

1. Run `npm run build`.
2. Commit the changes to `src/`, `content/`, `assets/` and `docs/`, then push to `main`.
3. In the repository settings, open **Pages**. Under **Build and deployment**, set the source to **Deploy from a branch**, select the **main** branch and the **/docs** folder, and save.
4. The site appears at `https://<user>.github.io/University-CV/` after a short wait.

`vite.config.ts` uses a relative base (`./`), so the same build works from any Pages path. It also copies `assets/` into `docs/assets/` and writes `docs/.nojekyll`.

## Keyboard and accessibility

- Tab moves through the controls. Focus is always visible.
- Enter or Space opens a tile or subject card.
- Escape closes the current view and returns to its parent.
- The browser back button moves up one level. Deep links open the full chain of parent views, so back keeps working.
- When a view opens, focus moves into it. When it closes, focus returns to the element that opened it.
- With `prefers-reduced-motion`, the transitions become a crossfade.
