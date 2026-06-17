// Go peer of bench/mandelbrot.vader. Same parameters, same kernel, same
// checksum so cross-language equivalence is verifiable.

package main

import "fmt"

const (
	WIDTH    = 240
	HEIGHT   = 180
	MAX_ITER = 500
	X_MIN    = -2.0
	X_MAX    = 1.0
	Y_MIN    = -1.0
	Y_MAX    = 1.0
)

// On arm64 Go fuses `a*b + c` into a single FMA instruction, which uses a
// single rounding step rather than two. The resulting checksum drifts from
// the C-compiled Vader and Bun/TS peers by ~0.3 % at the boundary of the
// Mandelbrot set. Both results are correct ; only the rounding model
// differs. The bench harness reports the checksums independently and only
// compares timings across implementations.
func iterations(cx, cy float64) int32 {
	zx, zy := 0.0, 0.0
	for iter := int32(0); iter < MAX_ITER; iter++ {
		zx2 := zx * zx
		zy2 := zy * zy
		if zx2+zy2 > 4.0 {
			return iter
		}
		newZy := 2.0*zx*zy + cy
		zx = zx2 - zy2 + cx
		zy = newZy
	}
	return MAX_ITER
}

func main() {
	dx := (X_MAX - X_MIN) / float64(WIDTH)
	dy := (Y_MAX - Y_MIN) / float64(HEIGHT)
	var checksum int64
	for row := 0; row < HEIGHT; row++ {
		cy := Y_MIN + float64(row)*dy
		for col := 0; col < WIDTH; col++ {
			cx := X_MIN + float64(col)*dx
			checksum += int64(iterations(cx, cy))
		}
	}
	fmt.Printf("mandelbrot %dx%d iter=%d checksum=%d\n", WIDTH, HEIGHT, MAX_ITER, checksum)
}
