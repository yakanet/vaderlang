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
import child_process from "node:child_process";
import { BundleContext } from "./context/context.ts";

const shouldUpdate = !!process.env['UPDATE_SNAPSHOT'];
const testFolders = [
    'examples'
]
const skip = new Set<string>([
    'examples/strings.vader'
])
const snapshot_directory = '__snapshot__'
if (shouldUpdate) {
    fs.rmSync(snapshot_directory, {recursive: true})
}

for (const folder of testFolders) {
    const glob = new Glob(`${folder}/*.vader`);
    for (const file of glob.scanSync(".")) {
        if (skip.has(file)) continue;
        testTokenizer(file, shouldUpdate);
        testParser(file, shouldUpdate);
        testWasmEmitter(file, shouldUpdate);
        testRun(file, shouldUpdate);
    }
}

function createSnapshotFile(file: string, suffix: string) {
    const {dir, name} = path.parse(file);
    const output_dir = `${snapshot_directory}/${dir}/${name}`
    fs.mkdirSync(output_dir, {recursive: true});
    return `${output_dir}/${name}${suffix}`;
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
        const context = new BundleContext(resolver);
        let program = parseProgram(file, context)
        program = resolve(program, context)
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, program);
        } else {
            expectSnapshot(snapshotFile, program);
        }
    });
}

function testWasmEmitter(file: string, update: boolean) {
    const snapshotFile = createSnapshotFile(file, '_emitter.wat')
    it("Testing emiter (wasm) on " + file, () => {
        const resolver = new FileResolver(process.cwd(), ['./modules']);
        const context = new BundleContext(resolver);
        let program = parseProgram(file, context)
        program = resolve(program, context)
        const emitter = new WasmEmitter(false);
        const module = emitter.emit(program)
        const value = module.emitText();
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, value);
        } else {
            expectSnapshot(snapshotFile, value);
        }
    });
}


function testRun(file: string, update: boolean) {
    const snapshotFile = createSnapshotFile(file, '_run.txt')
    it("Testing execution (wasm) on " + file, () => {
        const resolver = new FileResolver(process.cwd(), ['./modules']);
        const context = new BundleContext(resolver);
        let program = parseProgram(file, context)
        program = resolve(program, context)
        const emitter = new WasmEmitter(false);
        emitter.emit(program)
        const wasmfile = createSnapshotFile(file, '.wasm');
        fs.writeFileSync(wasmfile, emitter.mod.module.emitBinary());
        const pid = child_process.spawnSync('wasmtime', ['--wasm=gc', wasmfile], {
            shell: true,
        })
        const actual = [
            `EXIT: ${pid.status}`,
            pid.stdout.length > 0 ? `STDOUT:\n${pid.stdout.toString()}` : undefined,
            pid.stderr.length > 0 ? `STDERR:\n${pid.stderr.toString()}` : undefined,
        ].filter(x => x).join('\n');
        if (update || !fs.existsSync(snapshotFile)) {
            updateSnapshot(snapshotFile, actual);
        } else {
            expectSnapshot(snapshotFile, actual);
        }
    });
}

function updateSnapshot(snapshotFile: string, value: unknown) {
    if (typeof value !== 'string') {
        value = JSON.stringify(value, null, 2);
    }
    fs.writeFileSync(snapshotFile, value as string, {encoding: 'utf-8'});
}

function expectSnapshot(snapshotFile: string, value: unknown) {
    const content = fs.readFileSync(snapshotFile, {encoding: 'utf-8'});
    if (typeof value === 'string') {
        expect(value).toEqual(content);
    } else {
        expect(JSON.parse(JSON.stringify(value))).toEqual(JSON.parse(content));
    }
}
