// Java peer of bench/binary_trees.vader. `Node` is a record holding value +
// left/right refs ; null is the empty subtree, matching Vader's `Node | null`.

record Node(int value, Node left, Node right) {}

static final int DEPTH = 17;

static Node buildTree(int depth, int value) {
    if (depth == 0) return new Node(value, null, null);
    return new Node(value,
        buildTree(depth - 1, value * 2),
        buildTree(depth - 1, value * 2 + 1));
}

static int countNodes(Node t) {
    if (t == null) return 0;
    return 1 + countNodes(t.left()) + countNodes(t.right());
}

void main() {
    Node tree = buildTree(DEPTH, 1);
    int count = countNodes(tree);
    IO.println("binary_trees depth=%d count=%d".formatted(DEPTH, count));
}
