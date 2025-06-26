# 1051. Height Checker

---
**Difficulty:** Easy
**Tags:** Array, Sorting, Counting Sort
**Company:** IBM, Google, Microsoft, Amazon
___
## 🧠 Problem

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in **non-decreasing order** by height. Let this ordering be represented by the integer array `expected` where `expected[i]` is the expected height of the `ith` student in line.

You are given an integer array `heights` representing the **current order** that the students are standing in. Each `heights[i]` is the height of the `ith` student in line (**0-indexed**).

Return _the **number of indices** where_ `heights[i] != expected[i]`.

### ✳️ Examples

**Example 1:**

	**Input:** heights = [1,1,4,2,1,3]
	**Output:** 3
	**Explanation:** 
	heights:  [1,1,4,2,1,3]
	expected: [1,1,1,2,3,4]
	Indices 2, 4, and 5 do not match.

**Example 2:**

	**Input:** heights = [5,1,2,3,4]
	**Output:** 5
	**Explanation:**
	heights:  [5,1,2,3,4]
	expected: [1,2,3,4,5]
	All indices do not match.

**Example 3:**

	**Input:** heights = [1,2,3,4,5]
	**Output:** 0
	**Explanation:**
	heights:  [1,2,3,4,5]
	expected: [1,2,3,4,5]
	All indices match.

---
## 📌 Constraints

- `1 <= heights.length <= 100`
- `1 <= heights[i] <= 100`

---

## 🚀 Approach

Use **Counting Sort** (heights[i] <= 100, small constant memory) to simulate the sorted order without actually sorting, then count mismatches with the original array.

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                     | Time Complexity | Space Complexity |
| -------- | ------------------------ | :-------------: | :--------------: |
| C        | [`1051.c`](./1051.c)     |      O(n)       |       O(1)       |
| C++      | [`1051.cpp`](./1051.cpp) |      O(n)       |       O(1)       |
| Python   | [`1051.py`](./1051.py)   |      O(n)       |       O(1)       |
| Rust     | [`1051.rs`](./1051.rs)   |      O(n)       |       O(1)       |
