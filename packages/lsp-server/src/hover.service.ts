import type { Hover, HoverParams } from "vscode-languageserver";
import { DocumentService } from "./document.service";
import { ConnectionService } from "./connection.service";
import {tokenize} from '@vaderlang/compiler'

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
    if (!document) {
      return {
        contents: []
      }
    }
    for(const token of tokenize(document.getText(), document.uri)) {
      if(token.location.start.line === handler.position.line + 1) {
        if(token.location.start.column <= handler.position.character + 1 && token.location.end.column > handler.position.character + 1) {
          return {
            contents: [
              JSON.stringify({type: token.type, value: token.value})
            ]
          }
        }
      }
    }
    return {
      contents: [],
    };
  }
}
