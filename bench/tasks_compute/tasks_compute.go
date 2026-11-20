// Go peer of bench/tasks_compute.vader. A goroutine is the task, a channel that
// carries its one result the join. GOMAXPROCS sets the cores, as VADER_THREADS
// does for Vader.

package main

import "fmt"

const (
	tasks = 16
	chunk = 125_000
)

func longestChain(lo, hi int64) int64 {
	var best int64
	for n := lo; n < hi; n++ {
		x := n
		var steps int64
		for x != 1 {
			if x%2 == 0 {
				x = x / 2
			} else {
				x = 3*x + 1
			}
			steps++
		}
		if steps > best {
			best = steps
		}
	}
	return best
}

func main() {
	results := make([]chan int64, tasks)
	for k := 0; k < tasks; k++ {
		lo := 1 + int64(k)*chunk
		done := make(chan int64, 1)
		results[k] = done
		go func() { done <- longestChain(lo, lo+chunk) }()
	}
	var best int64
	for _, done := range results {
		if steps := <-done; steps > best {
			best = steps
		}
	}
	fmt.Printf("tasks_compute best=%d\n", best)
}
