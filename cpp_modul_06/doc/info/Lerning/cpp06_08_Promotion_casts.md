[back](cpp06_07_explicit_keyword.md) | [main](/) | [forward](cpp06_00_lerning.md) > 

---

## Promotion Casts
In C++, there are automatic ("implicit") type conversions that can occur when smaller data types are converted to larger data types without you explicitly using a cast (e.g., (int), (float)). These conversions are called `Promotion Casts`. They are safe because no information is lost.

A classic example:

When you convert a `char` (1 byte) to an `int` (4 bytes), this happens automatically because there is no loss of information. This is a promotion cast.

```cpp
Copy code
char c = 'A';
int i = c; // implicit promotion cast from char to int
```

Here, `c` would automatically be converted to `i` because `int` has enough memory space to accommodate the `char` value.
