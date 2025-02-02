import type {
  CallExpression,
  Program,
  Statement,
  StringExpression,
  VaderType,
} from "../parser/types";
import binaryen from "binaryen";
import { addWasiFunction } from "./wasi.ts";
import fs from "node:fs";
import assert from "node:assert";
import type { Resolved } from "../resolver/types.ts";

const encoder = new TextEncoder();

export class WasmEmitter {
  private strings = new Set<string>();
  private module = new binaryen.Module();

  constructor() {
    this.module.setMemory(1, -1);
    addWasiFunction(this.module);
  }

  emit(program: Resolved<Program>, outputDirectory: string) {
    for (const statement of program.body) {
      this.emitTopLevelStatement(statement);
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
    fs.mkdirSync(`${outputDirectory}/wasm`, { recursive: true });

    fs.writeFileSync(
      `${outputDirectory}/wasm/app.wasm`,
      this.module.emitBinary()
    );
  }

  emitMainMethod(program: Resolved<Program>) {
    if (!program.mainMethod) {
      return;
    }
    const resolved = program.scope.lookupVariable(program.mainMethod);
    if (resolved.type.name !== "u32") {
      return;
    }
    const funct = this.module.addFunction(
      "__start__",
      binaryen.createType([]),
      binaryen.none,
      [],
      this.module.block(null, [
        this.module.call(
          "wasi_snapshot_preview1:proc_exit",
          [this.module.call(program.mainMethod, [], binaryen.i32)],
          binaryen.none
        ),
      ])
    );
    this.module.setStart(funct);
  }

  emitTopLevelStatement(statement: Resolved<Statement>) {
    switch (statement.kind) {
      case "FunctionDeclaration": {
        this.module.addFunction(
          statement.name,
          binaryen.createType(
            statement.parameters.map((t) => mapBinaryenType(t.type))
          ),
          mapBinaryenType(statement.returnType),
          // TODO must declare here every local variable of the function
          [], //statement.parameters.map((t) => mapBinaryenType(t.type)),
          this.module.block(
            null,
            statement.body.map((stmt) => this.emitStatement(stmt))
          )
        );

        //this.module.addFunctionExport(statement.name, statement.name);
        return;
      }

      case "VariableDeclarationStatement": {
        const variableRef = statement.scope.lookupVariable(statement.name);
        if (statement.scope.depth === 0) {
          return this.module.addGlobal(
            statement.name,
            mapBinaryenType(variableRef.type),
            !statement.isConstant,
            this.emitExpression(statement.value!)
          );
        } else {
          throw new Error(`Unimplemented VariableDeclarationStatement case`);
        }
      }
    }
    throw new Error(statement.kind + " is not implemented yet");
  }

  emitStatement(stmt: Resolved<Statement>): binaryen.ExpressionRef {
    switch (stmt.kind) {
      case "ReturnStatement":
        return this.module.return(this.emitExpression(stmt.expression));

      case "CallExpression": {
        if (stmt.functionName === "printf") {
          return this.emitPrintf(stmt);
        }
        const resolved = stmt.scope.lookupVariable(stmt.functionName);
        return this.module.call(
          stmt.functionName,
          stmt.parameters.map((p) => this.emitStatement(p)),
          mapBinaryenType(resolved.type)
        );
      }

      case "VariableDeclarationStatement": {
        const scope = stmt.scope;
        if (scope.depth === 0) {
          return this.module.global.set(
            stmt.name,
            this.emitExpression(stmt.value!)
          );
        }
        throw new Error(
          "VariableDeclarationStatement is not implemented for " +
            JSON.stringify(stmt.type)
        );
      }

      case "VariableAssignmentStatement": {
        const scope = stmt.scope;
        const resolved = scope.lookupVariable(stmt.identifier);
        if (resolved.source.kind === "GlobalParameterSource") {
          return this.module.global.set(
            resolved.named,
            this.emitExpression(stmt.value)
          );
        }
        if (resolved.source.kind === "FunctionParameterSource") {
          return this.module.local.set(
            resolved.source.index,
            this.emitExpression(stmt.value)
          );
        }
        if (resolved.source.kind === "LocalParameterSource") {
          return this.module.local.set(0, this.emitExpression(stmt.value));
          //throw new Error(`Local param for local parameter is not implemented`);
        }
      }
    }
    return this.emitExpression(stmt);
  }

  private emitExpression(
    expression: Resolved<Statement>
  ): binaryen.ExpressionRef {
    switch (expression.kind) {
      case "VariableExpression": {
        debugger;
        const ref = expression.scope.lookupVariable(expression.value);
        const source = ref.source;
        switch (source.kind) {
          case "GlobalParameterSource": {
            return this.module.global.get(ref.named, mapBinaryenType(ref.type));
          }
          case "FunctionParameterSource": {
            return this.module.local.get(
              source.index,
              mapBinaryenType(ref.type)
            );
          }
          case "LocalParameterSource": {
            throw new Error(`Unimplemented local variable`);
          }
        }
        throw new Error(`Unimplemented get variable from somewhere else`);
      }
      case "NumberExpression": {
        // FIXME: Wrong type should be more explicit
        if (expression.type.name === "f32") {
          return this.module.f32.const(expression.value);
        }
        return this.module.i32.const(expression.value);
      }

      case "BinaryExpression": {
        const fn = this.binaryOperations.get(
          [
            expression.operator,
            mapBinaryenType(expression.type),
            mapBinaryenType(expression.type),
          ].join()
        );
        if (!fn) {
          throw new Error(
            `No binary expression defined for ${JSON.stringify(
              expression.type
            )} ${expression.operator}`
          );
        }
        return fn(
          this.emitExpression(expression.lhs),
          this.emitExpression(expression.rhs)
        );
      }
    }
    throw new Error("Expression " + expression.kind + " is not implemented.");
  }

  binaryOperations = new Map<string, (a: number, b: number) => number>([
    [["+", binaryen.i32, binaryen.i32].join(), this.module.i32.add],
    [["+", binaryen.f32, binaryen.f32].join(), this.module.f32.add],
    [["*", binaryen.i32, binaryen.i32].join(), this.module.i32.mul],
    [["*", binaryen.f32, binaryen.f32].join(), this.module.f32.mul],
    [["/", binaryen.i32, binaryen.i32].join(), this.module.i32.div_u],
    [["/", binaryen.f32, binaryen.f32].join(), this.module.f32.div],
    [["-", binaryen.i32, binaryen.i32].join(), this.module.i32.sub],
    [["-", binaryen.f32, binaryen.f32].join(), this.module.f32.sub],
  ]);

  emitPrintf(stmt: CallExpression) {
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
}

function mapBinaryenType(t: VaderType): binaryen.Type {
  switch (t.name) {
    case "boolean":
    case "int":
    case "u8":
    case "u32":
      return binaryen.i32;
    case "long":
    case "u64":
      return binaryen.i64;
    case "float":
    case "f32":
      return binaryen.f32;
    case "f64":
      return binaryen.f64;
    case "void":
      return binaryen.none;
  }
  throw new Error("Type mapping " + t.name + " is not implemented.");
}
