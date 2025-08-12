# 95. Unique Binary Search Trees II

---
**Difficulty:** Medium
**Tags:** Tree, Binary Tree, Binary Search Tree, Recursion, Backtracking, Dynamic Programming
**Company:** Meta, Amazon, Google, Microsoft
___
## 🧠 Problem

Given an integer `n`, return _all the structurally unique **BST'**s (binary search trees), which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`. Return the answer in **any order**.

### ✳️ Examples

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

	**Input:** n = 3
	**Output:** [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

**Example 2:**

	**Input:** n = 1
	**Output:** [[1]]

---
## 📌 Constraints

- `1 <= n <= 8`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(n * C(n)), S.C: O(n * C(n)); C(n): nth Catalan Number
        - For each root value from start to end, recursively build all left and right subtree.
        - Combine all possible left-right subtree pairs to form unique BSTs.
        - Total number of unique trees formed is given by the Catalan number C(n).
 
---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`95.c`](./95.c)     |   O(n * C(n))   |   O(n * C(n))    |
| C++      | [`95.cpp`](./95.cpp) |   O(n * C(n))   |   O(n * C(n))    |
| Python   | [`95.py`](./95.py)   |   O(n * C(n))   |   O(n * C(n))    |
| Rust     | [`95.rs`](./95.rs)   |   O(n * C(n))   |   O(n * C(n))    |
