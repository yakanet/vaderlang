// TypeScript peer of bench/mandelbrot.vader. Same parameters, same kernel,
// same checksum so cross-language equivalence is verifiable.

const WIDTH = 240;
const HEIGHT = 180;
const MAX_ITER = 500;

const X_MIN = -2.0;
const X_MAX = 1.0;
const Y_MIN = -1.0;
const Y_MAX = 1.0;

function iterations(cx: number, cy: number): number {
  let zx = 0.0;
  let zy = 0.0;
  for (let iter = 0; iter < MAX_ITER; iter++) {
    const zx2 = zx * zx;
    const zy2 = zy * zy;
    if (zx2 + zy2 > 4.0) return iter;
    const newZy = 2.0 * zx * zy + cy;
    zx = zx2 - zy2 + cx;
    zy = newZy;
  }
  return MAX_ITER;
}

const dx = (X_MAX - X_MIN) / WIDTH;
const dy = (Y_MAX - Y_MIN) / HEIGHT;
let checksum = 0;
for (let row = 0; row < HEIGHT; row++) {
  const cy = Y_MIN + row * dy;
  for (let col = 0; col < WIDTH; col++) {
    const cx = X_MIN + col * dx;
    checksum += iterations(cx, cy);
  }
}
console.log(`mandelbrot ${WIDTH}x${HEIGHT} iter=${MAX_ITER} checksum=${checksum}`);
