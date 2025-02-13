import {Scope} from "./scope";
import {
    BasicVaderType,
    type Expression,
    type ForStatement,
    type FunctionDeclarationExpression,
    isTypeEquals,
    type Program,
    type ReturnStatement,
    type Statement,
    type VariableDeclarationStatement,
} from "../parser/types";
import assert from "node:assert";

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
        case "Program":
            throw new Error("unreachable");
        case "ReturnStatement":
            return {
                ...statement,
                expression: resolveExpression(statement.expression, scope),
                scope,
            } satisfies ReturnStatement;

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
        case "VariableDeclarationStatement":
            return resolveVariableDeclaration(statement, scope);
        case "VariableAssignmentStatement": {
            const res = resolveExpression(statement.value, scope);
            // TODO: Should check if the variable is constant or not
            return {
                ...statement,
                value: res,
                scope,
            };
        }
        case "ForStatement":
            const initialization = resolveStatement(statement.initialization, scope)
            const cloneScope = new Scope(scope)
            return {
                ...statement,
                kind: "ForStatement",
                initialization,
                condition: resolveExpression(statement.condition, cloneScope),
                iteration: resolveStatement(statement.iteration, cloneScope),
                body: statement.body.map(b => resolveStatement(b, cloneScope)),
                scope: cloneScope
            } satisfies ForStatement
    }
    return resolveExpression(statement, scope);
}

function resolveFunctionDeclaration(
    statement: FunctionDeclarationExpression,
    scope: Scope
): FunctionDeclarationExpression {
    const functionScope = new Scope(scope);
    let i = 0;
    for (const parameter of statement.type.parameters) {
        while (parameter.type.kind === 'unknown') {
            parameter.type = scope.lookupVariable(parameter.type.name).type;
        }
        functionScope.newFunctionParameter(parameter.type, i++, parameter.name);
    }
    const body = statement.body.map((stmt) =>
        resolveStatement(stmt, functionScope)
    );
    return {
        ...statement,
        body,
        scope,
    };
}

function resolveVariableDeclaration(
    statement: VariableDeclarationStatement,
    scope: Scope
): Statement {
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
        scope.newLocalVariable(type, scope.allFunctionLevelVariable().filter(v => v.source.kind !== 'GlobalParameterSource').length, statement.name);
    }
    if (value && value.kind === 'ConditionalExpression') {
        value.kind = 'ConditionalStatement' as any;
        let queue = [value.ifBody, value.elseBody].filter(b => b);
        while (true) {
            const oldValue = queue.pop();
            if (!oldValue) {
                break
            }
            const oldStatement = oldValue.at(-1) as Statement;
            if (!oldStatement) {
                continue;
            }
            if (oldStatement.kind === 'ConditionalStatement' || oldStatement.kind === 'ConditionalExpression') {
                oldStatement.kind = 'ConditionalStatement';
                queue.push(oldStatement.ifBody)
                if (oldStatement.elseBody) {
                    queue.push(oldStatement.elseBody)
                }
            } else {
                oldValue[oldValue.length - 1] = {
                    kind: 'VariableAssignmentStatement',
                    value: oldStatement as Expression,
                    identifier: statement.name,
                    location: statement.location,
                    scope,
                }
            }
        }
        return value
    }
    return {
        ...statement,
        type,
        value,
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
        case "FunctionDeclarationExpression":
            return resolveFunctionDeclaration(expression, scope);
        case "CallExpression": {
            const resolved = scope.lookupVariable(expression.functionName);
            const parameters = expression.parameters.map((param) =>
                resolveExpression(param, scope)
            );
            if (resolved.type.kind !== 'function') {
                throw new Error(`Only function can be call, here try to call a ${resolved.source.kind}`);
            }

            return {
                ...expression,
                kind: 'CallExpression',
                parameters,
                type: resolved.type.returnType,
                scope,
            };

        }
        case "StructDeclarationExpression": {
            assert(expression.type.kind === 'struct');
            for (const parameter of expression.type.parameters) {
                if (parameter.type.kind === 'unknown') {
                    parameter.type = scope.lookupVariable(parameter.type.name).type
                }
                //type.parameters.push({name: parameter.name, type: parameter.type});
            }
            return {
                ...expression,
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

        case 'ArrayIndexExpression': {
            const resolved = scope.lookupVariable(expression.identifier)
            return {
                ...expression,
                type: resolved.type,
                indexes: expression.indexes.map(i => resolveExpression(i, scope)),
                scope
            }
        }
        case 'ArrayDeclarationExpression': {
            return {
                ...expression,
                value: expression.value?.map(i => resolveExpression(i, scope)),
                scope
            }
        }
        case 'StructInstantiationExpression': {
            const resolved = scope.lookupVariable(expression.structName)
            if (resolved.type.kind !== 'struct') {
                throw new Error(`Trying to instantiate a struct, but ${resolved.named} is not a struct`);
            }
            if (resolved.type.parameters.length !== expression.parameters.length) {
                throw new Error(`Wrong number of arguments (expected ${resolved.type.parameters.length}, got ${expression.parameters.length})`);
            }
            for (let i = 0; i < resolved.type.parameters.length; i += 1) {
                expression.parameters[i] = resolveExpression(expression.parameters[i], scope);
                if (!isTypeEquals(expression.parameters[i].type, resolved.type.parameters[i].type)) {
                    throw new Error(`Wrong type for parameter ${resolved.type.parameters[i].name} (expected ${resolved.type.parameters[i].type}, got ${expression.parameters[i].type})`);
                }
            }
            return {
                ...expression,
                type: resolved.type,
                scope,
            }
        }
        case 'DotExpression': {
            let resolved = scope.lookupVariable(expression.properties[0].name);
            while (resolved.type.kind === 'unknown') {
                resolved = scope.lookupVariable(resolved.type.name);
            }
            expression.properties[0].type = resolved.type;
            for (let i = 1; i < expression.properties.length; i++) {
                const previousType = expression.properties[i - 1].type;
                if (previousType.kind === 'struct') {
                    const resolvedType = previousType.parameters.find(p => p.name === expression.properties[i].name)
                    if (!resolvedType) {
                        throw new Error(`Unresolved property ${expression.properties[i].name}`);
                    }
                    expression.properties[i].type = resolvedType.type;
                } else {
                    throw new Error(`Unimplemented other case of DotExpression: ${resolved.type.kind}`);
                }
            }
            return {
                ...expression,
                type: expression.properties[expression.properties.length - 1].type,
                scope
            }
        }
        case 'ConditionalExpression': {
            const ifBody = expression.ifBody.map(b => resolveStatement(b, scope));
            const elseBody = expression.elseBody?.map(b => resolveStatement(b, scope))
            const returnIf = ifBody.at(-1) as Expression;
            const returnElse = elseBody?.at(-1) as Expression | undefined;
            if (!returnIf?.kind.endsWith('Expression')) {
                throw new Error(`Missing return expression in if block at ${expression.location}`);
            }
            if (returnElse && returnIf.type !== returnElse.type) {
                throw new Error(`Return type mismatch in conditional expression ${JSON.stringify([returnIf.type, returnElse.type])} at ${expression.location.start}`);
            }
            return {
                ...expression,
                condition: resolveExpression(expression.condition, scope),
                type: returnIf.type,
                ifBody,
                elseBody,
                scope
            }
        }
        default:
            return {...expression, scope};
    }
}
