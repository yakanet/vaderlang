package dev.vaderlang.intellij

import com.intellij.execution.filters.ConsoleFilterProvider
import com.intellij.execution.filters.Filter
import com.intellij.execution.filters.OpenFileHyperlinkInfo
import com.intellij.openapi.project.Project
import com.intellij.openapi.vfs.LocalFileSystem
import com.intellij.openapi.vfs.VirtualFile

// Makes `[path:line:column]` in console output clickable.
//
// The compiler prints a path RELATIVE to its working directory when the file is
// under it, which is what keeps a diagnostic readable instead of spending most
// of the line on `/Users/…/vaderlang2/`. IntelliJ's built-in console filters do
// not link a relative path — they linked the old absolute ones, so shortening
// them silently cost Ctrl+click. This gives it back rather than trading one for
// the other.
//
// Resolution mirrors what the compiler did: an absolute path is opened as-is, a
// relative one is joined to the project root — which is exactly the working
// directory the run configuration sets (`VaderRunConfigurationType`), so the two
// agree by construction rather than by coincidence.
internal class VaderConsoleFilterProvider : ConsoleFilterProvider {
    override fun getDefaultFilters(project: Project): Array<Filter> =
        arrayOf(VaderDiagnosticFilter(project))
}

private class VaderDiagnosticFilter(private val project: Project) : Filter {
    override fun applyFilter(line: String, entireLength: Int): Filter.Result? {
        val m = PATTERN.find(line) ?: return null
        val path = m.groupValues[1]
        val lineNo = m.groupValues[2].toIntOrNull() ?: return null
        val column = m.groupValues[3].toIntOrNull() ?: return null
        val file = resolve(path) ?: return null

        // `entireLength` counts every character the console has emitted so far;
        // the offsets a Result carries are absolute in that stream, not in this
        // line. Getting this wrong underlines the wrong text somewhere far above.
        val lineStart = entireLength - line.length
        val range = m.groups[1] ?: return null
        return Filter.Result(
            lineStart + range.range.first,
            lineStart + m.range.last + 1,
            // 0-based for the editor, 1-based in the diagnostic.
            OpenFileHyperlinkInfo(project, file, lineNo - 1, column - 1),
        )
    }

    private fun resolve(path: String): VirtualFile? {
        val fs = LocalFileSystem.getInstance()
        if (path.startsWith("/")) {
            return fs.findFileByPath(path)
        }
        val base = project.basePath ?: return null
        return fs.findFileByPath("$base/$path")
    }

    private companion object {
        // `[<path>:<line>:<col>]` — the shape `format_diagnostic` emits
        // (`vader/diagnostics/render.vader`). Anchored on the brackets so a
        // colon-separated fragment inside a message cannot masquerade as one.
        val PATTERN = Regex("\\[([^\\[\\]:]+\\.vader):(\\d+):(\\d+)]")
    }
}
