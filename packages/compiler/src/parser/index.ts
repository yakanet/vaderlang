import {type Program,} from "./types.ts";
import {Parser} from "./parser.ts";
import {parseStatement} from "./statement.ts";
import { BundleContext } from "../context/context.ts";

export function parseProgram(entryFile: string, context: BundleContext): Program {
    const parser = new Parser(context);
    if(!parser.loadVaderFile(entryFile, '.')) {
        throw context.reportError(`could not find entrypoint ${entryFile}`, {
            file: entryFile,
            start: {offset: 0, column: 0, line: 0},
            end: {offset: 0, column: 0, line: 0},
        })
    }
    const program: Program = {
        kind: 'Program',
        body: [],
        location: {
            start: parser.current.location.start,
            end: parser.current.location.start,
            file: parser.current.location.file,
        }
    }
    while (!parser.isCurrentType('EOF')) {
        program.body.push(parseStatement(parser))
    }
    program.location.end = parser.expect('EOF').location.end;
    return program;
}

