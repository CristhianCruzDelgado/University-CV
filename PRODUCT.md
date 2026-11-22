# Product

<!-- impeccable:product-schema 1 -->

## Platform

web

## Stack

delegated to CLAUDE.md: TypeScript (strict) and Vite, vanilla DOM, no UI framework, no animation libraries, built into `docs/` for GitHub Pages with relative base and hash routing.

## Users

Recruiters, professors, and peers who evaluate Cristhian Cruz Delgado's academic work. Inferred from CLAUDE.md: they arrive from a link, scan the path through the degree, and open subject projects. Desktop browsers only.

## Product Purpose

An online academic CV for Cristhian Cruz Delgado, a student at the Universidad de La Laguna (2023–2027). It maps the four academic years, the two semesters of each year, the subjects in each semester, and the projects the author produced for each subject. Success: a visitor knows where the author studied, what they studied, and what they built, within seconds.

## Positioning

The academic path is the interface. Every level is reached by expanding from the element that was pressed, so the visitor always knows where they came from and how to return.

## Operating Context

Viewed on a desktop browser window, usually 1280×720 to 2560×1440. Content is authored by the student in `content/`. Project files live in `assets/projects/` or on GitHub.

## Capabilities and Constraints

- Four academic years, each with two semesters. Subjects are 6 credits each and carry no credit field.
- Subject descriptions are two lines at most and are written by the author.
- Projects have a title, a short summary, and a link to GitHub or a file in `assets/projects/`.
- Routing is hash-based so deep links and the browser back button work on GitHub Pages.

## Brand Commitments

- Universidad de La Laguna visual identity: only two colours, `--ull-purple: #5C068C` and `--ull-white: #FFFFFF`. Text is purple on white or white on purple.
- Typeface: Argentum Sans, loaded from `assets/fonts/` as WOFF2. A generic sans-serif fallback is used when it is missing.
- Logo: only the official horizontal mark from `assets/brand/`, shown once in the header.
- "ULL" never appears as part of a brand or mark. The name is written as "Universidad de La Laguna".

## Product Principles

- Every transition starts from the element the visitor pressed and returns to it on close.
- Presentation comes first: the view is calm, two-colour, and fits the window without page scroll.
- Content is the author's. Placeholders are explicit, never invented.
- Keyboard, focus, and reduced-motion behaviour are first-class.

## Accessibility & Inclusion

Every control is a real `<button>` or `<a>`. Focus is always visible. Escape closes the current view. `prefers-reduced-motion` replaces positional motion with a crossfade.
