// Java peer of bench/tree_eval.vader. A sealed interface over four records, and
// the dispatch is an exhaustive pattern switch — the JIT's own tag test.

static final int TREE_DEPTH = 17;
static final int PASS_COUNT = 100;
static final int MAX_LITERAL = 9;

sealed interface Expression permits Literal, Add, Subtract, Negate {}

record Literal(long value) implements Expression {}
record Add(Expression left, Expression right) implements Expression {}
record Subtract(Expression left, Expression right) implements Expression {}
record Negate(Expression operand) implements Expression {}

static long evaluate(Expression expression) {
    return switch (expression) {
        case Literal node -> node.value();
        case Add node -> evaluate(node.left()) + evaluate(node.right());
        case Subtract node -> evaluate(node.left()) - evaluate(node.right());
        case Negate node -> -evaluate(node.operand());
    };
}

// The seed descends the tree deterministically, so the shape and every literal
// are identical in all four ports. Negate wraps a binary node rather than taking
// one child, which keeps the tree balanced.
static Expression build(int depth, int seed) {
    if (depth == 0) return new Literal(seed % MAX_LITERAL + 1);
    Expression left = build(depth - 1, seed * 2 + 1);
    Expression right = build(depth - 1, seed * 2 + 2);
    return switch (seed % 3) {
        case 0 -> new Add(left, right);
        case 1 -> new Subtract(left, right);
        default -> new Negate(new Add(left, right));
    };
}

void main() {
    Expression root = build(TREE_DEPTH, 1);
    long total = 0;
    for (int pass = 0; pass < PASS_COUNT; pass++) {
        total += evaluate(root);
    }
    IO.println("tree_eval depth=%d passes=%d total=%d".formatted(TREE_DEPTH, PASS_COUNT, total));
}
