# 261. Graph Valid Tree

---

- **Difficulty:** Medium
- **Tags:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg, LinkedIn

---

## 🧠 Problem

Given `n` nodes labeled from `0` to `n - 1` and a list of undirected edges
where `edges[i] = [ai, bi]` indicates an undirected edge between nodes `ai`
and `bi`, return `true` if these edges make up a valid tree and `false`
otherwise.

A valid tree must satisfy two conditions:

- The graph is **fully connected** — all nodes can be reached from any node.
- The graph has **no cycles** — there is exactly one path between any two nodes.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg)

- Input: `n = 5`, `edges = [[0,1],[0,2],[0,3],[1,4]]`
- Output: `true`

**Example 2:**
![Example 2](https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg)

- Input: `n = 5`, `edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]`
- Output: `false`
- Explanation: The graph contains a cycle: `1 → 2 → 3 → 1`.

---

## 📌 Constraints

- `1 <= n <= 2000`
- `0 <= edges.length <= 5000`
- `edges[i].length == 2`
- `0 <= ai, bi < n`
- There are no self-loops or repeated edges.

---

## 🚀 Approaches

### Approach 1 — DFS

Build an adjacency list, then run DFS from node `0` tracking visited nodes
and the parent to avoid revisiting the edge we came from. If a visited node
is encountered that isn't the parent, a cycle exists. After DFS, check that
all nodes were visited to confirm connectivity.

Time Complexity: **O(V + E)**.
Space Complexity: **O(V + E)** — adjacency list and visited array.

---

### Approach 2 — BFS

Same logic as DFS but uses a queue for level-by-level traversal. Track
visited nodes and parent to detect cycles. After BFS, verify all nodes
were visited.

Time Complexity: **O(V + E)**.
Space Complexity: **O(V + E)**.

---

### Approach 3 — Union Find (Optimal)

For each edge, check if the two nodes already belong to the same component
using `find`. If they do, adding this edge would create a cycle — return
`false`. Otherwise, union them. After processing all edges, confirm that
exactly `n - 1` edges exist (necessary condition for a tree).

Time Complexity: **O(E · α(V))** — α is the inverse Ackermann function, nearly O(1).
Space Complexity: **O(V)**.

---

## 💻 Solutions

| Language | File                   | Approach   | Time Complexity | Space Complexity |
| -------- | ---------------------- | ---------- | :-------------: | :--------------: |
| C        | [`261.c`](./261.c)     | Union Find |   O(E · α(V))   |       O(V)       |
| C++      | [`261.cpp`](./261.cpp) | Union Find |   O(E · α(V))   |       O(V)       |
| Python   | [`261.py`](./261.py)   | Union Find |   O(E · α(V))   |       O(V)       |
| Rust     | [`261.rs`](./261.rs)   | Union Find |   O(E · α(V))   |       O(V)       |

---

## ✅ Test Cases

```text
Input:  n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true

Input:  n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false

Input:  n = 1, edges = []
Output: true

Input:  n = 2, edges = [[0,1]]
Output: true

Input:  n = 3, edges = [[0,1],[1,2],[2,0]]
Output: false
```
