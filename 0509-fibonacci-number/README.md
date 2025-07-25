# 509. Fibonacci Number

---
**Difficulty:** Easy
**Tags:** Math, Dynamic Programming, Recursion, Memoization
**Company:** 
___
## 🧠 Problem

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given `n`, calculate `F(n)`.

### ✳️ Examples

**Example 1:**

	**Input:** n = 2
	**Output:** 1
	**Explanation:** F(2) = F(1) + F(0) = 1 + 0 = 1.

**Example 2:**

	**Input:** n = 3
	**Output:** 2
	**Explanation:** F(3) = F(2) + F(1) = 1 + 1 = 2.

**Example 3:**

	**Input:** n = 4
	**Output:** 3
	**Explanation:** F(4) = F(3) + F(2) = 2 + 1 = 3.

---
## 📌 Constraints

- `0 <= n <= 30`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(2^N), S.C: O(N)
2. **Dynamic Programming** -- T.C: O(N), S.C: O(1)
---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`509.c`](./509.c)     |      O(n)       |       O(1)       |
| C++      | [`509.cpp`](./509.cpp) |      O(n)       |       O(1)       |
| Python   | [`509.py`](./509.py)   |      O(n)       |       O(1)       |
| Rust     | [`509.rs`](./509.rs)   |      O(n)       |       O(1)       |
