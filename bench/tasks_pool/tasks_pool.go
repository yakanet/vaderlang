// Go peer of bench/tasks_pool.vader. Goroutines are the workers, channels of
// capacity 64 carry the jobs and the results. GOMAXPROCS sets the cores, as
// VADER_THREADS does for Vader.

package main

import "fmt"

const (
	workers = 8
	jobs    = 20_000
	steps   = 5_000
	modulus = 1_000_000_007
)

func work(n int64) int64 {
	acc := n
	for i := int64(0); i < steps; i++ {
		acc = (acc*31 + i) % modulus
	}
	return acc
}

func worker(jobQueue <-chan int64, results chan<- int64, done chan<- int64) {
	var count int64
	for job := range jobQueue {
		results <- work(job)
		count++
	}
	done <- count
}

func main() {
	jobQueue := make(chan int64, 64)
	results := make(chan int64, 64)
	done := make(chan int64, workers)
	for w := 0; w < workers; w++ {
		go worker(jobQueue, results, done)
	}
	go func() {
		for n := int64(0); n < jobs; n++ {
			jobQueue <- n
		}
		close(jobQueue)
	}()
	var sum int64
	for i := 0; i < jobs; i++ {
		sum = (sum + <-results) % modulus
	}
	var count int64
	for w := 0; w < workers; w++ {
		count += <-done
	}
	fmt.Printf("tasks_pool done=%d sum=%d\n", count, sum)
}
