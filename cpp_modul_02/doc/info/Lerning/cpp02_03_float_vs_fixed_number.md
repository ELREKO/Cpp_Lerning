<[back](cpp02_02_orthodox_canonical.md) | [main](/) | [forward](cpp02_00_lerning.md) >

--- 

# Floating Point Numbers
**Learning from C++_02 -> ex_00**

[1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)  
**Accuracy vs. Precision**
- **Integer numbers** are *very accurate*, but not always precise enough when it comes to finer gradations. They can only represent whole values without decimal places.
- **Floating point numbers**, on the other hand, offer *high precision* by being able to store decimal values. However, they are *not always accurate* due to the limited mantissa length and exponent, often leading to rounding errors. This results in inaccuracies in calculations.

[2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)  
**Representation of Floating Point Numbers (Float)**
- Floating point numbers are represented in memory according to the IEEE 754 standard. A 32-bit float number is divided into three main components:
  
  `seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm`  
  **s = Sign bit**  
  **e = Exponent**  
  **m = Mantissa (fraction)**

- **Sign bit (S)**: The most significant bit (position 31) determines the sign. `0` means positive, `1` means negative.
- **Exponent (E)**: Occupies bits from position 30 to 23 and stores the biased exponent (with a bias to represent negative exponents).
- **Mantissa (M)**: The remaining bits (positions 22 to 0) represent the significant digits of the number. The mantissa always implicitly starts with `1`.

Example of a float number:
```
1 + 1/2 + 0/4 + 1/8 + 1/16 = 1.6875
```

### Float Comparison
Floating point numbers are *not directly suitable for comparison* due to rounding errors. This is because of the limited precision with which numbers are stored. Instead of direct comparison using `==`, comparisons often account for a small tolerance (epsilon):

- The smallest difference (machine precision) in a `float` is represented by *epsilon*. For a 32-bit float, this value is typically:
  ```
  Epsilon ≈ 1.1920929e-7
  ```
- This represents the minimal difference that two adjacent floating point numbers can have.

### Overflow
- For **integers**, overflow often results in wrapping around to zero or another value, without clear detection.
- For **floating point numbers**, overflow is typically represented by positive or negative infinity (`+∞` or `-∞`), making overflow easier to detect.
- Be cautious when converting between `float` and `int`, as this may lead to unexpected results, especially when overflow occurs.

A potential solution to avoid overflow is using **double**, as this format allocates more bits for both the exponent and mantissa, allowing for larger values and higher precision.

---

# Fixed Point Numbers

In contrast to [Floating Point Numbers](#Floating-Point-Numbers), **Fixed Point Numbers** are a good alternative to:
- Achieve **higher performance**, as only integers are processed.
- Ensure **higher accuracy** compared to floating point numbers.
- Improve **comparability**, as there are no rounding errors.

### Fixed Point Number Calculations
Fixed point numbers are represented by a fixed number of bits for the integer and fractional part. This is specified by the format `fixed<w,b>`, where:
- `w` is the total number of bits (including the sign bit).
- `b` is the number of bits reserved for the fractional part.

**Example:**
- Consider the number `2.75` in the `fixed<8,3>` format:
  ```
  2.75 (decimal) = 00010.110 (binary)
  ```
  This can be broken down as:
  ```
  2^1 + 2^(-1) + 2^(-2) = 2.75
  ```

The `fixed<8,3>` format means that a total of 8 bits are available, with 3 bits reserved for the fractional part. The remaining 5 bits (including a sign bit, if necessary) represent the integer part.

**Binary Number Calculations:**
The binary representation of a fixed point number can be calculated by its exact value. For instance:
```
0x2^4 + 0x2^3 + 0x2^2 + 1x2^1 + 0x2^0 + 1x2^(-1) + 1x2^(-2) + 0x2^(-3)
```
- Integer part: `2^1 = 2`
- Fractional part: `2^(-1) + 2^(-2) = 0.75`

Thus, the value of the number is: `2 + 0.75 = 2.75`.

### Advantages and Disadvantages of Fixed Point Numbers:
- **Advantages**: Fast computation and consistent precision. They are useful for embedded systems or environments with limited memory and processing power.
- **Disadvantages**: They cannot represent values as large or as fine as floating point numbers due to the limited number of bits.
