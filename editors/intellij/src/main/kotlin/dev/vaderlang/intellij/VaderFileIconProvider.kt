package dev.vaderlang.intellij

import com.intellij.ide.FileIconProvider
import com.intellij.openapi.project.Project
import com.intellij.openapi.util.IconLoader
import com.intellij.openapi.vfs.VirtualFile
import javax.swing.Icon

class VaderFileIconProvider : FileIconProvider {
    override fun getIcon(file: VirtualFile, flags: Int, project: Project?): Icon? =
        when (file.extension?.lowercase()) {
            "vader" -> VADER
            "vir" -> VIR
            else -> null
        }

    companion object {
        private val VADER: Icon = IconLoader.getIcon("/icons/vader.svg", VaderFileIconProvider::class.java)
        private val VIR: Icon = IconLoader.getIcon("/icons/vir.svg", VaderFileIconProvider::class.java)
    }
}
