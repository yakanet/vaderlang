// TypeScript peer of bench/shapes.vader. An array of three classes sharing one
// method name, cycled so the call site stays megamorphic and no inline cache
// settles on a single shape.

const SHAPE_COUNT = 200_000;
const PASS_COUNT = 60;
const DIMENSION_LIMIT = 1000;

interface Shape {
  // Twice the area, so every shape's answer is an exact integer.
  area(): number;
}

class Circle implements Shape {
  constructor(private radius: number) {}
  area(): number { return 6 * this.radius * this.radius; }
}

class Rectangle implements Shape {
  constructor(private width: number, private height: number) {}
  area(): number { return 2 * this.width * this.height; }
}

class Triangle implements Shape {
  constructor(private base: number, private height: number) {}
  area(): number { return this.base * this.height; }
}

function buildShapes(): Shape[] {
  const shapes: Shape[] = [];
  for (let index = 0; index < SHAPE_COUNT; index++) {
    const dimension = index % DIMENSION_LIMIT;
    switch (index % 3) {
      case 0: shapes.push(new Circle(dimension)); break;
      case 1: shapes.push(new Rectangle(dimension, dimension + 1)); break;
      default: shapes.push(new Triangle(dimension, dimension + 2)); break;
    }
  }
  return shapes;
}

const shapes = buildShapes();
let total = 0;
for (let pass = 0; pass < PASS_COUNT; pass++) {
  for (let index = 0; index < shapes.length; index++) {
    total += shapes[index]!.area();
  }
}
console.log(`shapes count=${SHAPE_COUNT} passes=${PASS_COUNT} total=${total}`);
