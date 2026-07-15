// Java peer of bench/mandelbrot.vader. Same parameters, same kernel, same
// checksum.

static final int WIDTH = 240;
static final int HEIGHT = 180;
static final int MAX_ITER = 500;
static final double X_MIN = -2.0;
static final double X_MAX =  1.0;
static final double Y_MIN = -1.0;
static final double Y_MAX =  1.0;

static int iterations(double cx, double cy) {
    double zx = 0.0, zy = 0.0;
    for (int iter = 0; iter < MAX_ITER; iter++) {
        double zx2 = zx * zx;
        double zy2 = zy * zy;
        if (zx2 + zy2 > 4.0) return iter;
        double newZy = 2.0 * zx * zy + cy;
        zx = zx2 - zy2 + cx;
        zy = newZy;
    }
    return MAX_ITER;
}

void main() {
    double dx = (X_MAX - X_MIN) / WIDTH;
    double dy = (Y_MAX - Y_MIN) / HEIGHT;
    long checksum = 0;
    for (int row = 0; row < HEIGHT; row++) {
        double cy = Y_MIN + row * dy;
        for (int col = 0; col < WIDTH; col++) {
            double cx = X_MIN + col * dx;
            checksum += iterations(cx, cy);
        }
    }
    IO.println("mandelbrot %dx%d iter=%d checksum=%d".formatted(WIDTH, HEIGHT, MAX_ITER, checksum));
}
