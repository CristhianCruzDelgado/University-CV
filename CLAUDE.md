# CLAUDE.md

## Language

- Reply to the author in Spanish.
- Everything in the repository is in English: interface text, content, file and folder names, identifiers, code comments, commit messages, and the README.

## Project

An online academic CV for Cristhian Cruz Delgado, student at the Universidad de La Laguna (ULL), Bachelor's Degree in Computer Engineering (Grado en Ingeniería Informática), 2023–2027.

- Visual, simple, and striking. Presentation is the priority.
- The reveal transition is the signature feature. It must feel polished and deliberate. A plain list is not acceptable.
- Online only. No PDF export, no print styles, no dark mode.
- Desktop browsers only. Mobile and tablet testing are out of scope, but the layout must not break badly on them.
- Hosted on GitHub Pages.

## Stack and build

- TypeScript in strict mode, with no UI framework. Use vanilla DOM.
- Source lives in `src/`. Vite builds it into `docs/`, which GitHub Pages serves from the `main` branch.
- Use relative asset paths (`base: "./"`) so the site works from the Pages URL.
- Routing is hash-based (for example `#/year/1/semester/1`). This keeps deep links and the browser back button working on GitHub Pages.
- Scripts: `npm run dev`, `npm run build`, `npm run typecheck`.
- Use no animation libraries. Animations use the browser's own APIs.
- Commit both `src/` and the built `docs/`.

## Code style

### Principles

- Follow the Google TypeScript Style Guide for TypeScript, and the Google HTML/CSS Style Guide for markup and styles.
- Follow the principles of *Clean Code* (Robert C. Martin):
  - Names reveal intent. Prefer a longer, precise name to a short, vague one.
  - Functions do one thing, at one level of abstraction. Keep them short, and avoid more than three parameters. Avoid boolean flag parameters: split the function instead.
  - No magic numbers or strings. Give them named constants.
  - No duplication. Extract shared logic once it appears a second time.
  - Comments explain *why*, not *what*. If a comment is needed to explain *what* code does, rename or restructure the code instead.
  - No dead code, commented-out code, or unused exports.
  - Handle errors explicitly. Do not swallow exceptions silently.
  - Keep modules focused. Separate rendering, routing, state, animation, and content into distinct modules.
- Prefer clarity over cleverness.

### TypeScript (Google style, enforced by ESLint and Prettier)

- Indentation: 2 spaces. Maximum line length: 80 characters.
- Strings: single quotes. Always end statements with semicolons.
- Use `const` by default and `let` only when reassignment is needed. Never use `var`.
- Never use `any`. Use `unknown` and narrow it, or define a proper type.
- Use named exports. Do not use default exports.
- Naming: `camelCase` for variables, functions, and methods; `PascalCase` for types, interfaces, and classes; `UPPER_SNAKE_CASE` for true constants.
- Use `interface` for object shapes and `type` for unions and aliases.
- Add a JSDoc comment to every exported function, type, and interface.
- Prefer explicit return types on exported functions.
- Use the strict compiler options. Do not disable a rule or type check without a written reason in a comment.

### HTML and CSS (Google style)

- Lowercase element and attribute names. Double quotes in attributes. Two-space indentation.
- Use semantic elements (`header`, `main`, `nav`, `section`, `button`, `a`) before adding `div` and `span`.
- Put all `<script>` tags in `<head>`, with `type="module"` and a relative `src`. Do not place scripts at the end of `<body>`.
- Do not use inline scripts or inline styles.
- Use class names in lowercase kebab-case, and organize CSS by component.

## Brand rules (Universidad de La Laguna)

These rules come from the institution's visual identity summary, which the author has provided. They are mandatory.

- **Colors:** use only two colors.
  - `--ull-purple: #5C068C`
  - `--ull-white: #FFFFFF`
  - Text is purple on white or white on purple. No other text colors. Do not add other hues.
- **Typeface:** Argentum Sans is the official typeface. Load it from `assets/fonts/` as WOFF2 files. Use a generic sans-serif fallback only if the font fails to load. Do not use Montserrat, which the manual allows only in Google Docs.
- **Logo:**
  - Use only the official mark from the university's visual identity repository, stored in `assets/brand/`.
  - Prefer the horizontal format.
  - Do not redraw, distort, rotate, add effects, or change the mark's typography.
  - Show only one university mark on the site, in the header.
  - Do not use the traditional San Fernando coat of arms.
  - Do not use the Centenary commemorative mark.
- **Acronym:** "ULL" may appear in plain text and URLs, but never as part of a brand or mark. Write "Universidad de La Laguna" in full wherever a name is needed.

## Design principles

- Follow the Impeccable skill for all visual and motion craft decisions, including composition, spacing, hierarchy, and timing. The rules in this file cover brand, code, and behavior only.
- If a rule here seems to conflict with Impeccable, follow Impeccable on craft and keep the brand, code, and behavior rules. Then flag the conflict to the author.

## Layout and viewport

- Every view fits the desktop browser window. Home, year, and subject views must have no page-level scroll.
- If content is taller than its column, the column scrolls internally, not the page.
- Verify the layout at 1280×720, 1366×768, 1920×1080, and 2560×1440.

## Information architecture

1. **Home (`#/`)**
   - The author's name and the university mark in the header.
   - Four large buttons, one per academic year:
     - 1st Year (2023–2024)
     - 2nd Year (2024–2025)
     - 3rd Year (2025–2026)
     - 4th Year (2026–2027)
2. **Year (`#/year/N`)**
   - Two full-height columns side by side: First Semester (left) and Second Semester (right).
   - Each column has a header with the semester name.
   - Columns are vertical. Do not stack the semesters in rows.
3. **Subject cards**
   - Each subject in a semester column is a card that shows:
     - The subject name.
     - A description of two lines at most, written by the author.
   - Subjects carry no credit information. All subjects are 6 credits, so the field is omitted.
   - Clicking a card opens its subject view.
4. **Subject view (`#/year/N/semester/M/subject/K`)**
   - The full subject name and description.
   - A list of the author's projects for that subject. Each project shows:
     - Title.
     - Short summary.
     - Link to a GitHub repository, or a file in `assets/projects/`.
   - If a subject has no projects, show a short placeholder line rather than leaving the space empty.
Breadcrumbs show the current path, for example: Home › 1st Year › First Semester › Subject name.
 
## Transitions (the signature feature)

- Each button opens its target by expanding from its own on-screen position, and closing returns the view to that same position.
  - Home tile → Year view.
  - Subject card → Subject view.
- Reopening the same element starts from its position again and restores the state the user left (scroll position, open project, and so on).
- Motion uses transforms and opacity so it stays smooth. Avoid layout jank. Target 60 fps.
- Content inside an expanded view fades or staggers in after the container settles. Keep it subtle.
- Respect `prefers-reduced-motion`: use a simple crossfade instead of positional motion.
- Exact durations and easing follow the Impeccable skill.

## Navigation and accessibility

- Use real `<button>` and `<a>` elements.
- Every control is reachable by keyboard. Focus is visible.
- Enter or Space opens an item. Escape closes the current view and returns to its parent.
- The browser back button moves up one level, not out of the site.
- When a view opens, move focus into it. When it closes, return focus to the element that opened it.
- Use `role="dialog"` and `aria-modal` on expanded views, with appropriate labels.
- Contrast is guaranteed by the two-color palette, but check the final result.

## Content

- All content lives in `content/`, as typed TypeScript data. This is the single source of truth.
- Suggested schema:

```ts
export interface Project {
  readonly title: string;
  readonly summary: string;
  readonly link?: string;
  readonly file?: string;
}

export interface Subject {
  readonly id: string;
  readonly name: string;
  readonly description: string;
  readonly projects: readonly Project[];
}

export interface Semester {
  readonly id: string;
  readonly name: string;
  readonly subjects: readonly Subject[];
}

export interface AcademicYear {
  readonly id: string;
  readonly label: string;
  readonly semesters: readonly Semester[];
}
```

- The author writes all subject descriptions and project entries after the site is built.
- Until then, use `"[DESCRIPTION PENDING]"` for descriptions. Show a clear placeholder rather than making up text.
- Never invent academic content, project names, or links.
- One example subject, clearly marked `EXAMPLE` in its name, may be included to show the layout. The author will replace it.

## Assets

- `assets/brand/`: the official university logo files.
- `assets/fonts/`: Argentum Sans WOFF2 files.
- `assets/projects/`: files referenced by projects, such as PDFs.

## Working rules for Claude

- Read the Impeccable skill before designing or changing any visual element.
- After each change, run `npm run check`. Fix every error and warning before reporting back.
- Verify the desktop behavior: no page-level scroll, transitions, Escape and back navigation, and deep links.
- Do not commit or push unless the author asks.
- Ask before changing brand rules, information architecture, or content.
- Report what changed and how to check it, in Spanish.

## Deployment

- GitHub Pages serves the `docs/` folder from the `main` branch. In the repository settings, set the Pages source to "Deploy from a branch", branch `main`, folder `/docs`.
- `docs/` must contain a `.nojekyll` file. This tells GitHub Pages to serve the built files as they are, without running Jekyll. Without it, Pages tries to process the site with Jekyll and can fail.
- `docs/` must be committed. Run `npm run build` before each push so the published files are current.
- Keep the `CNAME` file in `docs/` if a custom domain is ever added. Vite empties `docs/` on build, so `CNAME` and `.nojekyll` must live in `public/` to survive the build.
- The README (in English) explains how to edit content, build, and publish, and includes a troubleshooting section for these deployment issues.
