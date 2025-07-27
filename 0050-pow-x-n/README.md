# 50. Pow(x, n)

---
**Difficulty:** Medium
**Tags:** Math, Recursion
**Company:** Meta, Google, Amazon, Microsoft
___
## 🧠 Problem

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., `xn`).

### ✳️ Examples

**Example 1:**

**Input:** x = 2.00000, n = 10
**Output:** 1024.00000

**Example 2:**

**Input:** x = 2.10000, n = 3
**Output:** 9.26100

**Example 3:**

**Input:** x = 2.00000, n = -2
**Output:** 0.25000
**Explanation:** 2^-2 = 1/2^2 = 1/4 = 0.25

---
## 📌 Constraints

- `-100.0 < x < 100.0`
- `-2^31 <= n <= 2^31-1`
- `n` is an integer.
- Either `x` is not zero or `n > 0`.
- `-10^4 <= x^n <= 10^4`

---

## 🚀 Approach

1. **Binary Exponentiation** -- T.C: O(log N), S.C: O(N)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`50.c`](./50.c)     |    O(log N)     |       O(1)       |
| C++      | [`50.cpp`](./50.cpp) |    O(log N)     |       O(1)       |
| Python   | [`50.py`](./50.py)   |    O(log N)     |       O(1)       |
| Rust     | [`50.rs`](./50.rs)   |    O(log N)     |       O(1)       |
