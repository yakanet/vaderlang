// Vader VSCode extension — spawns the Vader Language Server and routes
// every `.vader` document through it. The server itself is implemented
// in Vader (`vader/lsp/main_entry.vader`) and shipped with the Vader CLI
// binary ; this extension is a thin client.

import * as vscode from "vscode";
import {
  LanguageClient,
  type LanguageClientOptions,
  type ServerOptions,
  TransportKind,
} from "vscode-languageclient/node";

let client: LanguageClient | undefined;

// Replaces `${workspaceFolder}` with the first workspace folder's absolute
// path. VS Code's launch.json does this natively but `getConfiguration()`
// returns raw strings, so we interpolate by hand. If no folder is open the
// placeholder is left as-is so the spawn fails loudly instead of silently
// pointing at the wrong location.
function interpolate(input: string): string {
  const folder = vscode.workspace.workspaceFolders?.[0]?.uri.fsPath;
  if (folder === undefined) return input;
  return input.replace(/\$\{workspaceFolder\}/g, folder);
}

function isBinaryMissing(err: unknown): boolean {
  // Node's `spawn` rejects with an Error carrying `.code = "ENOENT"`. Prefer
  // that over message-matching since the wording is locale-dependent.
  if (err !== null && typeof err === "object" && (err as { code?: string }).code === "ENOENT") {
    return true;
  }
  const msg = err instanceof Error ? err.message : String(err);
  return msg.includes("ENOENT");
}

async function promptForBinaryPath(currentValue: string): Promise<string | undefined> {
  const choice = await vscode.window.showErrorMessage(
    `Could not find the Vader binary (currently configured as "${currentValue}"). Set the path to the \`vader\` executable?`,
    { modal: false },
    "Browse...",
    "Enter Path...",
  );

  if (choice === "Browse...") {
    const folder = vscode.workspace.workspaceFolders?.[0]?.uri;
    const picked = await vscode.window.showOpenDialog({
      canSelectFiles: true,
      canSelectFolders: false,
      canSelectMany: false,
      title: "Select the Vader CLI binary",
      defaultUri: folder,
    });
    return picked?.[0]?.fsPath;
  }

  if (choice === "Enter Path...") {
    const entered = await vscode.window.showInputBox({
      title: "Vader binary path",
      placeHolder: "/absolute/path/to/vader  or  ${workspaceFolder}/build/vader",
      value: currentValue === "vader" ? "" : currentValue,
      validateInput: (v) => (v.trim() === "" ? "Path cannot be empty" : null),
    });
    return entered?.trim();
  }

  return undefined;
}

async function startClient(attempt = 0): Promise<void> {
  const config = vscode.workspace.getConfiguration("vader");
  const rawPath = config.get<string>("lsp.path", "vader");
  const command = interpolate(rawPath);
  const args = config.get<string[]>("lsp.args", ["lsp"]).map(interpolate);

  // Both `run` and `debug` configurations point at the same binary —
  // the LSP server doesn't have a "debug mode" yet (no `--inspect` /
  // attached debugger), and a separate code path here would just lead
  // to drift.
  const serverOptions: ServerOptions = {
    run:   { command, args, transport: TransportKind.stdio },
    debug: { command, args, transport: TransportKind.stdio },
  };

  const clientOptions: LanguageClientOptions = {
    documentSelector: [{ scheme: "file", language: "vader" }],
    synchronize: { configurationSection: "vader" },
  };

  client = new LanguageClient("vader", "Vader Language Server", serverOptions, clientOptions);

  try {
    await client.start();
  } catch (err) {
    if (!isBinaryMissing(err)) {
      vscode.window.showErrorMessage(
        `Vader Language Server failed to start (${command} ${args.join(" ")}): ${
          err instanceof Error ? err.message : String(err)
        }`,
      );
      return;
    }

    // One retry only — if the user supplies a still-broken path we'd loop
    // forever otherwise, and they can always re-trigger by reloading.
    if (attempt > 0) {
      vscode.window.showErrorMessage(
        `Vader Language Server still cannot find the binary at "${rawPath}". Reload the window after fixing the path.`,
      );
      return;
    }

    const newPath = await promptForBinaryPath(rawPath);
    if (newPath === undefined || newPath === "") return;

    // Persist at workspace scope when there's an open folder ; otherwise
    // fall back to global so the next session picks it up too.
    const target =
      vscode.workspace.workspaceFolders !== undefined
        ? vscode.ConfigurationTarget.Workspace
        : vscode.ConfigurationTarget.Global;
    await config.update("lsp.path", newPath, target);

    client = undefined;
    await startClient(attempt + 1);
  }
}

export function activate(_context: vscode.ExtensionContext): void {
  startClient().catch((err) => {
    vscode.window.showErrorMessage(
      `Vader Language Server activation failed: ${
        err instanceof Error ? err.message : String(err)
      }`,
    );
  });
}

export function deactivate(): Thenable<void> | undefined {
  return client?.stop();
}
