# 67. Add Binary

---
**Difficulty:** Easy
**Tags:** Math, String, Bit Manipulation, Simulation
**Company:** Google, Meta, Bloomberg, Amazon
___
## 🧠 Problem

Given two binary strings `a` and `b`, return _their sum as a binary string_.

### ✳️ Examples

**Example 1:**

	**Input:** a = "11", b = "1"
	**Output:** "100"

**Example 2:**

	**Input:** a = "1010", b = "1011"
	**Output:** "10101"

---
## 📌 Constraints

- `1 <= a.length, b.length <= 104`
- `a` and `b` consist only of `'0'` or `'1'` characters.
- Each string does not contain leading zeros except for the zero itself.

---

## 🚀 Approach

Use `Simulation`
- Start from the end of both strings
- Keep adding digits and carry
- Preallocate the result string with size = max(len(a), len(b)) + 1
- Fill the result string from the back using a decrementing index.
- At the end, check for a leading '0' and strip it if unused.
 

Time Complexity: O(max(n, m))
Space complexity: O(max(n, m))

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`67.c`](./67.c)     |  O(max(m, n))   |   O(max(n, m))   |
| C++      | [`67.cpp`](./67.cpp) |  O(max(m, n))   |   O(max(n, m))   |
| Python   | [`67.py`](./67.py)   |  O(max(m, n))   |   O(max(n, m))   |
| Rust     | [`67.rs`](./67.rs)   |  O(max(m, n))   |   O(max(n, m))   |
