import type {Decorator} from "../tokens/types.ts";

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
    properties: (ArrayIndexExpression | IdentifierExpression)[]
}

export type ArrayDeclarationExpression = BasicStatement & {
    kind: 'ArrayDeclarationExpression',
    type: ArrayVaderType,
    value?: Expression[],
}

export type ArrayIndexExpression = BasicStatement & {
    kind: 'ArrayIndexExpression',
    type: VaderType,
    index: Expression
}

export type VaderType =
    | PrimitiveVaderType
    | ArrayVaderType
    | StructVaderType
    | FunctionVaderType
    | UnknownType;

interface PrimitiveVaderType {
    kind: 'primitive'
    name: string,
    signed: boolean
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
            const length = vaderType.length;
            if (!length) {
                return `${typeToString(vaderType.type)}[?]`;
            }
            if (length.kind === 'NumberExpression') {
                return `${typeToString(vaderType.type)}[${length.value}]`;
            }
            return `${typeToString(vaderType.type)}[_]`
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
            const c = b as PrimitiveVaderType;
            return c.name === a.name;
        }
    }
}

export const BasicVaderType = {
    unknown: {name: 'UNKNOWN', kind: 'unknown'},
    ptr: {name: 'u32', kind: 'primitive', signed: false},
    u8: {name: 'u8', kind: 'primitive', signed: false},
    u32: {name: 'u32', kind: 'primitive', signed: false},
    u64: {name: 'u64', kind: 'primitive', signed: false},
    u16: {name: 'u16', kind: 'primitive', signed: false},
    f32: {name: 'f32', kind: 'primitive', signed: false},
    f64: {name: 'f64', kind: 'primitive', signed: false},
    boolean: {name: 'boolean', kind: 'primitive', signed: false},
    void: {name: 'void', kind: 'primitive', signed: false},
    string: {name: 'string', kind: 'primitive', signed: false},
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
