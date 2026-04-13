# 286. Walls and Gates

---

- **Difficulty:** Medium
- **Tags:** Array, Breadth-First Search, Matrix
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg, Facebook

---

## 🧠 Problem

You are given an `m x n` grid `rooms` initialized with these three possible
values:

- `-1` — A wall or an obstacle.
- `0` — A gate.
- `INF` — An empty room. We use `2^31 - 1 = 2147483647` to represent
  infinity, which you may assume is large enough that it will never overflow
  when we add to it.

Fill each empty room with the distance to its nearest gate. If it is
impossible to reach a gate, it should remain `INF`.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2021/01/03/grid.jpg)

- Input:
  ```text
  rooms = [[2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]]
  ```
- Output:

  ```text
  [[3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]]
  ```

**Example 2:**

- Input: `rooms = [[-1]]`
- Output: `[[-1]]`

---

## 📌 Constraints

- `m == rooms.length`
- `n == rooms[i].length`
- `1 <= m, n <= 250`
- `rooms[i][j]` is `-1`, `0`, or `2^31 - 1`.

---

## 🚀 Approaches

### Approach 1 — BFS from Each Empty Room

For each empty room, run BFS to find the nearest gate. This results in
redundant work since many rooms share nearby gates.

Time Complexity: **O((M \* N)²)**.
Space Complexity: **O(M \* N)**.

---

### Approach 2 — Multi-Source BFS from Gates (Optimal)

Start BFS simultaneously from all gates at once. Each empty room is visited
exactly once and assigned the shortest distance to any gate. Walls are never
enqueued.

Time Complexity: **O(M \* N)** — every cell is visited at most once.
Space Complexity: **O(M \* N)** — queue holds at most M \* N cells.

---

## 💻 Solutions

| Language | File                   | Approach         | Time Complexity | Space Complexity |
| -------- | ---------------------- | ---------------- | :-------------: | :--------------: |
| C        | [`286.c`](./286.c)     | Multi-Source BFS |    O(M \* N)    |    O(M \* N)     |
| C++      | [`286.cpp`](./286.cpp) | Multi-Source BFS |    O(M \* N)    |    O(M \* N)     |
| Python   | [`286.py`](./286.py)   | Multi-Source BFS |    O(M \* N)    |    O(M \* N)     |
| Rust     | [`286.rs`](./286.rs)   | Multi-Source BFS |    O(M \* N)    |    O(M \* N)     |

---

## ✅ Test Cases

```text
Input:  [[2147483647,-1,0,2147483647],
          [2147483647,2147483647,2147483647,-1],
          [2147483647,-1,2147483647,-1],
          [0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],
          [2,2,1,-1],
          [1,-1,2,-1],
          [0,-1,3,4]]

Input:  [[-1]]
Output: [[-1]]

Input:  [[0]]
Output: [[0]]

Input:  [[2147483647]]
Output: [[2147483647]]
```
