# 498. Diagonal Traverse

---
**Difficulty:** Medium
**Tags:** Array, Matrix, Simulation
**Company:** Meta, Walmart, Liftoff, Google
___
## 🧠 Problem

Given an `m x n` matrix `mat`, return _an array of all the elements of the array in a diagonal order_.

### ✳️ Examples

**Example 1:**

	**Input:** mat = [[1,2,3],[4,5,6],[7,8,9]]
	**Output:** [1,2,4,7,5,3,6,8,9]
	
**Example 2:**

	**Input:** mat = [[1,2],[3,4]]
	**Output:** [1,2,3,4]

---
## 📌 Constraints

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 104`
- `1 <= m * n <= 104`
- `-105 <= mat[i][j] <= 105`

---

## 🚀 Approach

Use `simulation` technique
 - Observation: Move up if (row + col) is even, down if it's odd.
 - While moving up: row--, col++
 - While moving down: row++, col--
 - Handle boundaries carefully to avoid index errors.

Time Complexity: O(n * m)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`498.c`](./498.c)     |    O(n * m)     |       O(1)       |
| C++      | [`498.cpp`](./498.cpp) |    O(n * m)     |       O(1)       |
| Python   | [`498.py`](./498.py)   |    O(n * m)     |       O(1)       |
| Rust     | [`498.rs`](./498.rs)   |    O(n * m)     |       O(1)       |
