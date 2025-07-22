# 118. Pascal's Triangle

---
**Difficulty:** Easy
**Tags:** Array, Dynamic Programming
**Company:** Google, Microsoft, Amazon
___
## 🧠 Problem

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:
![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

### ✳️ Examples

**Example 1:**

	**Input:** rowIndex = 3
	**Output:** [1,3,3,1]

**Example 2:**

	**Input:** rowIndex = 0
	**Output:** [1]

**Example 3:**

	**Input:** rowIndex = 1
	**Output:** [1,1]

---
## 📌 Constraints

- `1 <= numRows <= 33`

---

## 🚀 Approach

Use **Simulation** to build Pascal’s Triangle row by row:

- Start with the first two base rows: `[1]` and `[1, 1]`.
- For each subsequent row:
  - Set the first and last elements as `1`.
  - Each middle element is the sum of the two elements directly above it from the previous row.

Time Complexity: O(n^2)
Space complexity: O(n^2)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`118.c`](./118.c)     |     O(n^2)      |      O(n^2)      |
| C++      | [`118.cpp`](./118.cpp) |     O(n^2)      |      O(n^2)      |
| Python   | [`118.py`](./118.py)   |     O(n^2)      |      O(n^2)      |
| Rust     | [`118.rs`](./118.rs)   |     O(n^2)      |      O(n^2)      |
