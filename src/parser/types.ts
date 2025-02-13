import type {Scope} from "../resolver/scope.ts";
import type {Decorator, Token} from "../tokens/types.ts";

type BasicStatement = {
    scope: Scope;
    location: {
        start: number
        end: number
        file: string
    }
}

export type Program = BasicStatement & {
    kind: 'Program',
    body: Statement[],
    mainMethod: string | undefined;
}

export type ReturnStatement = BasicStatement & {
    kind: 'ReturnStatement',
    expression: Expression
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

export type VariableExpression = BasicStatement & {
    kind: 'VariableExpression',
    type: VaderType
    value: string
}

export type VariableDeclarationStatement = BasicStatement & {
    kind: 'VariableDeclarationStatement',
    name: string,
    type: VaderType
    isConstant: boolean,
    value?: Expression
}

export type ConditionalStatement = BasicStatement & {
    kind: 'ConditionalStatement'
    type: VaderType,
    condition: Expression,
    ifBody: Statement[]
    elseBody?: Statement[];
}

export type ConditionalExpression = Omit<ConditionalStatement, 'kind'> & {
    kind: 'ConditionalExpression'
}

export type FunctionDeclaration = BasicStatement & {
    kind: 'FunctionDeclaration',
    name: string,
    decorators: Decorator[],
    parameters: ({ name: string; type: VaderType })[],
    returnType: VaderType,
    body: Statement[]
}
export type StructStatement = BasicStatement & {
    kind: 'StructStatement',
    name: string;
    definition: ({
        attributeName: string;
        typeName: VaderType;
    })[]
}

export type ForStatement = BasicStatement & {
    kind: 'ForStatement',
    initialization: Statement,
    condition: Expression,
    iteration: Statement,
    body: Statement[],
}


export type VariableAssignmentStatement = BasicStatement & {
    kind: 'VariableAssignmentStatement',
    identifier: string,
    value: Expression
}

export type StructInstantiationExpression = BasicStatement & {
    kind: 'StructInstantiationExpression',
    parameters: Expression[],
    type: VaderType,
    structName: string,
}

export type DotExpression = BasicStatement & {
    kind: 'DotExpression',
    type: VaderType,
    properties: {
        name: string,
        type: VaderType,
        location: Token['location']
    }[],
}

export type ArrayDeclarationExpression = BasicStatement & {
    kind: 'ArrayDeclarationExpression',
    type: ArrayVaderType,
    value?: Expression[],
}


export type ArrayIndexExpression  = BasicStatement & {
    kind: 'ArrayIndexExpression',
    type: VaderType,
    identifier: string,
    indexes: Expression[]
}

export type VaderType = RawVaderType | ArrayVaderType | StructVaderType | UnknownType

interface RawVaderType {
    kind: 'primitive'
    name: string,
}

interface StructVaderType {
    kind: 'struct'
    name: string,
    parameters: {
        name: string,
        type: VaderType
    }[]
}

export interface ArrayVaderType {
    kind: 'array'
    size: number,
    type: VaderType,
}

interface UnknownType {
    kind: 'unknown'
    name: string,
}

export function isTypeEquals<T extends VaderType>(a: T, b: T): boolean {
    if (a.kind !== b.kind) {
        return false
    }
    switch (a.kind) {
        case 'unknown': {
            return a.kind === b.kind;
        }
        case 'struct': {
            const c = b as StructVaderType
            if (a.name !== c.name) {
                return false
            }
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
            return a.size === c.size;
        }
        case 'primitive': {
            const c = b as RawVaderType;
            return c.name === a.name;
        }
    }
}

export const BasicVaderType = {
    unknown: {name: 'UNKNOWN', kind: 'unknown'},
    function: {name: 'Function', kind: 'primitive'},
    ptr: {name: 'u32', kind: 'primitive'},
    u8: {name: 'u8', kind: 'primitive'},
    u32: {name: 'u32', kind: 'primitive'},
    u64: {name: 'u64', kind: 'primitive'},
    u16: {name: 'u16', kind: 'primitive'},
    f32: {name: 'f32', kind: 'primitive'},
    f64: {name: 'f64', kind: 'primitive'},
    void: {name: 'void', kind: 'primitive'},
    string: {name: 'string', kind: 'primitive'},
} as const satisfies Record<string, VaderType>;


export type Expression =
    | NumberExpression
    | StringExpression
    | VariableExpression
    | BinaryExpression
    | ConditionalExpression
    | CallExpression
    | StructInstantiationExpression
    | DotExpression
    | ArrayDeclarationExpression
    | ArrayIndexExpression

export type Statement =
    | Program
    | ReturnStatement
    | FunctionDeclaration
    | ConditionalStatement
    | Expression
    | StructStatement
    | VariableDeclarationStatement
    | VariableAssignmentStatement
    | ForStatement
    ;
