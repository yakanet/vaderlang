import type {VaderType} from "../parser/types";
import assert from "node:assert";
import {locationToString, type Decorator, type Location} from "../tokens/types.ts";
import type { BundleContext } from "../context/context.ts";

export class Ref {
    constructor(
        public readonly named: string,
        public readonly type: VaderType,
        public readonly source: Source,
        public readonly location: Location
    ) {
    }
}

interface FunctionParameterSource {
    kind: "FunctionParameterSource";
    index: number;
}

interface GlobalFunctionSource {
    kind: "GlobalFunctionSource";
    parameters: VaderType[];
    returnType: VaderType;
    decorators: Decorator[]
}

interface LocalVariableSource {
    kind: "LocalVariableSource";
    index: number;
    address?: number;
}

interface StructSource {
    kind: "StructSource";
}

export interface GlobalParameterSource {
    kind: "GlobalParameterSource";
}

type Source =
    | FunctionParameterSource
    | LocalVariableSource
    | GlobalParameterSource
    | GlobalFunctionSource
    | StructSource;

export class Scope {
    private namedVariables = new Map<string, Ref>();
    public readonly depth: number;
    #parent?: Scope

    constructor(public readonly context: BundleContext, parent?: Scope) {
        this.#parent = parent;
        this.depth = parent ? parent.depth + 1 : 0;
    }

    static childScope(scope: Scope) {
        return new Scope(scope.context, scope);
    }

    newGlobalVariable(type: VaderType, name: string, location: Location) {
        assert(this.depth === 0, "Global variable must be declared in global scope");
        return this.newVariable(type, name, {
            kind: "GlobalParameterSource",
        }, location)
    }

    newFunctionParameter(type: VaderType, index: number, name: string, location: Location) {
        if (this.depth === 0) {
            throw new Error("Function parameter must be declared in a function scope");
        }
        if (this.depth === 1) {
            return this.newVariable(type, name, {
                kind: "FunctionParameterSource",
                index
            }, location)
        }
        return this.#parent!.newVariable(type, name, {
            kind: "FunctionParameterSource",
            index
        }, location)
    }

    newLocalVariable(type: VaderType, index: number, name: string, location: Location) {
        if (this.depth === 0) {
            throw new Error("Function parameter must be declared in a function scope");
        }
        if (this.depth === 1) {
            return this.newVariable(type, name, {
                kind: "LocalVariableSource",
                index
            }, location)
        }
        return this.#parent!.newVariable(type, name, {
            kind: "LocalVariableSource",
            index
        }, location)
    }

    private newVariable(type: VaderType, name: string, source: Source, location: Location) {
        if (this.namedVariables.has(name)) {
            throw this.context.reportError(`variable ${name} is already declared at ${locationToString(this.namedVariables.get(name)!.location)}`, location)
        }
        const ref = new Ref(name, type, source, location);
        this.namedVariables.set(name, ref);
        return ref;
    }

    lookupVariable(value: string, location: Location): Ref {
        const ref = this.namedVariables.get(value);
        if (ref) {
            return ref;
        }
        if (this.#parent) {
            return this.#parent.lookupVariable(value, location);
        }
        throw this.context.reportError(`unknown variable ${value}`, location)
    }

    allFunctionLevelVariable(): Ref[] {
        if (this.depth === 0 || this.depth === 1) {
            return [...this.namedVariables.values()]
        }
        return this.#parent!.allFunctionLevelVariable();
    }
}
