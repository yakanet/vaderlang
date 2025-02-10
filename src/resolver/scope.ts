import type {Decorator, VaderType} from "../parser/types";
import assert from "node:assert";

export class Ref {
    constructor(
        public readonly named: string,
        public readonly type: VaderType,
        public readonly source: Source
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
}

export interface GlobalParameterSource {
    kind: "GlobalParameterSource";
}

type Source =
    | FunctionParameterSource
    | LocalVariableSource
    | GlobalParameterSource
    | GlobalFunctionSource;

export class Scope {
    private namedVariables = new Map<string, Ref>();
    public readonly depth: number;
    #parent?: Scope

    constructor(parent?: Scope) {
        this.#parent = parent;
        this.depth = parent ? parent.depth + 1 : 0;
    }

    newGlobalVariable(type: VaderType, name: string) {
        assert(this.depth === 0, "Global variable must be declared in global scope");
        return this.newVariable(type, name, {
            kind: "GlobalParameterSource",
        })
    }

    newGlobalFunction(type: VaderType, name: string, options: Omit<GlobalFunctionSource, 'kind'>) {
        assert(this.depth === 0, "Global variable must be declared in global scope");
        return this.newVariable(type, name, {
            kind: "GlobalFunctionSource",
            ...options,
        })
    }

    newFunctionParameter(type: VaderType, index: number, name: string) {
        return this.newVariable(type, name, {
            kind: "FunctionParameterSource",
            index
        })
    }

    newLocalVariable(type: VaderType, index: number, name: string) {
        return this.newVariable(type, name, {
            kind: "LocalVariableSource",
            index
        })
    }

    private newVariable(type: VaderType, name: string, source: Source) {
        if (this.namedVariables.has(name)) {
            throw new Error(`Already declared variable ${name}`);
        }
        const ref = new Ref(name, type, source);
        this.namedVariables.set(name, ref);
        return ref;
    }

    lookupVariable(value: string): Ref {
        const ref = this.namedVariables.get(value);
        if (ref) {
            return ref;
        }
        if (this.#parent) {
            return this.#parent.lookupVariable(value);
        }
        throw new Error(`Unknown variable name ${value}`);
    }

    allVariables() {
        return [...this.namedVariables.values()]
    }
}

export const UnresolvedScope = new class extends Scope {
    lookupVariable(value: string): Ref {
        throw new Error(`Attempt to lookup for a variable with an unresolved scope`)
    }
}
