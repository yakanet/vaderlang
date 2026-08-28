package dev.vaderlang.intellij

import com.intellij.codeInsight.daemon.LineMarkerInfo
import com.intellij.codeInsight.daemon.LineMarkerProviderDescriptor
import com.intellij.codeInsight.navigation.NavigationGutterIconBuilder
import com.intellij.icons.AllIcons
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
        for (element in elements) {
            // Leaf tokens only — otherwise every ancestor node yields a marker
            // and the gutter shows one icon per nesting level.
            if (element.firstChild != null) continue
            val file = element.containingFile ?: continue
            val self = file.virtualFile ?: continue
            if (!self.name.endsWith(".vader")) continue

            val name = element.text
            val offset = element.textRange.startOffset
            if (!isDeclarationLine(file.text, offset, name)) continue
            val decorator = targetDecoratorAbove(file.text, offset) ?: continue
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

            result.add(
                NavigationGutterIconBuilder.create(icon)
                    .setTargets(targets)
                    .setTooltipText(tooltip)
                    .createLineMarkerInfo(element),
            )
        }
    }
}

// True when `offset` sits on the NAME being bound on this line. `export` is
// legal only on the declaration — a body carrying it is R2037 — but this does
// not enforce that: the compiler already does, and a marker that vanished on
// invalid code would read as "no bodies" rather than as an error.
private fun isDeclarationLine(text: String, offset: Int, name: String): Boolean {
    val line = lineAround(text, offset)
    return Regex("^\\s*(export\\s+)?${Regex.escape(name)}\\s*::").containsMatchIn(line)
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
