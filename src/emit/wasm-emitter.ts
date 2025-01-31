import type {
  Expression,
  FunctionDeclaration,
  Program,
  Statement,
  StringExpression,
} from "../parser/types";
import binaryen from "binaryen";
import { Scope, Ref } from "./scope.ts";
import { addWasiFunction } from "./wasi.ts";
import fs from "node:fs";
import assert from "node:assert";

const encoder = new TextEncoder();

export class WasmEmitter {
  private strings = new Set<string>();
  private functions = new Map<string, FunctionDeclaration>();
  private module: binaryen.Module;

  constructor() {
    this.module = new binaryen.Module();
    this.module.setMemory(1, -1);
    addWasiFunction(this.module);
  }

  emit(program: Program, outputPath: string) {
    const scope = new Scope();
    for (const statement of program.body) {
      this.emitTopLevelStatement(statement, scope);
    }

    let offset = 0;
    this.module.setMemory(1, -1, "memory", [
      ...this.strings.values().map((v) => {
        const data = encoder.encode(v + "\0");
        offset += data.length;
        return {
          data,
          offset,
        };
      }),
    ]);
    this.emitMainMethod(program);
    assert.ok(this.module.validate());
    this.module.optimize();
    console.log(this.module.emitText());
    fs.mkdirSync(`${outputPath}/wasm`, { recursive: true });

    fs.writeFileSync(`${outputPath}/wasm/app.wasm`, this.module.emitBinary());
  }

  emitMainMethod(program: Program) {
    if(program.mainMethod) {
        const funct = this.module.addFunction('__start__', binaryen.createType([]), binaryen.none, [], this.module.block(null, [
            this.module.call('wasi_snapshot_preview1:proc_exit', [
                this.module.call(program.mainMethod, [], binaryen.i32)
            ], binaryen.none)
        ]));
        this.module.setStart(funct);
    }
  }

  emitTopLevelStatement(statement: Statement, scope: Scope) {
    switch (statement.type) {
      case "FunctionDeclaration": {
        const childScope = new Scope(scope);
        for (const p of statement.parameters) {
          scope.newVariable(p.type, p.name);
        }
        this.module.addFunction(
          statement.name,
          binaryen.createType(
            statement.parameters.map((t) => mapBinaryenType(t.type))
          ),
          mapBinaryenType(statement.returnType),
          [], //statement.parameters.map((t) => mapBinaryenType(t.type)),
          this.module.block(
            null,
            statement.body.map((stmt) => this.emitStatement(stmt, scope))
          )
        );

        //this.module.addFunctionExport(statement.name, statement.name);
        return;
      }
    }
    throw new Error(statement.type + " is not implemented yet");
  }
  emitStatement(stmt: Statement, scope: Scope): binaryen.ExpressionRef {
    switch (stmt.type) {
      case "ReturnStatement":
        return this.module.return(this.emitStatement(stmt.expression, scope));
      case "BinaryExpression": {
        if (stmt.operator === "+") {
          return this.module.i32.add(
            this.emitExpression(stmt.lhs, scope),
            this.emitExpression(stmt.rhs, scope)
          );
        }
        throw new Error(
          "BinaryExpression " + stmt.type + " is not implemented."
        );
      }

      case "CallExpression": {
        if (stmt.functionName === "printf") {
          const length = stmt.parameters[0];
          const offset = this.strings.values().reduce((acc, item) => {
            return acc + item.length;
          }, 0);
          this.strings.add((stmt.parameters[0] as StringExpression).value);
          return this.module.block(null, [
            // Store iovs
            this.module.i32.store(
              0,
              0,
              this.module.i32.const(40),
              this.module.i32.const(0)
            ), // Start of data (= *buf)
            this.module.i32.store(
              0,
              0,
              this.module.i32.const(44),
              this.module.i32.const(12)
            ), // Length of data (= buf_len)
            this.module.call(
              "wasi_snapshot_preview1:fd_write",
              [
                this.module.i32.const(1), // stdout = 1
                this.module.i32.const(40), // ptr of iovs
                this.module.i32.const(1), // number of iovs (could iovs is an array)
                this.module.i32.const(80), // where to store the returned error code
              ],
              binaryen.i32
            ),
          ]);
        }
        return this.module.call(
          stmt.functionName,
          stmt.parameters.map((p) => this.emitStatement(p, scope)),
          binaryen.i32 //mapBinaryenType(stmt.type)
        );
      }
    }
    return this.emitExpression(stmt, scope);
  }

  private emitExpression(
    expression: Statement,
    scope: Scope
  ): binaryen.ExpressionRef {
    switch (expression.type) {
      case "VariableExpression": {
        return this.module.local.get(0, binaryen.i32);
      }
      case "NumberExpression": {
        return this.module.i32.const(expression.value);
      }
    }

    throw new Error("Expression " + expression.type + " is not implemented.");
  }
}

function mapBinaryenType(t: string): binaryen.Type {
  switch (t) {
    case "w":
      return binaryen.i32;
  }
  throw new Error("Type mapping " + t + " is not implemented.");
}
