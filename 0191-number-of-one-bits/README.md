# 191. Number of 1 Bits

---

- **Difficulty:** Easy
- **Tags:** Bit Manipulation, Divide and Conquer
- **Company:** Amazon, Google, Meta, Box, Apple

---

## 🧠 Problem

Given a positive integer `n`, return the number of set bits in its binary
representation (also known as the **Hamming weight**).

### ✳️ Examples

**Example 1:**

- Input: `n = 11`
- Output: `3`
- Explanation: `11` in binary is `1011`, which has 3 set bits.

**Example 2:**

- Input: `n = 128`
- Output: `1`
- Explanation: `128` in binary is `10000000`, which has 1 set bit.

**Example 3:**

- Input: `n = 2147483645`
- Output: `30`
- Explanation: `2147483645` in binary is `1111111111111111111111111111101`, which has 30 set bits.

---

## 📌 Constraints

- `1 <= n <= 2^31 - 1`

---

## 🚀 Approaches

1. **Bit Shift** -- T.C: O(1), S.C: O(1)
   Check each of the 32 bits one at a time by extracting the LSB with `n & 1`,
   then right shifting `n` by 1. Count all bits that are set.

2. **Brian Kernighan Algorithm** -- T.C: O(k), S.C: O(1); k = number of set bits.
   `n & (n - 1)` clears the lowest set bit of `n`. Repeat until `n` is zero,
   counting iterations. Only iterates as many times as there are set bits —
   faster in practice for sparse bit patterns.

---

## 💻 Solutions

| Language | File                   | Approach        | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------------- | :-------------: | :--------------: |
| C        | [`191.c`](./191.c)     | Brian Kernighan |      O(1)       |       O(1)       |
| C++      | [`191.cpp`](./191.cpp) | Brian Kernighan |      O(1)       |       O(1)       |
| Python   | [`191.py`](./191.py)   | Brian Kernighan |      O(1)       |       O(1)       |
| Rust     | [`191.rs`](./191.rs)   | Brian Kernighan |      O(1)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  n = 11
Output: 3

Input:  n = 128
Output: 1

Input:  n = 2147483645
Output: 30

Input:  n = 1
Output: 1

Input:  n = 2147483647
Output: 31
```
