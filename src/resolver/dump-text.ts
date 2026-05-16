import type { ResolvedProject } from "./resolved-ast.ts";
import { isStdlibModule } from "./module.ts";

/** Text dump of a resolved project, byte-for-byte aligned with
 *  `vader/resolver/dump.vader::dump_project`. Both the snapshot
 *  generator (`tests/snapshot.ts::dumpResolver`) and the CLI stage
 *  (`src/cli/commands/dump.ts::runResolvedAstStage`) call this so a
 *  format change updates exactly one place. */
export function formatResolverDump(project: ResolvedProject): string {
  const lines: string[] = ["# Modules"];
  const userModules = [...project.modules.values()]
    .filter((p) => !isStdlibModule(p.module.displayPath))
    .sort((a, b) => (a.module.displayPath < b.module.displayPath ? -1 : 1));
  for (const p of userModules) {
    lines.push(`\n## ${p.module.displayPath}`);
    const syms = [...p.module.symbols.values()]
      .sort((a, b) => (a.name < b.name ? -1 : 1));
    for (const s of syms) {
      lines.push(`  ${s.kind.padEnd(16)} ${s.visibility.padEnd(8)} ${s.name}`);
    }
  }
  return lines.join("\n") + "\n";
}
