// Go peer of bench/binary_trees.vader. Same recursive build + count
// algorithm with a Node struct holding value + left/right pointers.

package main

import "fmt"

const DEPTH = 17

type Node struct {
	value int32
	left  *Node
	right *Node
}

func buildTree(depth, value int32) *Node {
	if depth == 0 {
		return &Node{value: value}
	}
	return &Node{
		value: value,
		left:  buildTree(depth-1, value*2),
		right: buildTree(depth-1, value*2+1),
	}
}

func countNodes(t *Node) int32 {
	if t == nil {
		return 0
	}
	return 1 + countNodes(t.left) + countNodes(t.right)
}

func main() {
	tree := buildTree(DEPTH, 1)
	count := countNodes(tree)
	fmt.Printf("binary_trees depth=%d count=%d\n", DEPTH, count)
}
