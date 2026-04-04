# 104. Maximum Depth of Binary Tree

---

- **Difficulty:** Easy
- **Tags:** Tree, Binary Tree, Depth-First Search, Breadth-First Search
- **Company:** Google, Microsoft, Bloomberg, Amazon

---

## 🧠 Problem

Given the `root` of a binary tree, return its maximum depth.

A binary tree's **maximum depth** is the number of nodes along the longest
path from the root node down to the farthest leaf node.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `3`

**Example 2:**

- Input: `root = [1,null,2]`
- Output: `2`

---

## 📌 Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-100 <= Node.val <= 100`

---

## 🚀 Approaches

### Approach 1 — Recursive DFS

Recursively compute the maximum depth of the left and right subtrees. The
depth at the current node is `1 + max(left, right)`. Base case: null node
returns 0.

Time Complexity: **O(N)** — every node is visited once.
Space Complexity: **O(N)** — recursion call stack, O(log N) for balanced tree.

---

### Approach 2 — Iterative BFS

Use a queue to traverse the tree level by level, incrementing a counter for
each level processed. The final counter value is the maximum depth.

Time Complexity: **O(N)**.
Space Complexity: **O(N)** — queue holds at most one level of the tree.

---

## 💻 Solutions

| Language | File                   | Approach      | Time Complexity | Space Complexity |
| -------- | ---------------------- | ------------- | :-------------: | :--------------: |
| C        | [`104.c`](./104.c)     | Recursive DFS |      O(N)       |       O(N)       |
| C++      | [`104.cpp`](./104.cpp) | Recursive DFS |      O(N)       |       O(N)       |
| Python   | [`104.py`](./104.py)   | Recursive DFS |      O(N)       |       O(N)       |
| Rust     | [`104.rs`](./104.rs)   | Recursive DFS |      O(N)       |       O(N)       |

---

## ✅ Test Cases

```text
Input:  root = [3,9,20,null,null,15,7]
Output: 3

Input:  root = [1,null,2]
Output: 2

Input:  root = []
Output: 0

Input:  root = [1]
Output: 1
```
