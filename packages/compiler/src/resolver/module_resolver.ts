import path from 'node:path'
import fs from 'node:fs';

export interface ModuleResolver {
    resolve(identifier: string, from: string): { key: string, content: string, location: string }
}

export class FileResolver implements ModuleResolver {
    constructor(private basePath: string, private lookupDirectories: string[] = []) {
        //this.lookupDirectories.push(this.basePath)
    }

    resolve(identifier: string, from: string): { key: string; content: string; location: string; } {
        // When from is a directory
        {
            const sameLocationFile = path.resolve(this.basePath, from, identifier);
            if (fs.existsSync(sameLocationFile)) {
                const content = fs.readFileSync(sameLocationFile, {encoding: 'utf-8'});
                return {
                    key: sameLocationFile,
                    content,
                    location: path.relative(this.basePath, sameLocationFile),
                }
            }
        }
        // When from is a file
        {
            const currentFile = path.parse(path.resolve(this.basePath, from))
            const sameLocationFile = path.resolve(currentFile.dir, identifier);
            if (fs.existsSync(sameLocationFile)) {
                const content = fs.readFileSync(sameLocationFile, {encoding: 'utf-8'});
                return {
                    key: sameLocationFile,
                    content,
                    location: path.relative(this.basePath, sameLocationFile),
                }
            }
        }

        // Look for lookupDirectories
        for (const directory of this.lookupDirectories) {
            const full_path = path.resolve(directory, identifier)
            if (fs.existsSync(full_path)) {
                const content = fs.readFileSync(full_path, {encoding: 'utf-8'});
                return {
                    key: full_path,
                    content,
                    location: path.relative(this.basePath, full_path),
                }
            }
        }
        throw new Error(`could not resolve path "${identifier}". Tried to resolve in the following locations : "${this.lookupDirectories}"`);
    }

}