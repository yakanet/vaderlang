import { Connection } from "vscode-languageserver";
import { ConnectionService } from "./connection.service";
import { DocumentService } from "./document.service";
import { HoverService } from "./hover.service";

export function setup(connection: Connection) {
    const connectionService = new ConnectionService(connection);
    const documentService = new DocumentService(connectionService);
    new HoverService(connectionService, documentService)
}