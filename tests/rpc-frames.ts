// tests/rpc-frames: the framing `vader lsp` and `vader dap` speak over stdio, a
// `Content-Length` header and a blank line before each JSON body.

import { spawnCapture } from "./cli-bin.ts";

const encoder = new TextEncoder();
const decoder = new TextDecoder();

/** `message` as one frame. */
export function encodeFrame(message: object): Uint8Array {
  const body = encoder.encode(JSON.stringify(message));
  const header = encoder.encode(`Content-Length: ${body.byteLength}\r\n\r\n`);
  const out = new Uint8Array(header.byteLength + body.byteLength);
  out.set(header, 0);
  out.set(body, header.byteLength);
  return out;
}

/** The complete frames at the start of `bytes`, decoded, and the bytes after
 *  the last one: a frame still arriving stays in `rest`. */
export function decodeFrames(bytes: Uint8Array): { messages: any[]; rest: Uint8Array } {
  const messages: any[] = [];
  let cursor = 0;
  for (;;) {
    const separator = indexOfBlankLine(bytes, cursor);
    if (separator < 0) break;
    const header = decoder.decode(bytes.subarray(cursor, separator));
    const length = /content-length:\s*(\d+)/i.exec(header);
    if (length === null) throw new Error(`no Content-Length in header: ${header}`);
    const start = separator + 4;
    const end = start + Number(length[1]);
    if (bytes.byteLength < end) break;
    messages.push(JSON.parse(decoder.decode(bytes.subarray(start, end))));
    cursor = end;
  }
  return { messages, rest: bytes.subarray(cursor) };
}

// Where the `\r\n\r\n` closing a header starts, from `from` on; -1 when it has
// not arrived.
function indexOfBlankLine(bytes: Uint8Array, from: number): number {
  for (let i = from; i + 3 < bytes.byteLength; i++) {
    if (bytes[i] === 0x0d && bytes[i + 1] === 0x0a && bytes[i + 2] === 0x0d && bytes[i + 3] === 0x0a) return i;
  }
  return -1;
}

/** The messages `stream` carries, each as soon as its frame is complete. */
export async function* readFrames(stream: ReadableStream<Uint8Array>): AsyncGenerator<any> {
  let pending: Uint8Array = new Uint8Array(0);
  for await (const chunk of stream) {
    const grown = new Uint8Array(pending.byteLength + chunk.byteLength);
    grown.set(pending);
    grown.set(chunk, pending.byteLength);
    const { messages, rest } = decodeFrames(grown);
    pending = rest;
    yield* messages;
  }
}

/** Run `vader <args>` with every one of `messages` on its input, and return the
 *  messages it sent back, in order. For a session whose requests do not depend
 *  on the answers. */
export async function exchangeFrames(args: string[], messages: object[], timeoutMs: number): Promise<any[]> {
  const stdin = Buffer.concat(messages.map(encodeFrame));
  const run = await spawnCapture(args, { stdin, timeoutMs });
  // The output was decoded as UTF-8 text: encoding it again gives back the bytes
  // the frame lengths count.
  return decodeFrames(encoder.encode(run.stdout)).messages;
}
