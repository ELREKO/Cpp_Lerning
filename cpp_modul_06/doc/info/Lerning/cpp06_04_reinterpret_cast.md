
[back](cpp06_03_static_and_dynamic_cast.md) | [main](/) | [forward](cpp06_05_const_cast.md) > 

---

# Reinterpret Cast

`reinterpret_cast` does not alter the actual data in memory. It merely changes the way that data is interpreted. This can lead to unexpected and often nonsensical results.

## Using `reinterpret_cast`
- It should only be used when the conversion is valid, which requires precise knowledge. No safety checks are performed on the type conversion. Better to use `dynamic_cast`.

- Suitable for system programming, such as low-level memory operations, e.g., implementing a memory manager or working with a specific hardware interface.

- It is used to cast between incompatible types, such as converting pointers to completely different data types or converting a pointer to an integer type and vice versa.

## Examples

### Example to Illustrate the Danger of `reinterpret_cast`
```cpp
#include <iostream>
#include <bitset>

int main() {
    int a = 42;
    // Cast int pointer to a double pointer
    double* b = reinterpret_cast<double*>(&a);
 
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of b: " << b << std::endl;
    
    std::cout << "Original value of a: " << a << std::endl;
    // Undefined behavior
    std::cout << "Value of b (reinterpret_cast): " << *b << std::endl;

    std::bitset<sizeof(int) * 8> bits_a(a);
    std::cout << "Bits: " << bits_a << std::endl;
    std::bitset<sizeof(double) * 8> bits_b(*b);
    std::cout << "Bits: " << bits_b << std::endl;
    return 0;
}
```

As seen, the result is nonsensical. The address is the same, but the value is incorrectly interpreted. An `explicit cast` would be more appropriate here.

```bash
Address of a: 0x7ffcbe49b298
Address of b: 0x7ffcbe49b298
Original value of a: 42
Value of b (reinterpret_cast): 2.07508e-322
Bits: 00000000000000000000000000101010
Bits: 0000000000000000000000000000000000000000000000000000000000000000
```

### More Appropriate Example
Suppose there's an interface, such as hardware, and data is transferred into a buffer.

```cpp
#include <iostream>
#include <cstring>  // For std::memcpy and std::strlen
#include <iomanip>  // For std::hex and std::dec

/* Actually, Data is only 16 bytes large, but padding adds extra bytes. See the output of the loop. */
struct Data {
    int id;      // 4 Bytes
    double value; // 8 Bytes
    int score;   // 4 Bytes
};

int main() {
    // Create a buffer large enough to hold the Data structure
    char buffer[sizeof(Data)];

    // Create a sample Data object
    Data data = {42, 3.14, 100};  

    // Copy the data into the buffer
    std::memcpy(buffer, &data, sizeof(Data));

    // Output the buffer contents in hexadecimal format
    std::cout << "Buffer contents in hex: ";
    for (size_t i = 0; i < sizeof(Data); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)buffer[i] << " ";
    }
    std::cout << std::dec << std::endl;

    // Access the data as a 'Data' structure and output the data
    std::cout << "ID: " << *reinterpret_cast<int *>(buffer) << std::endl;
    std::cout << "Value: " << *reinterpret_cast<double *>(buffer + 4) << std::endl;
    std::cout << "Score: " << *reinterpret_cast<int *>(buffer + 12) << std::endl;

    // Another form of output
    Data dataPtr = *reinterpret_cast<Data *>(buffer);
    std::cout << "ID: " << dataPtr.id << std::endl;
    std::cout << "Value: " << dataPtr.value << std::endl;
    std::cout << "Score: " << dataPtr.score << std::endl;

    // Another example from the video

    return 0;
}
```

### Casting from Integer to Pointer
For example, when a layout requires a pointer but the input does not provide a pointer.

```cpp
#include <iostream>
#include <bitset>

int main() {
    int a = 42;
    // Cast int pointer to an int pointer
    int* b = reinterpret_cast<int*>(&a);
 
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of b: " << b << std::endl;
    
    std::cout << "Original value of a: " << a << std::endl;
    // Undefined behavior
    std::cout << "Value of b (reinterpret_cast): " << *b << std::endl;

    std::bitset<sizeof(int) * 8> bits_a(a);
    std::cout << "Bits: " << bits_a << std::endl;
    std::bitset<sizeof(int) * 8> bits_b(*b);
    std::cout << "Bits: " << bits_b << std::endl;
    return 0;
}
