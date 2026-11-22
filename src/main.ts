import "./styles.css";
import { loadFonts } from "./fonts";
import { startApp } from "./app";

loadFonts();

const root = document.getElementById("app");
if (!root) {
  throw new Error("Missing #app root element in index.html");
}

startApp(root);
