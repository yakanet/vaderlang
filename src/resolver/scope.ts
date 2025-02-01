import type { VaderType } from "../parser/types";

export class Ref {
  constructor(
    public readonly named: string,
    public readonly type: VaderType,
    public readonly source: Source
  ) {}
}

interface FunctionParameterSource {
  kind: "FunctionParameterSource";
  index: number;
}

interface LocalParameterSource {
  kind: "LocalParameterSource";
}

type Source = FunctionParameterSource | LocalParameterSource;

export class Scope {
  private namedVariables = new Map<string, Ref>();
  public readonly depth: number;

  constructor(private parent?: Scope) {
    this.depth = parent ? parent.depth + 1 : 0;
  }

  newVariable(type: VaderType, name: string, source: Source) {
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
    if (this.parent) {
      return this.parent.lookupVariable(value);
    }
    throw new Error(`Unknown variable name ${value}`);
  }
}
