import {
  Diagnostic,
  DocumentDiagnosticReportKind,
  type DocumentDiagnosticParams,
  type DocumentDiagnosticReport,
} from "vscode-languageserver";
import { DocumentService } from "./document.service";
import { ConnectionService } from "./connection.service";
import {
  BundleContext,
  parseProgram,
  resolve,
} from "@vaderlang/compiler";
import { TextDocument } from "vscode-languageserver-textdocument";
import fs from 'node:fs';
import path from "node:path";

export class DiagnosticService {
  constructor(
    connectionService: ConnectionService,
    private documentService: DocumentService
  ) {
    connectionService.connection.languages.diagnostics.on((params) =>{
      return this.execute(params)
    });
  }

  execute(handler: DocumentDiagnosticParams): DocumentDiagnosticReport {
    const document = this.documentService.documents.get(
      handler.textDocument.uri
    );
    if (!document) {
      return {
        kind: DocumentDiagnosticReportKind.Full,
        items: [],
      };
    }
    return {
      kind: DocumentDiagnosticReportKind.Full,
      items: this.validateTextDocument(document),
    };
  }

  validateTextDocument(document: TextDocument): Diagnostic[] {
    const context = new BundleContext({
      resolve: (uri, from) => {
        // Try to resolve absolute URI (should be in workspace)
        const document = this.documentService.documents.get(uri)
        if(document) {
          return {
            key: uri,
            content: document.getText() ?? "",
            location: uri,
          };
        }
        // Try to resolve relative URI 
        try{
          const url = new URL(from);
          const type = fs.lstatSync(url.pathname)
          if(type.isDirectory()) {
            const newPath = path.resolve(url.pathname, uri)
            if(fs.existsSync(newPath)) {
              return {
                key: newPath,
                content: fs.readFileSync(newPath, {encoding: 'utf-8'}) ?? '',
                location: newPath,
              };
            }
          }else {
            const newPath = path.resolve( path.parse(url.pathname).dir, uri)
            if(fs.existsSync(newPath)) {
              return {
                key: newPath,
                content: fs.readFileSync(newPath, {encoding: 'utf-8'}) ?? '',
                location: newPath,
              };
            }
          }
        } catch(_e) {

        }

        // Try to resolve a module
        //FIXME: find a way to lookup for modules location (vscode settings ???)
        {
          const newUri = `/Users/mbroutin/Developments/default/vaderlang/modules/${uri}`
          const content = fs.readFileSync(newUri, {encoding: 'utf-8'}) ?? ''
          return {
            key: newUri,
            content: content,
            location: newUri,
          };
        }
      },
    });
    try{
      const program = parseProgram(document.uri, context);
      resolve(program, context)
      return []
    } catch(e) {
      return context.diagnostic.getDiagnostics().map(d => ({
        message: d.message,
        severity: d.type === 'ERROR' ? 1 : d.type === 'WARN' ? 2 : 3,
        range: {
          start: {
            character: d.location.start.column,
            line: d.location.start.line
          },
          end: {
            character: d.location.end.column,
            line: d.location.end.line
          }
        }
      }))
    }
  }
}
