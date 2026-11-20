// Go peer of bench/tasks_alloc.vader. A goroutine is the task, a channel that
// carries its one result the join. GOMAXPROCS sets the cores, as VADER_THREADS
// does for Vader.

package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	tasks  = 16
	rounds = 30_000
)

func churn(seed int) int64 {
	var total int64
	for i := 0; i < rounds; i++ {
		parts := []string{}
		for j := 0; j < 4; j++ {
			parts = append(parts, strconv.Itoa(seed)+"-"+strconv.Itoa(i)+"-"+strconv.Itoa(j))
		}
		total += int64(len(strings.Join(parts, ",")))
	}
	return total
}

func main() {
	results := make([]chan int64, tasks)
	for k := 0; k < tasks; k++ {
		seed := k
		done := make(chan int64, 1)
		results[k] = done
		go func() { done <- churn(seed) }()
	}
	var total int64
	for _, done := range results {
		total += <-done
	}
	fmt.Printf("tasks_alloc total=%d\n", total)
}
