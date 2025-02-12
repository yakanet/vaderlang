import {Scope} from "./scope";
import {
    BasicVaderType,
    type Expression,
    type FunctionDeclaration,
    type Program,
    type ReturnStatement,
    type Statement,
    type VaderType,
} from "../parser/types";

export function resolve(program: Program): Program {
    const scope = new Scope();
    const body = program.body.map((statement) =>
        resolveStatement(statement, scope)
    );
    return {
        ...program,
        body,
        scope,
    };
}

function resolveStatement(
    statement: Statement,
    scope: Scope
): Statement {
    switch (statement.kind) {
        case "FunctionDeclaration":
            return resolveFunctionDeclaration(statement, scope);
        case "ReturnStatement":
            return {
                ...statement,
                expression: resolveExpression(statement.expression, scope),
                scope,
            } satisfies ReturnStatement;
        case "VariableDeclarationStatement": {
            const value = statement.value
                ? resolveExpression(statement.value, scope)
                : undefined;
            const type =
                statement.type !== BasicVaderType.unknown
                    ? statement.type
                    : value?.type ?? BasicVaderType.unknown;
            // TODO need to check if we can cast the number with the range (ex: u32 should be between 0..2^32−1)
            if (value && value.type !== type) {
                value.type = type;
            }
            if (scope.depth === 0) {
                scope.newGlobalVariable(type, statement.name);
            } else {
                scope.newLocalVariable(type, scope.allVariables().filter(v => v.source.kind !== 'GlobalParameterSource').length, statement.name);
            }
            //console.log("declare var " + statement.name, statement.type, value?.type, type);
            return {
                ...statement,
                type,
                value,
                scope,
            };
        }
        case 'ConditionalStatement': {
            return {
                ...statement,
                condition: resolveExpression(statement.condition, scope),
                type: BasicVaderType.void,
                ifBody: statement.ifBody.map(b => resolveStatement(b, scope)),
                elseBody: statement.elseBody?.map(b => resolveStatement(b, scope)),
                scope
            }
        }
        case "VariableAssignmentStatement": {
            const res = resolveExpression(statement.value, scope);
            // TODO: Should check if the variable is constant or not
            return {
                ...statement,
                value: res,
                scope,
            };
        }
        case "StructStatement":
        case "ForStatement":
            throw new Error("unimplemented");
        case "Program":
            throw new Error("unreachable");
    }
    return resolveExpression(statement, scope);
}

function resolveFunctionDeclaration(
    statement: FunctionDeclaration,
    scope: Scope
): FunctionDeclaration {
    const functionScope = new Scope(scope);
    let i = 0;
    for (const param of statement.parameters) {
        functionScope.newFunctionParameter(param.type, i++, param.name);
    }
    const body = statement.body.map((stmt) =>
        resolveStatement(stmt, functionScope)
    );
    scope.newGlobalFunction(
        BasicVaderType.function,
        statement.name,
        {
            decorators: statement.decorators,
            parameters: statement.parameters.map(p => p.type),
            returnType: statement.returnType,
        }
    );
    return {
        ...statement,
        body,
        scope,
    };
}

function resolveExpression(
    expression: Expression,
    scope: Scope
): Expression {
    switch (expression.kind) {
        case "BinaryExpression": {
            const lhs = resolveExpression(expression.lhs, scope)
            const rhs = resolveExpression(expression.rhs, scope)
            return {
                ...expression,
                type: lhs.type !== BasicVaderType.unknown ? lhs.type : rhs.type, // TODO typechecker need to check left and right type
                lhs,
                rhs,
                scope,
            };
        }
        case "CallExpression": {
            const resolved = scope.lookupVariable(expression.functionName);
            const parameters = expression.parameters.map((param) =>
                resolveExpression(param, scope)
            );
            if (resolved.source.kind !== 'GlobalFunctionSource') {
                throw new Error(`Only function can be call, here try to call a ${resolved.source.kind}`);
            }

            return {
                ...expression,
                kind: 'CallExpression',
                parameters,
                type: resolved.source.returnType,
                scope,
            };

        }
        case 'ConditionalReturnExpression': {
            const value = resolveExpression(expression.expression, scope);
            return {
                ...expression,
                type: value.type,
                scope
            }
        }
        case 'VariableExpression': {
            const variable = scope.lookupVariable(expression.value)
            return {
                ...expression,
                type: variable.type,
                scope
            }
        }
        case 'ConditionalExpression': {
            const ifBody = expression.ifBody.map(b => resolveStatement(b, scope));
            const elseBody = expression.elseBody?.map(b => resolveStatement(b, scope))
            const returnIf = ifBody.filter(b => b.kind === 'ConditionalReturnExpression');
            const returnElse = elseBody?.filter(b => b.kind === 'ConditionalReturnExpression');
            if (!returnIf.length) {
                throw new Error(`Missing return expression in if block at ${expression.location}`);
            }
            if (returnElse && !returnElse.length) {
                throw new Error(`Missing return expression in else block at ${expression.location}`);
            }
            const returnsTypes = [...returnIf, ...(returnElse ?? [])].map(c => c.type)
                .reduce((acc, type) => {
                    return acc.add(type);
                }, new Set<VaderType>());
            if (returnsTypes.size !== 1) {
                throw new Error(`Return type mismatch in conditional expression ${[...returnsTypes]} at ${expression.location}`);
            }
            return {
                ...expression,
                condition: resolveExpression(expression.condition, scope),
                type: [...returnsTypes][0],
                ifBody,
                elseBody,
                scope
            }
        }
        default:
            return {...expression, scope};
    }
}
