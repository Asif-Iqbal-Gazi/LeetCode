# 100. Same Tree

---

- **Difficulty:** Easy
- **Tags:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg

---

## 🧠 Problem

Given the roots of two binary trees `p` and `q`, write a function to check
if they are the same or not.

Two binary trees are considered the same if they are structurally identical,
and the nodes have the same value.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

- Input: `p = [1,2,3]`, `q = [1,2,3]`
- Output: `true`

**Example 2:**
![Example 2](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

- Input: `p = [1,2]`, `q = [1,null,2]`
- Output: `false`

**Example 3:**
![Example 3](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

- Input: `p = [1,2,1]`, `q = [1,1,2]`
- Output: `false`

---

## 📌 Constraints

- The number of nodes in both trees is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

---

## 🚀 Approaches

### Approach 1 — Recursive DFS

Recursively check if the current nodes are equal, then verify the left and
right subtrees match. Base cases: both null → `true`, one null → `false`,
values differ → `false`.

Time Complexity: **O(N)** — every node is visited once.
Space Complexity: **O(N)** — recursion call stack, O(log N) for balanced tree.

---

### Approach 2 — Iterative BFS

Use a queue to traverse both trees simultaneously level by level. At each
step, compare the current nodes from both trees — if they differ, return
`false`. If traversal completes without mismatch, return `true`.

Time Complexity: **O(N)**.
Space Complexity: **O(N)**.

---

## 💻 Solutions

| Language | File                   | Approach      | Time Complexity | Space Complexity |
| -------- | ---------------------- | ------------- | :-------------: | :--------------: |
| C        | [`100.c`](./100.c)     | Recursive DFS |      O(N)       |       O(N)       |
| C++      | [`100.cpp`](./100.cpp) | Recursive DFS |      O(N)       |       O(N)       |
| Python   | [`100.py`](./100.py)   | Recursive DFS |      O(N)       |       O(N)       |
| Rust     | [`100.rs`](./100.rs)   | Recursive DFS |      O(N)       |       O(N)       |

---

## ✅ Test Cases

```text
Input:  p = [1,2,3], q = [1,2,3]
Output: true

Input:  p = [1,2], q = [1,null,2]
Output: false

Input:  p = [1,2,1], q = [1,1,2]
Output: false

Input:  p = [], q = []
Output: true

Input:  p = [1], q = []
Output: false
```
