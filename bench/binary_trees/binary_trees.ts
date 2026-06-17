// TypeScript peer of bench/binary_trees.vader. Same recursive build +
// count algorithm. Node holds value + left/right refs, exactly mirroring
// the Vader struct.

const DEPTH = 17;

class Node {
  constructor(
    public readonly value: number,
    public readonly left: Node | null,
    public readonly right: Node | null,
  ) {}
}

function buildTree(depth: number, value: number): Node {
  if (depth === 0) return new Node(value, null, null);
  return new Node(value, buildTree(depth - 1, value * 2), buildTree(depth - 1, value * 2 + 1));
}

function countNodes(t: Node | null): number {
  if (t === null) return 0;
  return 1 + countNodes(t.left) + countNodes(t.right);
}

const tree = buildTree(DEPTH, 1);
const count = countNodes(tree);
console.log(`binary_trees depth=${DEPTH} count=${count}`);
