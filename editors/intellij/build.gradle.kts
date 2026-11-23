import org.jetbrains.kotlin.gradle.dsl.KotlinVersion

plugins {
    id("org.jetbrains.kotlin.jvm")
    id("org.jetbrains.intellij.platform")
}

group = "dev.vaderlang"
version = "0.2.0"

dependencies {
    intellijPlatform {
        // LSP4IJ, the LSP and DAP client, is not bundled: the user installs it
        // from the Marketplace.
        intellijIdea("2025.3")
        bundledPlugin("org.jetbrains.plugins.textmate")
        bundledPlugin("com.intellij.modules.json")
        plugin("com.redhat.devtools.lsp4ij:0.30.1")
    }
}

kotlin {
    jvmToolchain(21)
    compilerOptions {
        // The standard library is the one the IDE bundles: the API version is
        // the one the oldest IDE of `sinceBuild` ships.
        apiVersion = KotlinVersion.KOTLIN_2_2
    }
}

intellijPlatform {
    pluginConfiguration {
        ideaVersion {
            sinceBuild = "253"
            untilBuild = provider { null }
        }
    }
}

tasks.processResources {
    val common = layout.projectDirectory.dir("../common")

    from(common) { include("*.tmLanguage.json"); into("bundle/syntaxes/") }
    from(common) { include("*language-configuration.json"); into("bundle/") }
    from(common) { include("*.svg"); into("icons/") }
    from(common) { include("*.schema.json"); into("schemas/") }
}
