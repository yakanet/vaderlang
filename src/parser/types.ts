import type {Scope} from "../resolver/scope.ts";

export type Program = {
    kind: 'Program',
    body: Statement[],
    mainMethod: string | undefined;
    scope: Scope
}

export type ReturnStatement = {
    kind: 'ReturnStatement',
    expression: Expression
    scope: Scope
}

export type BinaryExpression = {
    kind: 'BinaryExpression',
    type: VaderType
    lhs: Expression,
    operator: string,
    rhs: Expression,
    scope: Scope
}

export type NumberExpression = {
    kind: 'NumberExpression',
    type: VaderType,
    value: number,
    scope: Scope
}

export type StringExpression = {
    kind: 'StringExpression',
    type: VaderType
    value: string
    scope: Scope
}

export type CallExpression = {
    kind: 'CallExpression',
    type: VaderType
    functionName: string,
    parameters: Expression[],
    scope: Scope
}

export type VariableExpression = {
    kind: 'VariableExpression',
    type: VaderType
    value: string
    scope: Scope
}

export type VariableDeclarationStatement = {
    kind: 'VariableDeclarationStatement',
    name: string,
    type: VaderType
    isConstant: boolean,
    value?: Expression
    scope: Scope
}

export type ConditionalExpression = {
    kind: 'ConditionalExpression'
    type: VaderType,
    branches: {
        condition: Expression,
        body: Statement[]
    }[];
    elseBody?: Statement[];
    scope: Scope
}

export type FunctionDeclaration = {
    kind: 'FunctionDeclaration',
    name: string,
    decorators: Decorator[],
    parameters: ({ name: string; type: VaderType })[],
    returnType: VaderType,
    body: Statement[]
    scope: Scope
}
export type StructStatement = {
    kind: 'StructStatement',
    name: string;
    definition: ({
        attributeName: string;
        typeName: VaderType;
    })[]
    scope: Scope
}

export type ForStatement = {
    kind: 'ForStatement',
    initialization: Statement,
    condition: Expression,
    iteration: Statement,
    body: Statement[],
    scope: Scope
}


export type VariableAssignmentStatement = {
    kind: 'VariableAssignmentStatement',
    identifier: string,
    value: Expression
    scope: Scope
}

export type Decorator = 'intrinsic'

export interface VaderType {
    name: string,
    array?: { arrayLength?: number }
}

export const BasicVaderType = {
    unknown: {name: 'UNKNOWN'},
    function: {name: 'Function'},
    ptr: {name: 'u32'},
    u8: {name: 'u8'},
    u32: {name: 'u32'},
    u64: {name: 'u64'},
    u16: {name: 'u16'},
    f32: {name: 'f32'},
    f64: {name: 'f64'},
    void: {name: 'void'},
} as const satisfies Record<string, VaderType>;


export type Expression =
    | NumberExpression
    | StringExpression
    | VariableExpression
    | BinaryExpression
    | ConditionalExpression
    | CallExpression

export type Statement =
    | Program
    | ReturnStatement
    | FunctionDeclaration
    | Expression
    | StructStatement
    | VariableDeclarationStatement
    | VariableAssignmentStatement
    | ForStatement
    ;
