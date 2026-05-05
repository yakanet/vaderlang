// Unified diff utility for snapshot test error messages.
// LCS-based, dependency-free, ANSI-colored when running in a TTY.

const USE_COLOR = Boolean(process.stdout.isTTY) && !process.env["NO_COLOR"];

function paint(code: string, s: string): string {
  return USE_COLOR ? `\x1b[${code}m${s}\x1b[0m` : s;
}

type Edit = { kind: "eq" | "del" | "ins"; line: string };

function lcsEdits(a: string[], b: string[]): Edit[] {
  const m = a.length, n = b.length;
  const dp: Uint32Array[] = Array.from({ length: m + 1 }, () => new Uint32Array(n + 1));
  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      dp[i]![j] = a[i - 1] === b[j - 1]
        ? dp[i - 1]![j - 1]! + 1
        : Math.max(dp[i - 1]![j]!, dp[i]![j - 1]!);
    }
  }
  const edits: Edit[] = [];
  let i = m, j = n;
  while (i > 0 || j > 0) {
    if (i > 0 && j > 0 && a[i - 1] === b[j - 1]) {
      edits.push({ kind: "eq",  line: a[i - 1]! });
      i--; j--;
    } else if (j > 0 && (i === 0 || dp[i]![j - 1]! >= dp[i - 1]![j]!)) {
      edits.push({ kind: "ins", line: b[j - 1]! });
      j--;
    } else {
      edits.push({ kind: "del", line: a[i - 1]! });
      i--;
    }
  }
  return edits.reverse();
}

function unifiedDiff(expected: string, actual: string, ctx = 3): string {
  if (expected === actual) return "";
  const a = expected.split("\n");
  const b = actual.split("\n");
  const edits = lcsEdits(a, b);

  // Identify positions of changed edits.
  const changed: number[] = [];
  for (let k = 0; k < edits.length; k++) {
    if (edits[k]!.kind !== "eq") changed.push(k);
  }
  if (changed.length === 0) return "";

  // Merge change positions into hunk index ranges [start, end] in edits[].
  const hunks: Array<[number, number]> = [];
  let hs = Math.max(0, changed[0]! - ctx);
  let he = Math.min(edits.length - 1, changed[0]! + ctx);
  for (let c = 1; c < changed.length; c++) {
    const ns = Math.max(0, changed[c]! - ctx);
    if (ns <= he + 1) {
      he = Math.min(edits.length - 1, changed[c]! + ctx);
    } else {
      hunks.push([hs, he]);
      hs = ns;
      he = Math.min(edits.length - 1, changed[c]! + ctx);
    }
  }
  hunks.push([hs, he]);

  // Render header + hunks.
  const out: string[] = [
    paint("90", "--- expected"),
    paint("90", "+++ actual"),
  ];

  let aLine = 1, bLine = 1, ei = 0;
  for (const [hunkStart, hunkEnd] of hunks) {
    // Count lines in this hunk for the @@ header.
    let aC = 0, bC = 0;
    for (let k = hunkStart; k <= hunkEnd; k++) {
      if (edits[k]!.kind !== "ins") aC++;
      if (edits[k]!.kind !== "del") bC++;
    }
    // Advance line counters past edits before this hunk.
    while (ei < hunkStart) {
      if (edits[ei]!.kind !== "ins") aLine++;
      if (edits[ei]!.kind !== "del") bLine++;
      ei++;
    }
    out.push(paint("36", `@@ -${aLine},${aC} +${bLine},${bC} @@`));
    for (let k = hunkStart; k <= hunkEnd; k++) {
      const { kind, line } = edits[k]!;
      if (kind === "eq")  out.push(paint("90", ` ${line}`));
      if (kind === "del") out.push(paint("31", `-${line}`));
      if (kind === "ins") out.push(paint("32", `+${line}`));
      if (kind !== "ins") aLine++;
      if (kind !== "del") bLine++;
      ei++;
    }
  }
  return out.join("\n");
}

/** Format a snapshot mismatch for use in test error messages. */
export function snapshotDiff(label: string, expected: string | null, actual: string): string {
  if (expected === null) {
    return `(no snapshot yet — run with UPDATE_SNAPSHOTS=1)\n\n--- actual ---\n${actual}`;
  }
  const diff = unifiedDiff(expected, actual);
  return diff !== "" ? diff : `(diff produced no output for ${label})`;
}
