export type Program = {
    kind: 'Program',
    body: Statement[],
    mainMethod: string | undefined;
}

export type ReturnStatement = {
    kind: 'ReturnStatement',
    expression: Expression
}

export type BinaryExpression = {
    kind: 'BinaryExpression',
    type: VaderType
    lhs: Expression,
    operator: string,
    rhs: Expression
}

export type NumberExpression = {
    kind: 'NumberExpression',
    type: VaderType,
    value: number
}

export type StringExpression = {
    kind: 'StringExpression',
    type: VaderType
    value: string
}

export type CallExpression = {
    kind: 'CallExpression',
    type: VaderType
    functionName: string,
    parameters: Expression[],
}

export type VariableExpression = {
    kind: 'VariableExpression',
    type: VaderType
    value: string
}

export type VariableDeclarationStatement = {
    kind: 'VariableDeclarationStatement',
    name: string,
    type: VaderType
    isConstant: boolean,
    value?: Expression
}

export type ConditionalExpression = {
    kind: 'ConditionalExpression'
    type: VaderType,
    branches: {
        condition: Expression,
        body: Statement[]
    }[];
    elseBody?: Statement[];
}

export type FunctionDeclaration = {
    kind: 'FunctionDeclaration',
    name: string,
    parameters: ({ name: string; type: VaderType })[],
    returnType: VaderType,
    body: Statement[]
}
export type StructStatement = {
    kind: 'StructStatement',
    name: string;
    definition: ({
        attributeName: string;
        typeName: VaderType;
    })[]
}

export type ForStatement = {
    kind: 'ForStatement',
    initialization: Statement,
    condition: Expression,
    iteration: Statement,
    body: Statement[],
}


export type VariableAssignmentStatement = {
    kind: 'VariableAssignmentStatement',
    identifier: string,
    value: Expression
}

export interface VaderType {
    name: string,
    array?: { arrayLength?: number }
}

export const BasicVaderType = {
    unknown: {name: 'UNKNOWN'},
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
    | ForStatement;
