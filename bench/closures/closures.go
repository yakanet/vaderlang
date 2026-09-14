// Go peer of bench/closures.vader. A captured variable that escapes moves to
// the heap, which is the same cell Vader mints, and a func value is the same
// indirect call.

package main

import "fmt"

const (
	calls  = 6_000_000
	adders = 500
)

func makeAdder(n int64) func(int64) int64 {
	return func(x int64) int64 { return x + n }
}

func main() {
	var counter int64
	bump := func() { counter = counter + 1 }
	for i := 0; i < calls; i++ {
		bump()
	}

	list := make([]func(int64) int64, 0, adders)
	for index := 0; index < adders; index++ {
		list = append(list, makeAdder(int64(index)))
	}
	var total int64
	for pass := 0; pass < calls/adders; pass++ {
		for _, adder := range list {
			total = adder(total)
		}
	}
	fmt.Printf("closures counter=%d total=%d\n", counter, total)
}
