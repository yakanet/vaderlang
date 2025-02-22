import {type Program,} from "./types.ts";
import type {ModuleResolver} from "../resolver/module_resolver.ts";
import {Parser} from "./parser.ts";
import {parseStatement} from "./statement.ts";

export function parseProgram(entryFile: string, resolver: ModuleResolver): Program {
    const parser = new Parser(resolver);
    parser.loadVaderFile(entryFile)
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

