import { expect, test } from "bun:test";
import { tokenize } from "../src/lexer/lexer.ts";

test.skip("lexer: empty source produces only EOF (TODO when lexer is implemented)", () => {
  const tokens = tokenize("", "<test>");
  expect(tokens).toHaveLength(1);
  expect(tokens[0]?.kind).toBe("EOF");
});
