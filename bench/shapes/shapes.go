// Go peer of bench/shapes.vader. A []Shape of three concrete types, so every
// Area() is an interface call the compiler cannot devirtualize.

package main

import "fmt"

const (
	shapeCount     = 200_000
	passCount      = 60
	dimensionLimit = 1000
)

type Shape interface {
	// Twice the area, so every shape's answer is an exact integer.
	Area() int64
}

type Circle struct{ radius int64 }
type Rectangle struct{ width, height int64 }
type Triangle struct{ base, height int64 }

func (self Circle) Area() int64    { return 6 * self.radius * self.radius }
func (self Rectangle) Area() int64 { return 2 * self.width * self.height }
func (self Triangle) Area() int64  { return self.base * self.height }

func buildShapes() []Shape {
	shapes := make([]Shape, 0, shapeCount)
	for index := 0; index < shapeCount; index++ {
		dimension := int64(index % dimensionLimit)
		switch index % 3 {
		case 0:
			shapes = append(shapes, Circle{radius: dimension})
		case 1:
			shapes = append(shapes, Rectangle{width: dimension, height: dimension + 1})
		default:
			shapes = append(shapes, Triangle{base: dimension, height: dimension + 2})
		}
	}
	return shapes
}

func main() {
	shapes := buildShapes()
	var total int64
	for pass := 0; pass < passCount; pass++ {
		for _, shape := range shapes {
			total += shape.Area()
		}
	}
	fmt.Printf("shapes count=%d passes=%d total=%d\n", shapeCount, passCount, total)
}
