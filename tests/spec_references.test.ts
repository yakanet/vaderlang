// A section of SPEC.md is cited by its chapter and its title: `§4`, `§4 *Type
// inference*`, `§4 *Representation*, *Range types*`, and inside SPEC, a section of
// the same chapter as `(*Title*, below)` or `(*Title*, above)`. A title may stop at
// its colon: `*Identity*` cites "Identity: `===` and `!==`". Renaming a heading
// must update its citations: the compiler never reads them, and the site's build
// checks only the ones it renders. This scan checks every one against the
// headings.
//
// History keeps the titles that were current when it was written, so
// `docs/HISTORY.md` and the ADRs are not scanned, nor the generated seed.

import { expect, test } from "bun:test";
import { existsSync, readdirSync, readFileSync } from "node:fs";
import { join } from "node:path";

const ROOT = join(import.meta.dir, "..");
const ROOTS = ["vader", "lib", "docs", "tests", "site/content"];
const TOP_LEVEL_FILES = ["SPEC.md", "TODO.md", "README.md"];
const SKIPPED = new Set(["docs/HISTORY.md", "docs/adr", "tests/snippets", "tests/diag_corpus"]);
const SCANNED_EXTENSION = /\.(vader|ts|md)$/;

const CHAPTER = /^## (?:(\d+)\. )?(.+)$/;
const HEADING = /^#{3,6} (.+)$/;
const FENCE = /^\s*```/;
// A title may hold code, whose `*` does not end it.
const TITLE_TEXT = "(?:`[^`]*`|[^*`])+";
const TITLE = `\\*(${TITLE_TEXT})\\*`;
const CITATION = new RegExp(`§(\\d+)((?: \\*${TITLE_TEXT}\\*)(?:, \\*${TITLE_TEXT}\\*)*)?`, "g");
const TITLES = new RegExp(TITLE, "g");
const SAME_CHAPTER = new RegExp(`\\(${TITLE}, (?:below|above)\\)`, "g");

// A title as a reader sees it, the marks of its Markdown left out.
const plain = (text: string) => text.replaceAll("`", "").replaceAll("*", "").trim();

// The forms a heading is cited by: its plain title, and the part before its colon.
function citedForms(heading: string): string[] {
  const title = plain(heading);
  return [title, title.split(": ")[0]!];
}

// The cited forms of each chapter's titles, its own included, by chapter number ;
// and the chapter each line of SPEC.md belongs to.
function specOutline(): { titles: Map<string, Set<string>>; chapterOfLine: string[] } {
  const titles = new Map<string, Set<string>>();
  const chapterOfLine: string[] = [];
  let chapter = "";
  let fenced = false;
  for (const line of readFileSync(join(ROOT, "SPEC.md"), "utf8").split("\n")) {
    if (FENCE.test(line)) fenced = !fenced;
    const opens = fenced ? null : CHAPTER.exec(line);
    if (opens) {
      chapter = opens[1] ?? "";
      titles.set(chapter, new Set(citedForms(opens[2]!)));
    }
    const heading = fenced ? null : HEADING.exec(line);
    if (heading) citedForms(heading[1]!).forEach((form) => titles.get(chapter)?.add(form));
    chapterOfLine.push(chapter);
  }
  return { titles, chapterOfLine };
}

function scannedFiles(dir: string, out: string[]): string[] {
  for (const entry of readdirSync(join(ROOT, dir), { withFileTypes: true })) {
    const path = `${dir}/${entry.name}`;
    if (SKIPPED.has(path)) continue;
    if (entry.isDirectory()) {
      scannedFiles(path, out);
    } else if (SCANNED_EXTENSION.test(entry.name) && !entry.name.includes(".snapshot")) {
      out.push(path);
    }
  }
  return out;
}

const { titles, chapterOfLine } = specOutline();

test("every section a file cites exists in SPEC.md", () => {
  const files = [
    ...ROOTS.filter((root) => existsSync(join(ROOT, root))).flatMap((root) => scannedFiles(root, [])),
    ...TOP_LEVEL_FILES.filter((file) => existsSync(join(ROOT, file))),
  ];
  const dangling: string[] = [];
  for (const file of files) {
    const lines = readFileSync(join(ROOT, file), "utf8").split("\n");
    lines.forEach((line, i) => {
      for (const citation of line.matchAll(CITATION)) {
        const chapter = titles.get(citation[1]!);
        const cited = [...(citation[2] ?? "").matchAll(TITLES)].map((t) => plain(t[1]!));
        if (!chapter || cited.some((title) => !chapter.has(title))) {
          dangling.push(`${file}:${i + 1}: ${citation[0]}`);
        }
      }
      if (file !== "SPEC.md") return;
      for (const citation of line.matchAll(SAME_CHAPTER)) {
        if (!titles.get(chapterOfLine[i]!)?.has(plain(citation[1]!))) {
          dangling.push(`${file}:${i + 1}: ${citation[0]}`);
        }
      }
    });
  }
  expect(dangling).toEqual([]);
});
