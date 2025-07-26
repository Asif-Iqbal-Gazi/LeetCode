# 70. Counting Stairs

---
**Difficulty:** Easy
**Tags:** Math, Recursion, Dynamic Programming
**Company:** Google, Amazon, Meta, Microsoft, Apple, Bloomberg
___
## 🧠 Problem

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

### ✳️ Examples

**Example 1:**

	**Input:** n = 2
	**Output:** 2
	**Explanation:** There are two ways to climb to the top.
	1. 1 step + 1 step
	2. 2 steps

**Example 2:**

	**Input:** n = 3
	**Output:** 3
	**Explanation:** There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step

---
## 📌 Constraints

- `1 <= n <= 45`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(2^N), S.C: O(N)
2. **Dynamic Programming** -- T.C: O(N), S.C: O(1)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`70.c`](./70.c)     |      O(n)       |       O(1)       |
| C++      | [`70.cpp`](./70.cpp) |      O(n)       |       O(1)       |
| Python   | [`70.py`](./70.py)   |      O(n)       |       O(1)       |
| Rust     | [`70.rs`](./70.rs)   |      O(n)       |       O(1)       |
