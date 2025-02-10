import type {Scope} from "../resolver/scope.ts";

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

export type ConditionalExpression = BasicStatement & {
    kind: 'ConditionalExpression'
    type: VaderType,
    branches: {
        condition: Expression,
        body: Statement[]
    }[];
    elseBody?: Statement[];
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
