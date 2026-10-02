package dev.vaderlang.intellij

import com.google.gson.JsonParser
import com.intellij.openapi.application.PathManager
import com.intellij.openapi.diagnostic.logger
import org.jetbrains.plugins.textmate.api.TextMateBundleProvider
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption

class VaderBundleProvider : TextMateBundleProvider {
    override fun getBundles(): List<TextMateBundleProvider.PluginBundle> {
        val bundleDir = extractBundle() ?: return emptyList()
        return listOf(TextMateBundleProvider.PluginBundle("Vader", bundleDir))
    }

    // The TextMate plugin reads the extracted copy, not the jar: copy
    // `bundle/package.json` and every file it names — each language's
    // configuration, each grammar.
    private fun extractBundle(): Path? {
        val manifest = javaClass.getResourceAsStream("/bundle/package.json")
            ?.use { it.readBytes().decodeToString() }
            ?: return null
        val target = PathManager.getSystemDir().resolve("textmate/vader-bundle")
        for (file in listOf("package.json") + namedFiles(manifest)) {
            if (!copyResource("/bundle/$file", target.resolve(file))) {
                LOG.warn("Vader TextMate bundle: `bundle/$file` is named by package.json but missing from the plugin")
            }
        }
        return target
    }

    private fun namedFiles(manifest: String): List<String> {
        val contributes = JsonParser.parseString(manifest).asJsonObject.getAsJsonObject("contributes")
        val configurations = contributes.getAsJsonArray("languages")
            .mapNotNull { it.asJsonObject.get("configuration")?.asString }
        val grammars = contributes.getAsJsonArray("grammars")
            .map { it.asJsonObject.get("path").asString }
        return (configurations + grammars).map { it.removePrefix("./") }
    }

    private fun copyResource(resourcePath: String, target: Path): Boolean {
        val stream = javaClass.getResourceAsStream(resourcePath) ?: return false
        Files.createDirectories(target.parent)
        stream.use { Files.copy(it, target, StandardCopyOption.REPLACE_EXISTING) }
        return true
    }

    private companion object {
        val LOG = logger<VaderBundleProvider>()
    }
}
