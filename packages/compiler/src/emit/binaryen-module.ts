import binaryen from "binaryen";
import type {FunctionDeclarationExpression, Statement, VaderType} from "../parser/types.ts";
import type {Token} from "../tokens/types.ts";

const GLOBAL_SCOPE = '$$GLOBAL_SCOPE$$'
type SymbolScope = 'parameter' | 'local' | 'global'
type Symbol = {
    type: VaderType,
    index: number,
    scope: SymbolScope
}

export class BinaryenModule {
    private memoryLayout: { offset: number, data: Uint8Array }[] = [];
    private memoryOffset = 0;
    private currentScope: string = GLOBAL_SCOPE;
    private functionMapping = new Map<string, binaryen.ExpressionRef>();
    private debugSymbols: {
        functionName: string | undefined,
        expression: binaryen.ExpressionRef,
        location: Token['location'],
    }[] = [];
    private filesIndex = new Map<string, number>();
    private symbols: Record<string, Map<string, Symbol>> = {};
    public readonly module: binaryen.Module;

    constructor(private enableDebug = false) {
        this.module = new binaryen.Module();
        this.module.setFeatures(binaryen.Features.All)
        this.module.setMemory(1, -1);
        this.symbols[GLOBAL_SCOPE] = new Map();
    }

    inFunctionScope(functionName: string, statement: FunctionDeclarationExpression, createFunction: () => binaryen.ExpressionRef): binaryen.ExpressionRef {
        this.currentScope = functionName;
        this.symbols[this.currentScope] = new Map();
        const expression = createFunction()
        this.functionMapping.set(functionName, expression);
        this.currentScope = GLOBAL_SCOPE;
        return expression;
    }

    inCallScope(create: () => binaryen.ExpressionRef): binaryen.ExpressionRef {
        const previousScope = this.currentScope;
        const expression = create();
        this.currentScope = previousScope;
        return expression;
    }

    malloc(sizeOrData: number | Uint8Array): binaryen.MemorySegment {
        const size = typeof sizeOrData === "number" ? sizeOrData : sizeOrData.length;
        const data = typeof sizeOrData === "number" ? new Uint8Array(sizeOrData) : sizeOrData;
        const segment: binaryen.MemorySegment = {
            data,
            offset: this.memoryOffset,
        };
        this.memoryOffset += align_ptr(size)
        this.memoryLayout.push(segment);
        return segment;
    }

    createDebugStatement(statement: Statement) {
        return {
            addDebugStatement: (expression: binaryen.ExpressionRef) => {
                this.addDebugStatement(expression, statement);
                return expression;
            }
        }
    }

    build() {
        for (const instruction of this.debugSymbols) {
            let fileIndex = this.filesIndex.get(instruction.location.file);
            if (fileIndex === undefined) {
                fileIndex = this.module.addDebugInfoFileName(instruction.location.file);
                this.filesIndex.set(instruction.location.file, fileIndex);
            }
            this.module.setDebugLocation(
                instruction.functionName ? this.functionMapping.get(instruction.functionName)! : 0,
                instruction.expression,
                fileIndex,
                instruction.location.start.line + 1,
                instruction.location.start.column + 1,
            )
        }
        this.module.setMemory(1, -1, "memory", this.memoryLayout.map(layout => ({
            data: layout.data,
            offset: this.module.i32.const(layout.offset),
        })));
        return this.module;
    }

    public addDebugStatement(value: binaryen.ExpressionRef, statement: Statement) {
        if (this.enableDebug && this.currentScope !== GLOBAL_SCOPE) {
            this.debugSymbols.push({
                functionName: this.currentScope,
                expression: value,
                location: statement.location
            })
        }
        return value;
    }

    addSymbol(symbolName: string, type: VaderType, scope: SymbolScope, index: number) {
        this.symbols[this.currentScope].set(symbolName, {
            type,
            scope,
            index
        })
    }

    resolveSymbol(symbolName: string, scope: 'all' | 'global' | 'local' = 'local') {
        if (scope === "all") {
            return this.symbols[this.currentScope].get(symbolName)
                ?? this.symbols[GLOBAL_SCOPE].get(symbolName)
        }
        if (scope === "global") {
            return this.symbols[GLOBAL_SCOPE].get(symbolName)
        }
        return this.symbols[this.currentScope].get(symbolName)
    }

    currentSymbolIndex() {
        return this.symbols[this.currentScope].size;
    }

    getSymbols() {
        return [...this.symbols[this.currentScope].values()]
    }

    isGlobalScope() {
        return this.currentScope === GLOBAL_SCOPE;
    }
}

function align_ptr(address: number) {
    if (address % 4 === 0) {
        return address;
    }
    return address + 4 - (address % 4);
}