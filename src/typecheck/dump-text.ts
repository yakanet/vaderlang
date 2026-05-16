import type { TypedProject } from "./typed-ast.ts";
import { displayType } from "./types.ts";
import { isStdlibModule } from "../resolver/module.ts";

/** Text dump of a typed project, byte-for-byte aligned with
 *  the future `vader/typecheck/dump.vader::dump_project`. Both the
 *  snapshot generator (`tests/snapshot.ts::dumpTypecheck`) and the CLI
 *  stage (`src/cli/commands/dump.ts::runTypedAstStage`) call this so a
 *  format change updates one place. */
export function formatTypedDump(typed: TypedProject): string {
  const lines: string[] = ["# Typecheck"];
  for (const id of [...typed.modules.keys()].sort()) {
    const p = typed.modules.get(id)!;
    if (isStdlibModule(p.resolved.module.displayPath)) continue;
    lines.push(`\n## ${p.resolved.module.displayPath}`);
    const decls = p.resolved.source.decls
      .filter((d) => "name" in d)
      .sort((a, b) => ("name" in a && "name" in b ? a.name.localeCompare(b.name) : 0));
    for (const d of decls) {
      const ty = p.declTypes.get(d);
      const name = "name" in d ? d.name : "?";
      lines.push(`  ${d.kind.padEnd(14)} ${name.padEnd(20)} :: ${ty !== undefined ? displayType(ty) : "?"}`);
    }
    const exprLines: string[] = [];
    for (const [expr, ty] of p.exprTypes) {
      if (expr.kind === "IntLitExpr" || expr.kind === "FloatLitExpr"
          || expr.kind === "BoolLitExpr" || expr.kind === "NullLitExpr"
          || expr.kind === "CharLitExpr" || expr.kind === "BlockExpr") continue;
      const loc = `${expr.span.start.line}:${expr.span.start.column}`;
      exprLines.push(`  expr ${loc.padEnd(8)} ${expr.kind.padEnd(14)} :: ${displayType(ty)}`);
    }
    exprLines.sort();
    lines.push(...exprLines);
  }
  return lines.join("\n") + "\n";
}
