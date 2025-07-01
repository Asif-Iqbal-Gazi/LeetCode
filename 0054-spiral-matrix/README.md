# 54. Spiral Matrix

---
**Difficulty:** Medium
**Tags:** Array, Matrix, Simulation
**Company:** Amazon, Google, Tiktok, Microsoft, Meta
___
## 🧠 Problem

Given an `m x n` `matrix`, return _all elements of the_ `matrix` _in spiral order_.

### ✳️ Examples

**Example 1:**

	**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
	**Output:** [1,2,3,6,9,8,7,4,5]

**Example 2:**

	**Input:** matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
	**Output:** [1,2,3,4,8,12,11,10,9,5,6,7]

---
## 📌 Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

---

## 🚀 Approach

Simulation
- Simulate traversal in sequence: right --> down --> left --> up.
- Maintain four bounds (up, down, left, right) that shrinks inward as we complete each layer.
- Traverse in the current direction until hitting the boundary, then change direction.

Time Complexity: O(m * n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`54.c`](./54.c)     |    O(m * n)     |       O(1)       |
| C++      | [`54.cpp`](./54.cpp) |    O(m * n)     |       O(1)       |
| Python   | [`54.py`](./54.py)   |    O(m * n)     |       O(1)       |
| Rust     | [`54.rs`](./54.rs)   |    O(m * n)     |       O(1)       |
