package dev.vaderlang.intellij

import com.intellij.openapi.project.DumbAware
import com.intellij.openapi.project.Project
import com.intellij.openapi.vfs.VirtualFile
import com.jetbrains.jsonSchema.extension.JsonSchemaFileProvider
import com.jetbrains.jsonSchema.extension.JsonSchemaProviderFactory
import com.jetbrains.jsonSchema.extension.SchemaType

/**
 * Validates and completes `vader.json` against the schema shared with the VS Code
 * extension: `editors/common/vader.schema.json`, packaged under `schemas/` by
 * `processResources`.
 */
class VaderJsonSchemaProviderFactory : JsonSchemaProviderFactory, DumbAware {
    override fun getProviders(project: Project): List<JsonSchemaFileProvider> = listOf(VaderManifestSchema)
}

private const val MANIFEST_FILENAME = "vader.json"

private object VaderManifestSchema : JsonSchemaFileProvider {
    override fun isAvailable(file: VirtualFile): Boolean = file.name == MANIFEST_FILENAME

    override fun getName(): String = MANIFEST_FILENAME

    override fun getSchemaFile(): VirtualFile? =
        JsonSchemaProviderFactory.getResourceFile(VaderJsonSchemaProviderFactory::class.java, "/schemas/vader.schema.json")

    override fun getSchemaType(): SchemaType = SchemaType.embeddedSchema
}
