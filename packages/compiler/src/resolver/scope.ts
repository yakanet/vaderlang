import type {VaderType} from "../parser/types";
import assert from "node:assert";
import type {Decorator} from "../tokens/types.ts";

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

    newFunctionParameter(type: VaderType, index: number, name: string) {
        if (this.depth === 0) {
            throw new Error("Function parameter must be declared in a function scope");
        }
        if (this.depth === 1) {
            return this.newVariable(type, name, {
                kind: "FunctionParameterSource",
                index
            })
        }
        return this.#parent!.newVariable(type, name, {
            kind: "FunctionParameterSource",
            index
        })
    }

    newLocalVariable(type: VaderType, index: number, name: string) {
        if (this.depth === 0) {
            throw new Error("Function parameter must be declared in a function scope");
        }
        if (this.depth === 1) {
            return this.newVariable(type, name, {
                kind: "LocalVariableSource",
                index
            })
        }
        return this.#parent!.newVariable(type, name, {
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

    allFunctionLevelVariable(): Ref[] {
        if (this.depth === 0 || this.depth === 1) {
            return [...this.namedVariables.values()]
        }
        return this.#parent!.allFunctionLevelVariable();
    }
}

class _UnresolvedScope extends Scope {
    override lookupVariable(_value: string): Ref {
        throw new Error(`Attempt to lookup for a variable with an unresolved scope`)
    }
}

export const UnresolvedScope = new _UnresolvedScope();