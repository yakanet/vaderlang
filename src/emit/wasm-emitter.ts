import {
    BasicVaderType,
    type CallExpression,
    type DotExpression,
    type Program,
    type Statement,
    type StringExpression,
    type StructInstantiationExpression,
    type VaderType,
} from "../parser/types";
import binaryen from "binaryen";
import {addWasiFunction} from "./wasi.ts";
import assert from "node:assert";

const encoder = new TextEncoder();

export class WasmEmitter {
    private memoryLayout: { offset: number, data: Uint8Array }[] = [];
    public readonly module = new binaryen.Module();

    constructor() {
        addWasiFunction(this.module);
    }

    emit(program: Program) {
        this.module.setMemory(1, -1);

        for (const statement of program.body) {
            this.emitTopLevelStatement(statement);
        }

        this.emitMainMethod(program);

        this.module.setMemory(1, -1, "memory", this.memoryLayout.map(layout => ({
            data: layout.data,
            offset: this.module.i32.const(layout.offset),
        })));
        assert(this.module.validate());
        this.module.optimize();
    }

    emitMainMethod(program: Program) {
        if (!program.mainMethod) {
            return;
        }
        const resolved = program.scope.lookupVariable(program.mainMethod);
        if (resolved.source.kind !== 'GlobalFunctionSource') {
            throw new Error(`Main method must be a function`);
        }
        // TODO pass program param
        if (resolved.source.returnType.kind !== 'primitive') {
            throw new Error(`Main method should return a void type or u32 type`)
        }
        if (resolved.source.returnType.name === BasicVaderType.u32.name) {
            const funct = this.module.addFunction(
                "_start",
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
        } else if (resolved.source.returnType.name === BasicVaderType.void.name) {
            this.module.setStart(this.module.getFunction(program.mainMethod));
        } else {
            throw new Error(`Main method should return a void type or u32 type`)
        }
    }

    emitTopLevelStatement(statement: Statement) {
        switch (statement.kind) {
            case "FunctionDeclaration": {
                if (statement.decorators.includes('intrinsic')) {
                    return;
                }
                const localVariables = statement.body.length > 0
                    ? statement.body[0].scope.allVariables().filter(v => v.source.kind === 'LocalVariableSource')
                    : [];
                this.module.addFunction(
                    statement.name,
                    binaryen.createType(
                        statement.parameters.map((t) => mapBinaryenType(t.type))
                    ),
                    mapBinaryenType(statement.returnType),
                    localVariables.map(variable => mapBinaryenType(variable.type)),
                    this.module.block(
                        null,
                        statement.body.map((stmt) => this.emitStatement(stmt))
                    )
                );

                this.module.addFunctionExport(statement.name, statement.name);
                return;
            }
            case 'StructStatement':
                return;

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

    emitStatement(stmt: Statement): binaryen.ExpressionRef {
        switch (stmt.kind) {
            case "ReturnStatement":
                return this.module.return(this.emitExpression(stmt.expression));

            case "ConditionalStatement": {
                return this.module.if(
                    this.emitExpression(stmt.condition),
                    this.module.block(null, stmt.ifBody.map(b => this.emitStatement(b))),
                    stmt.elseBody ? this.module.block(null, stmt.elseBody.map(b => this.emitStatement(b as any))) : undefined
                )
            }

            case "VariableDeclarationStatement": {
                const scope = stmt.scope;
                const resolved = scope.lookupVariable(stmt.name);
                switch (resolved.source.kind) {
                    case "GlobalParameterSource": {
                        return this.module.global.set(
                            stmt.name,
                            this.emitExpression(stmt.value!)
                        );
                    }
                    case "FunctionParameterSource": {
                        throw new Error(`Could not reassign parameter value`);
                    }
                    case "LocalVariableSource": {
                        //if (resolved.type.kind === 'struct') {
                        //    const [address, expression] = this.instantiateStruct(stmt.value as StructInstantiationExpression);
                        //    return this.module.block(null, [
                        //        ...expression,
                        //        this.module.local.set(resolved.source.index, this.module.i32.const(address))
                        //    ])
                        //}
                        return this.module.local.set(
                            resolved.source.index,
                            this.emitExpression(stmt.value!)
                        )
                    }
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
                    return this.module.local.set(resolved.source.index, this.emitExpression(stmt.value));
                }
                if (resolved.source.kind === "LocalVariableSource") {
                    return this.module.local.set(resolved.source.index, this.emitExpression(stmt.value));
                }
            }
        }
        return this.emitExpression(stmt);
    }

    private emitExpression(
        expression: Statement
    ): binaryen.ExpressionRef {
        switch (expression.kind) {
            case 'CallExpression': {
                const ref = expression.scope.lookupVariable(expression.functionName);
                if (ref.source.kind !== 'GlobalFunctionSource') {
                    throw new Error(`Could only call function, trying to call ${ref.source.kind}.`);
                }
                if (ref.source.decorators.includes('intrinsic')) {
                    switch (expression.functionName) {
                        case 'print':
                            return this.emitPrint(expression)
                        case 'exit':
                            return this.emitExit(expression);
                        default:
                            throw new Error(`Unknown intrinsic function ${expression.functionName}`)
                    }
                }
                return this.module.call(
                    expression.functionName,
                    expression.parameters.map(p => this.emitExpression(p)),
                    mapBinaryenType(ref.source.returnType)
                );
            }
            case "VariableExpression": {
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
                    case "LocalVariableSource": {
                        return this.module.local.get(
                            source.index,
                            mapBinaryenType(ref.type)
                        );
                    }
                }
                throw new Error(`Unimplemented get variable from somewhere else`);
            }
            case "NumberExpression": {
                return createBinaryenConst(this.module, expression.type, expression.value!);
            }

            case 'StructInstantiationExpression':
                return this.instantiateStruct(expression);

            case 'DotExpression':
                return this.emitDotExpression(expression);

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

    private instantiateStruct(expression: StructInstantiationExpression): binaryen.ExpressionRef {
        assert(expression.type.kind === "struct");
        const size = size_of(expression.type);
        const segment = this.malloc(size);
        let offset = 0;
        const exp: binaryen.ExpressionRef[] = [];
        for (const p of expression.parameters) {
            exp.push(this.module.i32.store(
                offset,
                0,
                this.module.i32.const(segment.offset),
                this.emitExpression(p)
            ));
            offset += size_of(p.type);
        }
        return this.module.block(null, [
            ...exp,
            this.module.i32.const(segment.offset)
        ], binaryen.i32);
    }

    private emitDotExpression(expression: DotExpression) {
        const resolved = expression.scope.lookupVariable(expression.properties[0].name);
        let exprs: binaryen.ExpressionRef
        if (resolved.source.kind === 'GlobalFunctionSource') {
            exprs = this.module.global.get(resolved.named, binaryen.i32);
        } else if (resolved.source.kind === 'LocalVariableSource') {
            exprs = this.module.local.get(resolved.source.index, binaryen.i32);
        } else {
            throw new Error(`Unimplemented get variable from ${resolved.source.kind}`);
        }
        let previousType = expression.properties[0].type
        for (let i = 1; i < expression.properties.length; i ++) {
            if (previousType.kind === 'struct') {
                let offset = 0;
                const index = previousType.parameters.findIndex(p => p.name === expression.properties[i].name)
                for (let j = 0; j < index; j++) {
                    offset += size_of(previousType.parameters[j].type);
                }
                exprs = this.module.i32.load(
                    offset,
                    0,
                    exprs,
                )
                previousType = previousType.parameters[index].type
            }
        }
        return exprs;
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
        [['==', binaryen.i32, binaryen.i32].join(), this.module.i32.eq],
        [['!=', binaryen.i32, binaryen.i32].join(), this.module.i32.ne],
        [['&&', binaryen.i32, binaryen.i32].join(), this.module.i32.and],
        [['||', binaryen.i32, binaryen.i32].join(), this.module.i32.or],
    ]);

    private memoryOffset = 0;

    malloc(sizeOrData: number | Uint8Array): binaryen.MemorySegment {
        const size = typeof sizeOrData === "number" ? sizeOrData : sizeOrData.length;
        const data = typeof sizeOrData === "number" ? new Uint8Array(sizeOrData) : sizeOrData;
        const segment: binaryen.MemorySegment = {
            data,
            offset: this.memoryOffset,
        };
        this.memoryOffset += align_ptr(size + 1)
        this.memoryLayout.push(segment);
        return segment;
    }

    emitPrint(stmt: CallExpression) {
        assert(stmt.parameters[0]?.kind === "StringExpression");
        const string = stmt.parameters[0] as StringExpression;

        const string_memory_address = this.malloc(encoder.encode(string.value));
        const iov_memory_address = this.malloc(size_of(BasicVaderType.ptr) + size_of(BasicVaderType.u32));
        const result_memory_address = this.malloc(size_of(BasicVaderType.u32));

        return this.module.block(null, [
            // Store iovs
            // Start of data  (= *buf)
            this.module.i32.store(
                0,
                0,
                this.module.i32.const(iov_memory_address.offset),
                this.module.i32.const(string_memory_address.offset),
            ),
            // Length of data (= buf_len)
            this.module.i32.store(
                0,
                0,
                this.module.i32.const(iov_memory_address.offset + 4),
                this.module.i32.const(string_memory_address.data.length),
            ),
            this.module.drop(
                this.module.call(
                    "wasi_snapshot_preview1:fd_write",
                    [
                        this.module.i32.const(1), // stdout = 1
                        this.module.i32.const(iov_memory_address.offset), // ptr of iovs
                        this.module.i32.const(1), // number of iovs (iovs is an array)
                        this.module.i32.const(result_memory_address.offset), // where to store the returned error code
                    ],
                    binaryen.i32
                )
            ),
        ]);
    }

    emitExit(stmt: CallExpression) {
        assert(stmt.parameters.length === 1);
        return this.module.call("wasi_snapshot_preview1:proc_exit", [
            this.emitExpression(stmt.parameters[0])
        ], binaryen.none)
    }
}

function align_ptr(address: number) {
    if (address % 4 === 0) {
        return address;
    }
    return address + 4 - (address % 4);
}

function size_of(t: VaderType): number {
    if (t.kind === 'array') {
        return 4 * size_of(t.type);
    }
    if (t.kind === 'struct') {
        let size = 0;
        for (const p of t.parameters) {
            size += size_of(p.type)
        }
        return size;
    }
    switch (t.name) {
        case "boolean":
        case "int":
        case "u8":
        case "u32":
            return 4;
        case "long":
        case "u64":
            return 8;
        case "float":
        case "f32":
            return 4;
        case "f64":
            return 8;
        case "void":
            return 0;
    }
    throw new Error("Size of type " + t.name + " is not implemented.");
}

function createBinaryenConst(module: binaryen.Module, t: VaderType, value: number) {
    if (t.kind === 'array') {
        throw new Error(`Unimplemented array type`)
    }
    switch (t.name) {
        case "boolean":
        case "int":
        case "u8":
        case "u32":
            return module.i32.const(value);
        case "long":
        case "u64":
            return module.i64.const(value, 0);
        case "float":
        case "f32":
            return module.f32.const(value);
        case "f64":
            return module.f64.const(value);
        case "void":
            return binaryen.none;
    }
    throw new Error("Const of type " + t.name + " is not implemented.");
}

function mapBinaryenType(t: VaderType): binaryen.Type {
    if (t.kind === 'array') {
        throw new Error(`Unimplemented array type`)
    }
    if (t.kind === 'struct') {
        return binaryen.i32;
    }
    switch (t.name) {
        case "boolean":
        case "int":
        case "u8":
        case "u16":
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
