# 0181: The float formatter is Schubfach, on the parser's table

## Status

Accepted (2026-11-26). Replaces the Ryu core that 0019 measured.

## Context

`f64.to_string()` and `f32.to_string()` ran two ports of Ryu: `d2d` and `f2d`,
270 lines whose larger half kept track of the trailing zeros of what each
division dropped, so the last digit could be rounded. They read four tables of
powers of five, computed by `@comptime` with the big integers of `bigint.vader`
on every compilation of a program that prints a float. `parse_float` reads a
fifth, `POW5_128`, built the same way.

## Decision

- The decimal comes from Schubfach (Giulietti, 2020, as OpenJDK's
  `DoubleToDecimal` and `FloatToDecimal` implement it). A product rounded to
  odd keeps, in its last bit, whether the division was exact, and the choice
  among the candidates takes a few comparisons, with no loop. One core serves
  `f64` and `f32`.
- The powers of ten are read from `POW5_128`: a power of ten and the power of
  five of the same exponent have the same normalized mantissa. The table grows
  by the 16 rows the smallest subnormals need, and holds every row truncated:
  the parser rounds up, as it reads them, the rows fast_float holds rounded
  (exponents -27 to -1).
- The output stays Ryu's. Java keeps two digits where one reads back
  (`4.9E-324`), and scales the smallest subnormals by ten to find them: both
  are left out, so `5e-324` stays `5e-324`.
- The two ends of the interval are not multiplied apart: they differ from the
  value by `g` shifted, so one product gives all three.

Checked against Ryu before it was removed: every positive `f32`, 2 billion
random `f64`, and 67 million chosen ones (every subnormal significand under
2^24, the powers of two and their neighbours, the integers around 2^24 and
2^53), with no difference. 20 million random `f64` read back, through
`parse_float`, as the same bits.

## Consequences

- 866 lines become 531: `f2s.vader` and `dtoa_tables.vader` go, and
  `parse_float_tables.vader` becomes `powers_of_five.vader`, read by both.
- A `vader check` of a program that prints a float takes about 3.5 ms less, the
  four Ryu tables no longer computed.
- The core alone runs about 40 % faster than Ryu's, mostly because it
  allocates nothing: it hands its decimal back as a tuple. Rendering a float is
  still dominated by interning the string (0019).
