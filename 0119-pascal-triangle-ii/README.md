# 119. Pascal's Triangle II

---
**Difficulty:** Easy
**Tags:** Array, Dynamic Programming
**Company:** 
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

- `0 <= rowIndex <= 33`

---

## 🚀 Approach

1. **Dynamic Programming, Bottom-up** -- T.C: O(N^2), S.C: O(N)
   - Initialize result vector of size rowIndex+1 with 1's
   - For each row, update elements in-place from right to left:
       res[i] = res[i] + res[i-1]
   - Return res after building up to rowIndex
 
---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`119.c`](./119.c)     |      O(n)       |       O(n)       |
| C++      | [`119.cpp`](./119.cpp) |      O(n)       |       O(n)       |
| Python   | [`119.py`](./119.py)   |      O(n)       |       O(n)       |
| Rust     | [`119.rs`](./119.rs)   |      O(n)       |       O(n)       |
