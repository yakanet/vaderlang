// TypeScript peer of bench/tree_eval.vader. A discriminated union tagged by a
// string literal, and the dispatch is a switch on that tag.

const TREE_DEPTH = 17;
const PASS_COUNT = 40;
const MAX_LITERAL = 9;

type Expression =
  | { kind: "literal"; value: number }
  | { kind: "add"; left: Expression; right: Expression }
  | { kind: "subtract"; left: Expression; right: Expression }
  | { kind: "negate"; operand: Expression };

function evaluate(expression: Expression): number {
  switch (expression.kind) {
    case "literal": return expression.value;
    case "add": return evaluate(expression.left) + evaluate(expression.right);
    case "subtract": return evaluate(expression.left) - evaluate(expression.right);
    case "negate": return -evaluate(expression.operand);
  }
}

// The seed descends the tree deterministically, so the shape and every literal
// are identical in all four ports. Negate wraps a binary node rather than taking
// one child, which keeps the tree balanced.
function build(depth: number, seed: number): Expression {
  if (depth === 0) return { kind: "literal", value: (seed % MAX_LITERAL) + 1 };
  const left = build(depth - 1, seed * 2 + 1);
  const right = build(depth - 1, seed * 2 + 2);
  switch (seed % 3) {
    case 0: return { kind: "add", left, right };
    case 1: return { kind: "subtract", left, right };
    default: return { kind: "negate", operand: { kind: "add", left, right } };
  }
}

const root = build(TREE_DEPTH, 1);
let total = 0;
for (let pass = 0; pass < PASS_COUNT; pass++) {
  total += evaluate(root);
}
console.log(`tree_eval depth=${TREE_DEPTH} passes=${PASS_COUNT} total=${total}`);
