export type Program = {
    type: 'Program',
    body: Statement[]
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
    value: string
}

export type VariableDeclarationStatement = {
    type: 'VariableDeclarationStatement',
    name: string,
    variableType: string,
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
    parameters: ({ name: string; type: string })[],
    returnType: string,
    body: Statement[]
}
export type StructStatement = {
    type: 'StructStatement',
    name: string;
    definition: ({
        attributeName: string;
        typeName: string;
    })[]
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
    | VariableDeclarationStatement;
