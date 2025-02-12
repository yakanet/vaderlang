import {Glob} from "bun";
import {expect, it} from 'bun:test';
import {tokenize} from "./tokens";
import fs from "node:fs";
import path from 'node:path'
import {parseProgram} from "./parser";
import {FileResolver} from "./resolver/module_resolver.ts";
import {resolve} from "./resolver/resolver.ts";
import {WasmEmitter} from "./emit/wasm-emitter.ts";
import process from "node:process";

const shouldUpdate = !!process.env['UPDATE_SNAPSHOT'];
const testFolders = [
    'examples'
]
const skip = new Set<string>([
    'examples/loop.vader',
])

for (const folder of testFolders) {
    const glob = new Glob(`${folder}/*.vader`);
    for (const file of glob.scanSync(".")) {
        if (skip.has(file)) continue;
        testTokenizer(file, shouldUpdate);
        testParser(file, shouldUpdate);
        testWasmEmitter(file, shouldUpdate);
    }
}

function createSnapshotFile(file: string, suffix: string) {
    const oldExt = path.extname(file);
    return `${file.substring(0, file.length - oldExt.length)}${suffix}`;
}

function testTokenizer(file: string, update = false) {
    const snapshotFile = createSnapshotFile(file, '_tokenizer.json')
    it("Testing tokenizer on " + file, () => {
        const tokens = [...tokenize(fs.readFileSync(file, {encoding: 'utf-8'}), file)];
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, tokens);
        } else {
            expectSnapshot(snapshotFile, tokens);
        }
    });
}

function testParser(file: string, update = false) {
    const snapshotFile = createSnapshotFile(file, '_parser.json')
    it("Testing parser on " + file, () => {
        const resolver = new FileResolver(process.cwd(), ['./modules']);
        const program = parseProgram(file, resolver)
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, program);
        } else {
            expectSnapshot(snapshotFile, program);
        }
    });
}

function testWasmEmitter(file: string, update: boolean) {
    const snapshotFile = createSnapshotFile(file, '_emitter.wat')
    it("Testing WasmEmitter on " + file, () => {
        const resolver = new FileResolver(process.cwd(), ['./modules']);
        let program = parseProgram(file, resolver)
        program = resolve(program)
        const emitter = new WasmEmitter();
        emitter.emit(program)
        const value = emitter.module.emitText();
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, value);
        } else {
            expectSnapshot(snapshotFile, value);
        }
    });
}

function updateSnapshot(snapshotFile: string, value: unknown) {
    if (typeof value !== 'string') {
        value = JSON.stringify(value, (key, value) => {
            if (key === 'scope') {
                return undefined;
            }
            return value;
        }, 2);
    }
    fs.writeFileSync(snapshotFile, value as string, {encoding: 'utf-8'});
}

function expectSnapshot(snapshotFile: string, value: unknown) {
    const content = fs.readFileSync(snapshotFile, {encoding: 'utf-8'});
    if (typeof value === 'string') {
        expect(value).toEqual(content);
    } else {
        expect(value).toEqual(JSON.parse(content));
    }
}
