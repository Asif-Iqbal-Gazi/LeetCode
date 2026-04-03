# 190. Reverse Bits

---

- **Difficulty:** Easy
- **Tags:** Bit Manipulation, Divide and Conquer
- **Company:** Google, Amazon, Meta, Bloomberg, Apple, Nvidia

---

## 🧠 Problem

Reverse bits of a given 32 bits signed integer.

### ✳️ Examples

**Example 1:**

- Input: n = 43261596
- Output: 964176192
- Explanation:

  | Integer   | Binary                           |
  | --------- | -------------------------------- |
  | 43261596  | 00000010100101000001111010011100 |
  | 964176192 | 00111001011110000010100101000000 |

**Example 2:**

- Input: n = 2147483644
- Output: 1073741822
- Explanation:

  | Integer    | Binary                           |
  | ---------- | -------------------------------- |
  | 2147483644 | 01111111111111111111111111111100 |
  | 1073741822 | 00111111111111111111111111111110 |

---

## 📌 Constraints

- `0 <= n <= 2^31 - 2`
- `n` is even.

---

## 🚀 Approach

1. **Bit Manipulation** -- T.C: O(1), S.C: O(1)
   Iterate over all 32 bits. Extract the `i`-th bit from `n` using `(n >> i) & i`, then place it at position `31 - i` in the result using `bit << (31 - i)`.
   Use `uint32_t` in C/C++ to guarantee logical (not arithmetic) right shifts and avoid undefined behavior when shifting into the sign bit.

2. **Divide and Conquer (Byte Swap)** -- T.C: O(1), S.C: O(1)
   Split the 32-bit integer into smaller chunks (bytes or nibbles), reverse the bits within each chunk using lookup table, then reassemble in reverse order.
   Useful when the function in called repeatedly - the lookup table can be cached.

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`190.c`](./190.c)     |      O(1)       |       O(1)       |
| C++      | [`190.cpp`](./190.cpp) |      O(1)       |       O(1)       |
| Python   | [`190.py`](./190.py)   |      O(1)       |       O(1)       |
| Rust     | [`190.rs`](./190.rs)   |      O(1)       |       O(1)       |
