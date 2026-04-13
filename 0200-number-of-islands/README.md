# 200. Number of Islands

---

- **Difficulty:** Medium
- **Tags:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg, Apple, Adobe

---

## 🧠 Problem

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s
(land) and `'0'`s (water), return the number of islands.

An **island** is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid
are all surrounded by water.

### ✳️ Examples

**Example 1:**

- Input:

  ```text
  grid = [["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]]
  ```

- Output: `1`

**Example 2:**

- Input:
  ```text
  grid = [["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]]
  ```
- Output: `3`

---

## 📌 Constraints

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

---

## 🚀 Approaches

### Approach 1 — DFS

Traverse the grid. When a `'1'` is found, increment the island count and
run DFS to mark all connected land cells as visited by setting them to
`'0'`. Each DFS call sinks an entire island.

Time Complexity: **O(M \* N)**.
Space Complexity: **O(M \* N)** — recursion call stack in worst case.

---

### Approach 2 — BFS

Same logic as DFS but uses a queue. When a `'1'` is found, increment the
island count and run BFS to sink all connected land cells.

Time Complexity: **O(M \* N)**.
Space Complexity: **O(M \* N)** — queue holds at most min(M, N) cells.

---

### Approach 3 — Union Find

Initialize each land cell as its own component. For each land cell, union
it with its adjacent land neighbors. The number of islands is the number
of remaining distinct components after processing all cells.

Time Complexity: **O(M \* N · α(M \* N))**.
Space Complexity: **O(M \* N)**.

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`200.c`](./200.c)     | DFS      |    O(M \* N)    |    O(M \* N)     |
| C++      | [`200.cpp`](./200.cpp) | DFS      |    O(M \* N)    |    O(M \* N)     |
| Python   | [`200.py`](./200.py)   | DFS      |    O(M \* N)    |    O(M \* N)     |
| Rust     | [`200.rs`](./200.rs)   | DFS      |    O(M \* N)    |    O(M \* N)     |

---

## ✅ Test Cases

```text
Input:  grid = [["1","1","1","1","0"],
                ["1","1","0","1","0"],
                ["1","1","0","0","0"],
                ["0","0","0","0","0"]]
Output: 1

Input:  grid = [["1","1","0","0","0"],
                ["1","1","0","0","0"],
                ["0","0","1","0","0"],
                ["0","0","0","1","1"]]
Output: 3

Input:  grid = [["1"]]
Output: 1

Input:  grid = [["0"]]
Output: 0

Input:  grid = [["1","0","1","0","1"]]
Output: 3
```
