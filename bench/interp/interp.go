// Go peer of bench/interp/interp.vader. Same algorithm (assemble a string from
// three integers, 200 000 times), same checksum. Go has no string
// interpolation ; a strings.Builder + strconv.Itoa mirrors the StringBuilder +
// int-formatter path that Vader's `${}` and the Java port use. (fmt.Sprintf
// would instead measure reflection + arg boxing, off the workload.) `len(s)`
// is the byte length, matching Vader's bytes().len().

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var total int64
	for i := 0; i < 200000; i++ {
		var b strings.Builder
		b.WriteString("val=")
		b.WriteString(strconv.Itoa(i))
		b.WriteString(" x=")
		b.WriteString(strconv.Itoa(i * 2))
		b.WriteString(" y=")
		b.WriteString(strconv.Itoa(i - 1))
		s := b.String()
		total += int64(len(s))
	}
	fmt.Printf("interp %d\n", total)
}
