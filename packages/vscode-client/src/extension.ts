import * as path from "path";
import * as vscode from 'vscode';
import {
  LanguageClient,
  type LanguageClientOptions,
  type ServerOptions,
  TransportKind,
} from "vscode-languageclient/node";

let client: LanguageClient;

export function activate(context: vscode.ExtensionContext) {
  // The server is implemented in node
  console.log(`CWD: ${context.asAbsolutePath('.')}`)
  const serverModule = context.asAbsolutePath(
    path.join("..", "lsp-server", "build", "index.js")
  );

  // If the extension is launched in debug mode then the debug server options are used
  // Otherwise the run options are used
  console.log({ serverModule });
  const serverOptions: ServerOptions = {
    run: {
      module: serverModule,
      transport: TransportKind.ipc,
    },
    debug: {
      module: serverModule,
      transport: TransportKind.ipc,
    },
  };

  // Options to control the language client
  const clientOptions: LanguageClientOptions = {
    // Register the server for plain text documents
    documentSelector: [{ scheme: "file", language: "vader" }],
    outputChannel: vscode.window.createOutputChannel("Vader Language Server")
    //synchronize: {
    //  // Notify the server about file changes to '.clientrc files contained in the workspace
    //  fileEvents: workspace.createFileSystemWatcher("**/.clientrc"),
    //},
  };

  // Create the language client and start the client.
  client = new LanguageClient(
    "vls",
    "Vader Language Client",
    serverOptions,
    clientOptions
  );

  // Start the client. This will also launch the server
  client.start();
}

export function deactivate(): Thenable<void> | undefined {
  if (!client) {
    return undefined;
  }
  return client.stop();
}
