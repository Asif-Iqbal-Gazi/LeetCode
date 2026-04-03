# 572. Subtree of Another Tree

---

- **Difficulty:** Easy
- **Tags:** Tree, Depth-First Search, String Matching, Binary Tree, Hash Function, Senior Staff
- **Company:** Google, Meta, Microsoft, Amazon, Bloomberg

---

## 🧠 Problem

Given the `roots` of two binary trees root and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

### ✳️ Examples

**Example 1:**:

![Example 1](https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg)

- Input: `root = [3,4,5,1,2]`, `subRoot = [4,1,2]`
- Output: `true`

**Example 2:**:

![Example 2](https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg)

- Input: `root = [3,4,5,1,2,null,null,null,null,0]`, `subRoot = [4,1,2]`
- Output: `false`

---

## 📌 Constraints

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `-10^4 <= root.val <= 10^4`
- `-10^4 <= subRoot.val <= 10^4`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(M \* N), S.C: O(M + N)
   For each node in `root`, check if the subtree rooted at that node is identical to `subRoot` using a `isSameTree` helper. Recurse down both left and right subtrees until a match is found or all nodes are exhausted.

2. **Serialization** -- T.C: O(M \* N), S.C: O(M + N)
   Serialize both trees into strings using preorder traversal with delimiter to uniquely represent each tree. Then check if `subroot`'s serialization is a substring of `root`'s serialization.
   The leading `,` delimiter before each value is critical - without it, a node with value `2` would falsely match inside a node with value `12`.

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`572.c`](./572.c)     |    O(M \* N)    |     O(M + N)     |
| C++      | [`572.cpp`](./572.cpp) |    O(M \* N)    |     O(M + N)     |
| Python   | [`572.py`](./572.py)   |    O(M \* N)    |     O(M + N)     |
| Rust     | [`572.rs`](./572.rs)   |    O(M \* N)    |     O(M + N)     |
