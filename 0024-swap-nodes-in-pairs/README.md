# 24. Swap Nodes in Pairs

---
**Difficulty:** Medium
**Tags:** Linked List, Recursion
**Company:** Google, Bloomberg, Amazon
___
## 🧠 Problem

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

### ✳️ Examples

**Example 1:**

	**Input:** head = [1,2,3,4]
	
	**Output:** [2,1,4,3]
	
	**Explanation:**
	
	![](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

**Example 2:**

	**Input:** head = []
	
	**Output:** []

**Example 3:**

	**Input:** head = [1]
	
	**Output:** [1]

**Example 4:**

	**Input:** head = [1,2,3]
	
	**Output:** [2,1,3]

---
## 📌 Constraints

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

---

## 🚀 Approach

1. **Recursion** -- T.C: O(N), S.C: O(N)
2. **Iterative** -- T.C: O(N), S.C: O(1)


---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`24.c`](./24.c)     |      O(n)       |       O(1)       |
| C++      | [`24.cpp`](./24.cpp) |      O(n)       |       O(1)       |
| Python   | [`24.py`](./24.py)   |      O(n)       |       O(n)       |
| Rust     | [`24.rs`](./24.rs)   |      O(n)       |       O(n)       |
