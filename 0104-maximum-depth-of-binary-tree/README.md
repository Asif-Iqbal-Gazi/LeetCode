# 104. Maximum Depth of Binary Tree

---
**Difficulty:** Easy
**Tags:** Tree, Binary Tree, Depth-First Search, Breadth-First Search
**Company:** Google, Microsoft, Bloomberg, Amazon
___
## 🧠 Problem

Given the `root` of a binary tree, return _its maximum depth_.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

### ✳️ Examples

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

	**Input:** root = [3,9,20,null,null,15,7]
	**Output:** 3

**Example 2:**

	**Input:** root = [1,null,2]
	**Output:** 2

---
## 📌 Constraints

- The number of nodes in the tree is in the range `[0, 104]`.
- `-100 <= Node.val <= 100`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(N), S.C: O(N)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`104.c`](./104.c)     |      O(n)       |       O(1)       |
| C++      | [`104.cpp`](./104.cpp) |      O(n)       |       O(1)       |
| Python   | [`104.py`](./104.py)   |      O(n)       |       O(1)       |
| Rust     | [`104.rs`](./104.rs)   |      O(n)       |       O(1)       |
