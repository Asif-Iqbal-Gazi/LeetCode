# 133. Clone Graph

---

- **Difficulty:** Medium
- **Tags:** Hash Table, Depth-First Search, Breadth-First Search, Graph
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg, Apple

---

## 🧠 Problem

Given a reference of a node in a **connected** undirected graph, return a
**deep copy** (clone) of the graph.

Each node in the graph contains a value (`int`) and a list of its neighbors
(`List[Node]`).

```cpp
class Node {
    public:
        int val;
        vector<Node*> neighbors;
};
```

**Note:** The given node will always be the first node with `val = 1`. You
must return the reference to the cloned graph's first node.

### ✳️ Examples

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)

- Input: `adjList = [[2,4],[1,3],[2,4],[1,3]]`
- Output: `[[2,4],[1,3],[2,4],[1,3]]`
- Explanation: There are 4 nodes in the graph. Node 1's neighbors are nodes
  2 and 4. Node 2's neighbors are nodes 1 and 3. Node 3's neighbors are
  nodes 2 and 4. Node 4's neighbors are nodes 1 and 3.

**Example 2:**

- Input: `adjList = [[]]`
- Output: `[[]]`
- Explanation: The graph has one node with no neighbors.

**Example 3:**

- Input: `adjList = []`
- Output: `[]`
- Explanation: The graph is empty.

---

## 📌 Constraints

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The graph is connected and all nodes can be visited starting from the
  given node.

---

## 🚀 Approaches

### Approach 1 — DFS + Hash Map

Recursively clone each node. Use a hash map to track already cloned nodes
— if a node has been cloned before, return its clone immediately to avoid
infinite loops in cyclic graphs.

Time Complexity: **O(V + E)** — every node and edge is visited once.
Space Complexity: **O(V)** — hash map stores one clone per node.

---

### Approach 2 — BFS + Hash Map

Use a queue to traverse the graph level by level. Clone each node when
first encountered and store it in a hash map. For each neighbor, clone it
if not already done and add the edge to the cloned graph.

Time Complexity: **O(V + E)**.
Space Complexity: **O(V)**.

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`133.c`](./133.c)     | DFS      |    O(V + E)     |       O(V)       |
| C++      | [`133.cpp`](./133.cpp) | DFS      |    O(V + E)     |       O(V)       |
| Python   | [`133.py`](./133.py)   | DFS      |    O(V + E)     |       O(V)       |

---

## ✅ Test Cases

```text
Input:  adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]

Input:  adjList = [[]]
Output: [[]]

Input:  adjList = []
Output: []
```
