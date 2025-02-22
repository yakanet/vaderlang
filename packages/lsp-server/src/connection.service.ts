import { Connection } from "vscode-languageserver";

export class ConnectionService {
    constructor(public readonly connection: Connection) {
    }
}