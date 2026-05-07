package dev.vaderlang.intellij

import com.intellij.openapi.application.PathManager
import org.jetbrains.plugins.textmate.api.TextMateBundleProvider
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption

class VaderBundleProvider : TextMateBundleProvider {
    override fun getBundles(): List<TextMateBundleProvider.PluginBundle> {
        val bundleDir = extractBundle() ?: return emptyList()
        return listOf(TextMateBundleProvider.PluginBundle("Vader", bundleDir))
    }

    private fun extractBundle(): Path? {
        val target = PathManager.getSystemDir().resolve("textmate/vader-bundle")
        Files.createDirectories(target.resolve("syntaxes"))

        val ok = listOf(
            "/bundle/package.json" to target.resolve("package.json"),
            "/bundle/language-configuration.json" to target.resolve("language-configuration.json"),
            "/bundle/syntaxes/vader.tmLanguage.json" to target.resolve("syntaxes/vader.tmLanguage.json"),
        ).all { (resource, dest) -> copyResource(resource, dest) }

        return if (ok) target else null
    }

    private fun copyResource(resourcePath: String, target: Path): Boolean {
        val stream = javaClass.getResourceAsStream(resourcePath) ?: return false
        stream.use { Files.copy(it, target, StandardCopyOption.REPLACE_EXISTING) }
        return true
    }
}
