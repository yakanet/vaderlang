import { TextDocuments } from "vscode-languageserver";
import { TextDocument } from "vscode-languageserver-textdocument";
import { ConnectionService } from "./connection.service";

export class DocumentService {
  public readonly documents: TextDocuments<TextDocument>;
  constructor(public readonly connectionService: ConnectionService) {
    this.documents = new TextDocuments(TextDocument);
    this.documents.listen(connectionService.connection);
  }
}
