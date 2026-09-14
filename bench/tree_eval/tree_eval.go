// Go peer of bench/tree_eval.vader. Go's sum type is an interface with a
// private marker method, and its dispatch is a type switch.

package main

import "fmt"

const (
	treeDepth  = 17
	passCount  = 100
	maxLiteral = 9
)

type Expression interface{ isExpression() }

type Literal struct{ value int64 }
type Add struct{ left, right Expression }
type Subtract struct{ left, right Expression }
type Negate struct{ operand Expression }

func (Literal) isExpression()  {}
func (Add) isExpression()      {}
func (Subtract) isExpression() {}
func (Negate) isExpression()   {}

func evaluate(expression Expression) int64 {
	switch node := expression.(type) {
	case Literal:
		return node.value
	case Add:
		return evaluate(node.left) + evaluate(node.right)
	case Subtract:
		return evaluate(node.left) - evaluate(node.right)
	case Negate:
		return -evaluate(node.operand)
	}
	panic("unreachable")
}

// The seed descends the tree deterministically, so the shape and every literal
// are identical in all four ports. Negate wraps a binary node rather than taking
// one child, which keeps the tree balanced.
func build(depth int32, seed int32) Expression {
	if depth == 0 {
		return Literal{value: int64(seed%maxLiteral + 1)}
	}
	left := build(depth-1, seed*2+1)
	right := build(depth-1, seed*2+2)
	switch seed % 3 {
	case 0:
		return Add{left: left, right: right}
	case 1:
		return Subtract{left: left, right: right}
	default:
		return Negate{operand: Add{left: left, right: right}}
	}
}

func main() {
	root := build(treeDepth, 1)
	var total int64
	for pass := 0; pass < passCount; pass++ {
		total += evaluate(root)
	}
	fmt.Printf("tree_eval depth=%d passes=%d total=%d\n", treeDepth, passCount, total)
}
