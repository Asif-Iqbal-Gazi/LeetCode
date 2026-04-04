# 206. Reverse Linked List

---

- **Difficulty:** Easy
- **Tags:** Linked List, Recursion
- **Company:** Google, Apple, Microsoft, Amazon, Meta, Bloomberg

---

## 🧠 Problem

Given the `head` of a singly linked list, reverse the list, and return the
reversed list.

### ✳️ Examples

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

- Input: `head = [1,2,3,4,5]`
- Output: `[5,4,3,2,1]`

**Example 2:**

![Example 2](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

- Input: `head = [1,2]`
- Output: `[2,1]`

**Example 3:**

- Input: `head = []`
- Output: `[]`

---

## 📌 Constraints

- The number of nodes in the list is in the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

---

## 🚀 Approaches

### Approach 1 — Iterative

Use three pointers: `prev`, `curr`, and `next`. At each node, reverse the
link by pointing `curr->next` to `prev`, then advance all three pointers
forward until `curr` is null.

Time Complexity: **O(N)**.
Space Complexity: **O(1)**.

---

### Approach 2 — Recursive

Recurse to the end of the list — the last node becomes the new head. On the
way back up the call stack, reverse the link at each node with
`head->next->next = head`, then cut the old forward link with
`head->next = nullptr` to prevent cycles.

Time Complexity: **O(N)**.
Space Complexity: **O(N)** — recursion call stack.

---

## 💻 Solutions

| Language | File                   | Approach  | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------- | :-------------: | :--------------: |
| C        | [`206.c`](./206.c)     | Iterative |      O(N)       |       O(1)       |
| C++      | [`206.cpp`](./206.cpp) | Iterative |      O(N)       |       O(1)       |
| Python   | [`206.py`](./206.py)   | Iterative |      O(N)       |       O(1)       |
| Rust     | [`206.rs`](./206.rs)   | Iterative |      O(N)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input:  head = [1,2]
Output: [2,1]

Input:  head = []
Output: []
```
