// tests/site_content: every program the site shows runs, and prints what the
// site says it prints.
//
// The pages of `site/content/` are Markdown. Each ```vader block is a whole
// program, run here on the VM; a ```text block right after one, with nothing but
// blank lines between them, is its output, compared exactly. A line of the
// program that opens with `# ` (or a lone `#`) is compiled but not shown, as in
// vaderdoc's `@example`: the site's own rule decides (`hidden_lines.js`). The examples
// of the repository have their own test (`examples_run.test.ts`), whose
// snapshots the site shows.

import { expect, test } from "bun:test";
import { mkdtempSync, readdirSync, readFileSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { compiled_code } from "../site/src/lib/server/hidden_lines.js";
import { ensureCliBuilt, runCli } from "./cli-bin.ts";

ensureCliBuilt();

const CONTENT = join(import.meta.dir, "..", "site", "content");
const FENCE = /^```(\w*)$/;

interface Program {
  where: string;
  source: string;
  output: string | null;
}

interface Block {
  lang: string;
  body: string;
  line: number;
  // Only blank lines separate it from the block before.
  adjacent: boolean;
}

// The fenced blocks of `text`, in order.
function blocks(text: string): Block[] {
  const out: Block[] = [];
  let open: { lang: string; line: number; body: string[]; adjacent: boolean } | null = null;
  let afterBlock = false;
  text.split("\n").forEach((line, i) => {
    const fence = FENCE.exec(line);
    if (open) {
      if (line === "```") {
        out.push({ lang: open.lang, body: open.body.join("\n"), line: open.line, adjacent: open.adjacent });
        open = null;
        afterBlock = true;
      } else {
        open.body.push(line);
      }
    } else if (fence) {
      open = { lang: fence[1]!, line: i + 1, body: [], adjacent: afterBlock };
    } else if (line.trim() !== "") {
      afterBlock = false;
    }
  });
  return out;
}

// What the block after a program says it prints: a `text` block right after it,
// or nothing.
function outputAfter(next: Block | undefined): string | null {
  if (!next || next.lang !== "text" || !next.adjacent) return null;
  return next.body;
}

function programs(): Program[] {
  const files = readdirSync(CONTENT, { recursive: true, encoding: "utf8" }).filter((f) => f.endsWith(".md"));
  return files.flatMap((file) => {
    const found = blocks(readFileSync(join(CONTENT, file), "utf8"));
    return found.flatMap((block, i) => {
      if (block.lang !== "vader") return [];
      return [{ where: `${file}:${block.line}`, source: block.body, output: outputAfter(found[i + 1]) }];
    });
  });
}

const found = programs();

test("site content: at least one program", () => {
  expect(found.length).toBeGreaterThan(0);
});

for (const program of found) {
  test.concurrent(`site program runs: ${program.where}`, async () => {
    const dir = mkdtempSync(join(tmpdir(), "vader-site-"));
    try {
      const file = join(dir, "main.vader");
      writeFileSync(file, compiled_code(program.source) + "\n");
      const r = await runCli(["run", file]);
      expect(r.stderr).toBe("");
      expect(r.exit).toBe(0);
      if (program.output !== null) expect(r.stdout.trimEnd()).toBe(program.output);
    } finally {
      rmSync(dir, { recursive: true, force: true });
    }
  });
}
