import type {Decorator, Token} from "../tokens/types.ts";

type BasicStatement = {
    location: {
        start: number
        end: number
        file: string
    }
}

export type Program = BasicStatement & {
    kind: 'Program',
    body: Statement[],
}

export type ReturnStatement = BasicStatement & {
    kind: 'ReturnStatement',
    expression: Expression
}

export type VariableDeclarationStatement = BasicStatement & {
    kind: 'VariableDeclarationStatement',
    name: string
    type: VaderType
    isConstant: boolean
    value?: Expression
}

export type ConditionalStatement = BasicStatement & {
    kind: 'ConditionalStatement'
    type: VaderType,
    condition: Expression,
    ifBody: Statement[]
    elseBody?: Statement[];
}

export type VariableAssignmentStatement = BasicStatement & {
    kind: 'VariableAssignmentStatement'
    identifier: Expression
    value: Expression
}

export type ForStatement = BasicStatement & {
    kind: 'ForStatement',
    initialization: Statement,
    condition: Expression,
    iteration: Statement,
    body: Statement[],
}


export type BinaryExpression = BasicStatement & {
    kind: 'BinaryExpression',
    type: VaderType
    lhs: Expression,
    operator: string,
    rhs: Expression,
}

export type NumberExpression = BasicStatement & {
    kind: 'NumberExpression',
    type: VaderType,
    value: number,
}

export type StringExpression = BasicStatement & {
    kind: 'StringExpression',
    type: VaderType
    value: string
}

export type CallExpression = BasicStatement & {
    kind: 'CallExpression',
    type: VaderType
    functionName: string,
    parameters: Expression[],
}

export type IdentifierExpression = BasicStatement & {
    kind: 'IdentifierExpression'
    type: VaderType
    identifier: string
}


export type ConditionalExpression = Omit<ConditionalStatement, 'kind'> & {
    kind: 'ConditionalExpression'
}

export type FunctionDeclarationExpression = BasicStatement & {
    kind: 'FunctionDeclarationExpression',
    type: FunctionVaderType,
    body: Statement[]
}
export type StructDeclarationExpression = BasicStatement & {
    kind: 'StructDeclarationExpression',
    type: StructVaderType;
}

export type StructInstantiationExpression = BasicStatement & {
    kind: 'StructInstantiationExpression',
    parameters: {
        name?: string,
        value: Expression
    }[],
    type: VaderType,
    structName: string,
}

export type DotExpression = BasicStatement & {
    kind: 'DotExpression',
    type: VaderType,
    identifier: Expression,
    properties: {
        name: string, // FIXME Must be an expression not a string
        type: VaderType,
        location: Token['location']
    }[]
}

export type ArrayDeclarationExpression = BasicStatement & {
    kind: 'ArrayDeclarationExpression',
    type: ArrayVaderType,
    value?: Expression[],
}

export type ArrayIndexExpression = BasicStatement & {
    kind: 'ArrayIndexExpression',
    type: VaderType,
    identifier: Expression,
    indexes: Expression[]
}

export type VaderType =
    | RawVaderType
    | ArrayVaderType
    | StructVaderType
    | FunctionVaderType
    | UnknownType;

interface RawVaderType {
    kind: 'primitive'
    name: string,
}

export interface StructVaderType {
    kind: 'struct'
    parameters: {
        name: string,
        type: VaderType
    }[]
}

export interface ArrayVaderType {
    kind: 'array'
    length?: Expression,
    type: VaderType,
    dimension: number
}

export interface FunctionVaderType {
    kind: 'function'
    parameters: {
        name: string,
        type: VaderType
    }[],
    decorators: Decorator[]
    returnType: VaderType,
}

interface UnknownType {
    kind: 'unknown'
    name: string,
}

export function typeToString(vaderType: VaderType): string {
    switch (vaderType.kind) {
        case 'struct': {
            return `struct {${vaderType.parameters.map(t => typeToString(t.type))}`
        }
        case 'function': {
            return `function (${vaderType.parameters.map(t => typeToString(t.type))}) -> ${typeToString(vaderType.returnType)}`
        }
        case 'array': {
            return `${typeToString(vaderType.type)}[${vaderType.length === undefined ? '' : vaderType.length}]`
        }
        case 'primitive': {
            return vaderType.name
        }
        case 'unknown': {
            return 'UNKNOWN'
        }
    }
}

export function isTypeEquals<T extends VaderType>(a: T, b: T): boolean {
    if (a.kind !== b.kind) {
        return false
    }
    switch (a.kind) {
        case 'unknown': {
            return a.kind === b.kind;
        }
        case 'function': {
            const c = b as FunctionVaderType;
            if (a.parameters.length !== c.parameters.length) {
                return false
            }
            for (let i = 0; i < c.parameters.length; i++) {
                if (!isTypeEquals(a.parameters[i].type, c.parameters[i].type)) {
                    return false
                }
            }
            return isTypeEquals(a.returnType, c.returnType);
        }
        case 'struct': {
            const c = b as StructVaderType
            if (a.parameters.length !== c.parameters.length) {
                return false
            }
            for (let i = 0; i < c.parameters.length; i++) {
                if (!isTypeEquals(a.parameters[i].type, c.parameters[i].type)) {
                    return false
                }
            }
            return true;
        }
        case 'array': {
            const c = b as ArrayVaderType;
            if (!isTypeEquals(a.type, c.type)) {
                return false
            }
            if (a.length === undefined || c.length === undefined) {
                return true;
            }
            return a.length === c.length;
        }
        case 'primitive': {
            const c = b as RawVaderType;
            return c.name === a.name;
        }
    }
}

export const BasicVaderType = {
    unknown: {name: 'UNKNOWN', kind: 'unknown'},
    ptr: {name: 'u32', kind: 'primitive'},
    u8: {name: 'u8', kind: 'primitive'},
    u32: {name: 'u32', kind: 'primitive'},
    u64: {name: 'u64', kind: 'primitive'},
    u16: {name: 'u16', kind: 'primitive'},
    f32: {name: 'f32', kind: 'primitive'},
    f64: {name: 'f64', kind: 'primitive'},
    boolean: {name: 'boolean', kind: 'primitive'},
    void: {name: 'void', kind: 'primitive'},
    string: {name: 'string', kind: 'primitive'},
} as const satisfies Record<string, VaderType>;


export type Expression =
    | NumberExpression
    | StringExpression
    | IdentifierExpression
    | BinaryExpression
    | ConditionalExpression
    | CallExpression
    | FunctionDeclarationExpression
    | StructDeclarationExpression
    | StructInstantiationExpression
    | DotExpression
    | ArrayDeclarationExpression
    | ArrayIndexExpression

export type Statement =
    | Program
    | ReturnStatement
    | ConditionalStatement
    | Expression
    | VariableDeclarationStatement
    | VariableAssignmentStatement
    | ForStatement
    ;
