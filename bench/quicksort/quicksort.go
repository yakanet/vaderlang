// Go peer of bench/quicksort.vader. Same median-of-three Lomuto quicksort
// over an []int32, tail-recursion eliminated on the larger side.

package main

import "fmt"

const (
	n      = 1_000_000
	stride = 999983
	nMod   = 1_000_000
)

func qsort(a []int32, lo, hi int) {
	l, h := lo, hi
	for h-l > 1 {
		mid := l + (h-l)/2
		hh := h - 1
		if a[l] > a[mid] {
			a[l], a[mid] = a[mid], a[l]
		}
		if a[l] > a[hh] {
			a[l], a[hh] = a[hh], a[l]
		}
		if a[mid] < a[hh] {
			a[mid], a[hh] = a[hh], a[mid]
		}
		pivot := a[hh]
		i := l
		for j := l; j < hh; j++ {
			if a[j] < pivot {
				a[i], a[j] = a[j], a[i]
				i++
			}
		}
		a[i], a[hh] = a[hh], a[i]
		if i-l < h-(i+1) {
			qsort(a, l, i)
			l = i + 1
		} else {
			qsort(a, i+1, h)
			h = i
		}
	}
}

func main() {
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = int32((int64(i) * stride) % nMod)
	}
	qsort(a, 0, n)
	var chk int64
	for i := 0; i < n; i++ {
		chk = (chk*31 + int64(a[i])) % 2147483648
	}
	fmt.Printf("quicksort n=%d chk=%d\n", n, chk)
}
