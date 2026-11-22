import './styles/base.css';
import './styles/home.css';
import './styles/layer.css';
import './styles/year.css';
import './styles/subject.css';
import { loadArgentumSans } from './fonts';
import { startApp } from './app';

const APP_ROOT_ID = 'app';

/** Starts the site once the document is ready to receive it. */
function main(): void {
  const root = document.getElementById(APP_ROOT_ID);
  if (!(root instanceof HTMLElement)) {
    throw new Error(`Missing #${APP_ROOT_ID} element in index.html`);
  }
  loadArgentumSans();
  startApp(root);
}

main();
