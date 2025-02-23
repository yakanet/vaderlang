import type { Location } from "../tokens/types";

export class Diagnostic {
    private diagnostics: {type: DiagnosticType, message: string, location: Location}[] = [];

    add(type: DiagnosticType, message: string, location: Location) {
        this.diagnostics.push({type, message, location})
    }    

    getDiagnostics() {
        return this.diagnostics;
    }
}

type DiagnosticType = 'INFO' | 'WARN' | 'ERROR'