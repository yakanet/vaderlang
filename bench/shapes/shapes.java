// Java peer of bench/shapes.vader. A Shape[] of three record types, cycled so
// the call site stays megamorphic and the JIT cannot settle on one receiver.

static final int SHAPE_COUNT = 200_000;
static final int PASS_COUNT = 60;
static final int DIMENSION_LIMIT = 1000;

interface Shape {
    // Twice the area, so every shape's answer is an exact integer.
    long area();
}

record Circle(long radius) implements Shape {
    public long area() { return 6 * radius * radius; }
}

record Rectangle(long width, long height) implements Shape {
    public long area() { return 2 * width * height; }
}

record Triangle(long base, long height) implements Shape {
    public long area() { return base * height; }
}

static Shape[] buildShapes() {
    Shape[] shapes = new Shape[SHAPE_COUNT];
    for (int index = 0; index < SHAPE_COUNT; index++) {
        long dimension = index % DIMENSION_LIMIT;
        shapes[index] = switch (index % 3) {
            case 0 -> new Circle(dimension);
            case 1 -> new Rectangle(dimension, dimension + 1);
            default -> new Triangle(dimension, dimension + 2);
        };
    }
    return shapes;
}

void main() {
    Shape[] shapes = buildShapes();
    long total = 0;
    for (int pass = 0; pass < PASS_COUNT; pass++) {
        for (Shape shape : shapes) {
            total += shape.area();
        }
    }
    IO.println("shapes count=%d passes=%d total=%d".formatted(SHAPE_COUNT, PASS_COUNT, total));
}
