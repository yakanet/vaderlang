export type Program = {
    type: 'Program',
    body: Statement[],
    mainMethod: string | undefined;
}

export type ReturnStatement = {
    type: 'ReturnStatement',
    expression: Expression
}

export type BinaryExpression = {
    type: 'BinaryExpression',
    lhs: Expression,
    operator: string,
    rhs: Expression
}

export type NumberExpression = {
    type: 'NumberExpression',
    value: number
}

export type StringExpression = {
    type: 'StringExpression',
    value: string
}

export type CallExpression = {
    type: 'CallExpression',
    functionName: string,
    parameters: Expression[],
}

export type VariableExpression = {
    type: 'VariableExpression',
    value: string[]
}

export type VariableDeclarationStatement = {
    type: 'VariableDeclarationStatement',
    name: string,
    variableType?: VaderType,
    isConstant: boolean,
    value?: Expression
}

export type ConditionalExpression = {
    type: 'ConditionalExpression'
    branches: {
        condition: Expression,
        body: Statement[]
    }[];
    elseBody?: Statement[];
}

export type FunctionDeclaration = {
    type: 'FunctionDeclaration',
    name: string,
    parameters: ({ name: string; type: VaderType })[],
    returnType: VaderType,
    body: Statement[]
}
export type StructStatement = {
    type: 'StructStatement',
    name: string;
    definition: ({
        attributeName: string;
        typeName: VaderType;
    })[]
}

export type ForStatement = {
    type: 'ForStatement',
    initialization: Statement,
    condition: Expression,
    iteration: Statement,
    body: Statement[],
}


export type VariableAssignmentStatement = {
    type: 'VariableAssignment',
    identifier: string,
    value: Expression
}

export interface VaderType {
    name: string,
    array?: {arrayLenght?: number}
}


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
