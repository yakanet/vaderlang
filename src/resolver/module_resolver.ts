import path from 'node:path'
import fs from 'node:fs';

export interface ModuleResolver {
    resolve(identifier: string): { key: string, content: string, location: string }
}

export class FileResolver implements ModuleResolver {
    constructor(private basePath: string, private lookupDirectories: string[] = []) {
        this.lookupDirectories.push(this.basePath)
    }

    resolve(identifier: string): { key: string; content: string; location: string; } {
        if (!identifier.endsWith('.vader')) {
            identifier += '.vader'
        }
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
        throw new Error(`Could not resolve "${identifier}". Tried to resolve in the following locations : "${this.lookupDirectories}"`);
    }

}