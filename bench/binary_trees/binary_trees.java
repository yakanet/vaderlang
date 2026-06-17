// Java peer of bench/binary_trees.vader. `Node` is a record (Java 14+),
// holding value + left/right refs ; null is the empty subtree, matching
// Vader's `Node | null`.

public class binary_trees {
    static final int DEPTH = 17;

    record Node(int value, Node left, Node right) {}

    static Node buildTree(int depth, int value) {
        if (depth == 0) return new Node(value, null, null);
        return new Node(value,
            buildTree(depth - 1, value * 2),
            buildTree(depth - 1, value * 2 + 1));
    }

    static int countNodes(Node t) {
        if (t == null) return 0;
        return 1 + countNodes(t.left) + countNodes(t.right);
    }

    public static void main(String[] args) {
        Node tree = buildTree(DEPTH, 1);
        int count = countNodes(tree);
        System.out.printf("binary_trees depth=%d count=%d%n", DEPTH, count);
    }
}
