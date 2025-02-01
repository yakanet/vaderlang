import { Scope } from "./scope";
import type {
  Expression,
  ForStatement,
  FunctionDeclaration,
  Program,
  ReturnStatement,
  Statement,
} from "../parser/types";
import type { Resolved } from "./types";

export function resolve(program: Program): Resolved<Program> {
  const scope = new Scope();
  const body = program.body.map((statement) => {
    return resolveStatement(statement, scope);
  });
  return {
    ...program,
    body,
    scope,
  };
}

function resolveStatement(
  statement: Statement,
  scope: Scope
): Resolved<Statement> {
  switch (statement.type) {
    case "FunctionDeclaration":
      return resolveFunctionDeclaration(statement, scope);
    case "ReturnStatement":
      return {
        ...statement,
        expression: resolveExpression(statement.expression, scope),
        scope,
      } satisfies Resolved<ReturnStatement>;
    case "VariableDeclarationStatement": {
        const value = statement.value ? resolveExpression(statement.value, scope) : undefined
      // FIXME default type should be the resolved value type
      scope.newVariable(
        statement.variableType ?? { name: "u32" },
        statement.name,
        {
          kind: "LocalParameterSource",
        }
      );

      return {
        ...statement,
        value,
        scope,
      };
    }
    case "VariableAssignmentStatement": {
      const res = resolveExpression(statement.value, scope);
      scope.newVariable(
        { name: "f32" },
        statement.identifier,
        {
          kind: "LocalParameterSource",
        }
      );
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
): Resolved<FunctionDeclaration> {
  const functionScope = new Scope(scope);
  let i = 0;
  for (const param of statement.parameters) {
    functionScope.newVariable(param.type, param.name, {
      kind: "FunctionParameterSource",
      index: i++,
    });
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

function resolveExpression(
  expression: Expression,
  scope: Scope
): Resolved<Expression> {
  switch (expression.type) {
    case "BinaryExpression": {
      return {
        ...expression,
        lhs: resolveExpression(expression.lhs, scope),
        rhs: resolveExpression(expression.rhs, scope),
        scope,
      };
    }
    case "CallExpression": {
      const parameters = expression.parameters.map((param) =>
        resolveExpression(param, scope)
      );
      return {
        ...expression,
        parameters,
        scope,
      };
    }
    default:
      return { ...expression, scope };
  }
}
