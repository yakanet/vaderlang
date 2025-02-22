import type { Hover, HoverParams } from "vscode-languageserver";
import { DocumentService } from "./document.service";
import { ConnectionService } from "./connection.service";
import tokens from "@vaderlang/compiler/build/index";

export class HoverService {
  constructor(
    connectionService: ConnectionService,
    private documentService: DocumentService
  ) {
    connectionService.connection.onHover((handler) => this.execute(handler));
  }
  execute(handler: HoverParams): Hover {
    const document = this.documentService.documents.get(
      handler.textDocument.uri
    );
    if (document) {
      console.log(tokens.tokenize(document.getText(), document.uri));
    }
    return {
      contents: [
        `Hover content ${handler.textDocument.uri}:${handler.position.line}:${handler.position.character}`,
      ],
    };
  }
}
