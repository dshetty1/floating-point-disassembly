# floating-point-disassembly

### Description
Disassemble a single-precision (32-bit) floating point number into 3 separate components, based on the IEEE 754 format:
- s: sign (either 1 or -1)
- M: mantissa/significand (a floating point number in base 10 in the range [0.0,2.0) )
- E: exponent (an integer in base 10)

The original floating point number should then be equal to the product (-1)^s * M * 2^E.

Program also, differentiates between normalized, denormalized, and special values (+/- infinity, NaN)

### Input
A floating point number (positive or negative).

### Output
Three numbers each on a seperate line corresponding to s, E and M.
- s should be always either 1 or -1
- E should be printed as an integer in base 10
- M should be printed as a floating point number in base 10 with exactly 1 digit before the decimal point and 20 digits after the decimal point.

