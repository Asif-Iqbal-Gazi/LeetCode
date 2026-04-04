# 226. Invert Binary Tree

---

- **Difficulty:** Easy
- **Tags:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Company:** Google, Amazon, Meta, Microsoft, Apple

---

## 🧠 Problem

Given the `root` of a binary tree, invert the tree, and return its `root`.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

- Input: `root = [4,2,7,1,3,6,9]`
- Output: `[4,7,2,9,6,3,1]`

**Example 2:**
![Example 2](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

- Input: `root = [2,1,3]`
- Output: `[2,3,1]`

**Example 3:**

- Input: `root = []`
- Output: `[]`

---

## 📌 Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

---

## 🚀 Approaches

### Approach 1 — Recursive DFS

Recursively invert the left and right subtrees, then swap them at the current
node. The base case is a null node — return immediately.

Time Complexity: **O(N)** — every node is visited once.
Space Complexity: **O(N)** — recursion call stack, O(log N) for balanced tree.

---

### Approach 2 — Iterative BFS

Use a queue to traverse the tree level by level. At each node, swap its left
and right children, then enqueue both children for processing.

Time Complexity: **O(N)**.
Space Complexity: **O(N)** — queue holds at most one level of the tree.

---

## 💻 Solutions

| Language | File                   | Approach      | Time Complexity | Space Complexity |
| -------- | ---------------------- | ------------- | :-------------: | :--------------: |
| C        | [`226.c`](./226.c)     | Recursive DFS |      O(N)       |       O(N)       |
| C++      | [`226.cpp`](./226.cpp) | Recursive DFS |      O(N)       |       O(N)       |
| Python   | [`226.py`](./226.py)   | Recursive DFS |      O(N)       |       O(N)       |
| Rust     | [`226.rs`](./226.rs)   | Recursive DFS |      O(N)       |       O(N)       |

---

## ✅ Test Cases

```text
Input:  root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input:  root = [2,1,3]
Output: [2,3,1]

Input:  root = []
Output: []
```
