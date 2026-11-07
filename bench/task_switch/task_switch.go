// Go peer of bench/task_switch.vader. A goroutine is the task, a channel that
// carries its one result the join, and two channels of capacity 1 the round
// trip. The goroutines share one OS thread, as Vader's tasks do: on several,
// a wake would also cost a wake of another thread.

package main

import (
	"fmt"
	"runtime"
)

const (
	batch   = 1_000
	batches = 10
	trips   = 300_000
)

func launchAndJoin() int64 {
	var total int64
	for b := 0; b < batches; b++ {
		results := make([]chan int64, batch)
		for i := 0; i < batch; i++ {
			n := int64(b*batch + i)
			done := make(chan int64, 1)
			results[i] = done
			go func() { done <- n + 1 }()
		}
		for _, done := range results {
			total += <-done
		}
	}
	return total
}

func echo(ping <-chan int64, pong chan<- int64, echoed chan<- int64) {
	var count int64
	for value := range ping {
		pong <- value + 1
		count++
	}
	echoed <- count
}

func pingPong() string {
	ping := make(chan int64, 1)
	pong := make(chan int64, 1)
	echoed := make(chan int64, 1)
	go echo(ping, pong, echoed)
	var total int64
	for i := int64(0); i < trips; i++ {
		ping <- i
		total += <-pong
	}
	close(ping)
	return fmt.Sprintf("traded=%d echoed=%d", total, <-echoed)
}

func main() {
	runtime.GOMAXPROCS(1)
	launched := launchAndJoin()
	fmt.Printf("task_switch launched=%d %s\n", launched, pingPong())
}
