import type { VaderType } from "../parser/types";
import type { ModuleResolver } from "../resolver/module_resolver";
import { locationToString, type Location } from "../tokens/types";
import { Diagnostic } from "./diagnostic";

export class BundleContext {
    private symbols: Record<string, {type: VaderType, location: Location}> = {};
    constructor(
        private resolver: ModuleResolver,
        public diagnostic: Diagnostic = new Diagnostic()
    ) {
    }

    public resolve(uri: string, from: string) {
        return this.resolver.resolve(uri, from);
    }

    public addSymbol(name: string, type: VaderType, location: Location) {
        if(name in this.symbols) {
            const existingSymbol = this.symbols[name]!;
            this.reportError(`variable '${name}' is already declared at ${locationToString(existingSymbol.location)}`, location)
            return;
        }
        this.symbols[name] = {type, location};
    }

    public hasReportedError() {
        return this.diagnostic.getDiagnostics().filter(d => d.type === 'ERROR').length > 0;
    }

    public report(level: 'ERROR' | 'WARN' | 'INFO', message: string, location: Location) {
        this.diagnostic.add(level, message, location);
    }

    public reportError(message: string, location: Location) {
        this.report('ERROR', message, location);
    }

    public reportWarning(message: string, location: Location) {
        this.report('WARN', message, location);
    }

    public reportInfo(message: string, location: Location) {
        this.report('INFO', message, location);
    }
}