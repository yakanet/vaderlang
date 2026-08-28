package dev.vaderlang.intellij

import com.intellij.codeInsight.daemon.LineMarkerInfo
import com.intellij.codeInsight.daemon.LineMarkerProviderDescriptor
import com.intellij.codeInsight.navigation.NavigationGutterIconBuilder
import com.intellij.icons.AllIcons
import com.intellij.openapi.diagnostic.Logger
import com.intellij.openapi.vfs.VirtualFile
import com.intellij.psi.PsiElement
import com.intellij.psi.PsiManager

// The `(I)` gutter icon on a bare `@target` declaration, like Java's
// "is implemented by" marker: click it to jump to the bodies.
//
// WHY NOT ASK THE LANGUAGE SERVER. The server answers this exactly
// (`textDocument/implementation`), but a LineMarkerProvider runs inside
// highlighting and a per-line JSON-RPC round-trip there is not affordable — and
// LSP4IJ exposes no gutter hook that would do it for us.
//
// WHY THE FOLDER IS ENOUGH. A Vader module IS a directory: `module "..."` must
// match the folder, and files in one folder declaring different module names is
// an error (R2022). Every body of a group therefore lives beside the
// declaration, so scanning the containing folder's `*.vader` files finds all of
// them — including the cross-file shape the SPEC uses in its own example
// (`path.vader` + `path-windows.vader`).
//
// Vader has no PSI (TextMate-only highlighting), so this hooks the TextMate leaf
// carrying the declaration's name and confirms the shape from the surrounding
// text — the same technique `VaderRunLineMarker` already uses for the ▶ icon.
//
// ⚠️ Not verified in a running IDE. Whether TextMate yields a leaf exactly on
// the name is a live check (`./gradlew runIde`); if it does not, the icon simply
// does not appear and nothing else changes.
internal class VaderImplementationLineMarkerProvider : LineMarkerProviderDescriptor() {
    override fun getName(): String = "Vader @target bodies"

    override fun getIcon() = AllIcons.Gutter.ImplementedMethod

    // The fast pass must stay cheap — it runs on every keystroke. Reading
    // sibling files belongs in `collectSlowLineMarkers`, which the daemon runs
    // afterwards, off the critical path.
    override fun getLineMarkerInfo(element: PsiElement): LineMarkerInfo<*>? = null

    override fun collectSlowLineMarkers(
        elements: MutableList<out PsiElement>,
        result: MutableCollection<in LineMarkerInfo<*>>,
    ) {
        // Whether this provider RUNS at all for TextMate files is not something
        // that can be checked outside a live IDE, and a gutter icon that does
        // not appear gives no signal either way. One line per file that holds a
        // `@target` turns "nothing happened" into something readable in
        // Help → Show Log — silence there means the provider is never invoked,
        // which is a different bug from "invoked and matched nothing".
        var seen = 0
        var matched = 0
        for (element in elements) {
            // Leaf tokens only — otherwise every ancestor node yields a marker
            // and the gutter shows one icon per nesting level.
            if (element.firstChild != null) continue
            val file = element.containingFile ?: continue
            val self = file.virtualFile ?: continue
            if (!self.name.endsWith(".vader")) continue

            // The name is read from the TEXT, never from `element.text`.
            // TextMate splits by scope, not by identifier, so a leaf may be a
            // whole run of a line — assuming one leaf per name is what makes a
            // marker silently never appear.
            val text = file.text
            val offset = element.textRange.startOffset
            val bound = declarationNameAt(text, offset) ?: continue
            // Exactly ONE leaf per declaration gets the marker: the one covering
            // the name's first character. Without this every leaf on the line
            // would qualify and the gutter would stack duplicates.
            if (!element.textRange.contains(bound.second)) continue
            val name = bound.first
            seen++
            val decorator = targetDecoratorAbove(text, offset) ?: continue
            val psi = PsiManager.getInstance(element.project)

            // Bare `@target` → down to the bodies. `@target(.Os, …)` → up to the
            // declaration. Two directions, two icons, the same pair IntelliJ
            // uses for a Java interface and its implementors — so the gutter
            // reads the way a Java developer already expects.
            val (targets, tooltip, icon) = if (decorator == "@target") {
                Triple(
                    bodiesOf(name, self, psi),
                    "Bodies of `$name` — one per target",
                    AllIcons.Gutter.ImplementedMethod,
                )
            } else {
                Triple(
                    declarationOf(name, self, psi),
                    "Declaration of `$name` — the signature this body fills",
                    AllIcons.Gutter.ImplementingMethod,
                )
            }
            if (targets.isEmpty()) continue

            matched++
            result.add(
                NavigationGutterIconBuilder.create(icon)
                    .setTargets(targets)
                    .setTooltipText(tooltip)
                    .createLineMarkerInfo(element),
            )
        }
        if (seen > 0) {
            LOG.info("vader: @target gutter — $seen candidate line(s), $matched marker(s)")
        }
    }

    private companion object {
        val LOG = Logger.getInstance(VaderImplementationLineMarkerProvider::class.java)
    }
}

// The name bound on the line holding `offset`, with its absolute start offset,
// or null when that line binds nothing.
//
// `export` is legal only on the declaration — a body carrying it is R2037 — but
// this does not enforce it: the compiler already does, and a marker that
// vanished on invalid source would read as "no bodies" rather than as an error.
private fun declarationNameAt(text: String, offset: Int): Pair<String, Int>? {
    val start = lineStart(text, offset)
    val line = lineAround(text, offset)
    val m = Regex("^\\s*(?:export\\s+)?([A-Za-z_][A-Za-z0-9_]*)\\s*::").find(line) ?: return null
    val group = m.groups[1] ?: return null
    return group.value to (start + group.range.first)
}

// The `@target` decorator governing the declaration at `offset` — `"@target"`
// for the bare form, `"@target(...)"` for a body — or null when there is none.
//
// Walks up past vaderdoc and other decorators, which may legally sit between
// `@target` and the declaration.
private fun targetDecoratorAbove(text: String, offset: Int): String? {
    var cursor = lineStart(text, offset)
    while (cursor > 0) {
        val prev = lineAround(text, cursor - 1).trim()
        cursor = lineStart(text, cursor - 1)
        if (prev.isEmpty() || prev.startsWith("//")) continue
        if (prev == "@target") return "@target"
        if (prev.startsWith("@target")) return prev
        if (prev.startsWith("@")) continue
        return null
    }
    return null
}

// Every `@target(...)`-decorated declaration of `name` in the module — that is,
// in the folder — as PSI elements to navigate to.
private fun bodiesOf(name: String, self: VirtualFile, psi: PsiManager): List<PsiElement> {
    val folder = self.parent ?: return emptyList()
    val out = mutableListOf<PsiElement>()
    for (sibling in folder.children) {
        if (sibling.isDirectory || !sibling.name.endsWith(".vader")) continue
        val psiFile = psi.findFile(sibling) ?: continue
        val text = psiFile.text
        // `@target(` — with the paren, so the bare declaration itself is never
        // listed as one of its own bodies.
        for (m in Regex("@target\\s*\\([^)]*\\)\\s*(\\n\\s*@[^\\n]*)*\\s*\\n\\s*${Regex.escape(name)}\\s*::")
            .findAll(text)) {
            // Locate the name INSIDE the match rather than counting back from
            // its end: `name ::` and `name::` are both legal, so arithmetic on
            // the tail lands on whitespace for one of them.
            val at = m.range.first + m.value.lastIndexOf(name)
            out.add(psiFile.findElementAt(at.coerceAtLeast(0)) ?: continue)
        }
    }
    return out
}

// The module's bare `@target` declaration of `name` — the signature a body
// fills. One per group (a second is R2039), but returned as a list because
// `NavigationGutterIconBuilder` takes one, and because on invalid source the
// honest answer is "these, plural" rather than an arbitrary pick.
private fun declarationOf(name: String, self: VirtualFile, psi: PsiManager): List<PsiElement> {
    val folder = self.parent ?: return emptyList()
    val out = mutableListOf<PsiElement>()
    // `@target` NOT followed by `(` — `[^(\n]*` lets the line end or carry a
    // trailing comment, without swallowing the body form.
    val pattern = Regex(
        "@target[ \\t]*(\\n\\s*@[^\\n]*)*\\s*\\n\\s*(export\\s+)?${Regex.escape(name)}\\s*::",
    )
    for (sibling in folder.children) {
        if (sibling.isDirectory || !sibling.name.endsWith(".vader")) continue
        val psiFile = psi.findFile(sibling) ?: continue
        for (m in pattern.findAll(psiFile.text)) {
            val at = m.range.first + m.value.lastIndexOf(name)
            out.add(psiFile.findElementAt(at.coerceAtLeast(0)) ?: continue)
        }
    }
    return out
}

private fun lineStart(text: String, offset: Int): Int {
    var start = offset.coerceIn(0, text.length)
    while (start > 0 && text[start - 1] != '\n') start--
    return start
}

private fun lineAround(text: String, offset: Int): String {
    val start = lineStart(text, offset)
    var end = offset.coerceIn(0, text.length)
    while (end < text.length && text[end] != '\n') end++
    return text.substring(start, end)
}
