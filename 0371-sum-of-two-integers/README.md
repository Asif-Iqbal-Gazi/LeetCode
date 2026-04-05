# 371. Sum of Two Integers

---

- **Difficulty:** Medium
- **Tags:** Math, Bit Manipulation
- **Company:** Google, Amazon, Meta, Microsoft, Apple, Bloomberg

---

## 🧠 Problem

Given two integers `a` and `b`, return the sum of the two integers without
using the operators `+` and `-`.

### ✳️ Examples

**Example 1:**

- Input: `a = 1, b = 2`
- Output: `3`

**Example 2:**

- Input: `a = 2, b = 3`
- Output: `5`

---

## 📌 Constraints

- `-1000 <= a <= 1000`
- `-1000 <= b <= 1000`

---

## 🚀 Approaches

### Approach 1 — Bit Manipulation (Iterative)

Use XOR to add bits without carry, and AND shifted left by 1 to compute the
carry. Repeat until carry is zero.

- `a ^ b` → sum without carry
- `(a & b) << 1` → carry

Time Complexity: **O(1)** — bounded by 32-bit integer width.
Space Complexity: **O(1)**.

---

### Approach 2 — Bit Manipulation (Recursive)

Same logic as Approach 1 but expressed recursively. Base case: when `b == 0`,
no carry remains — return `a`.

Time Complexity: **O(1)**.
Space Complexity: **O(1)**.

---

## 💻 Solutions

| Language | File                   | Approach  | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------- | :-------------: | :--------------: |
| C        | [`371.c`](./371.c)     | Iterative |      O(1)       |       O(1)       |
| C++      | [`371.cpp`](./371.cpp) | Iterative |      O(1)       |       O(1)       |
| Python   | [`371.py`](./371.py)   | Iterative |      O(1)       |       O(1)       |
| Rust     | [`371.rs`](./371.rs)   | Iterative |      O(1)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  a = 1, b = 2
Output: 3

Input:  a = 2, b = 3
Output: 5

Input:  a = -1, b = 1
Output: 0

Input:  a = -7, b = 3
Output: -4

Input:  a = 0, b = 0
Output: 0
```
