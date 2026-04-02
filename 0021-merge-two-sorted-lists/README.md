# 21. Merge Two Sorted Lists

---

- **Difficulty:** Easy
- **Tags:** Linked List, Recursion
- **Company:** Google, Amazon, Meta, Microsoft, Apple

---

## 🧠 Problem

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

### ✳️ Examples

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

    **Input:** list1 = [1,2,4], list2 = [1,3,4]
    **Output:** [1,1,2,3,4,4]

**Example 2:**

    **Input:** list1 = [], list2 = []
    **Output:** []

**Example 3:**

    **Input:** list1 = [], list2 = [0]
    **Output:** [0]

---

## 📌 Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## 🚀 Approach

1. **Recursion** -- T.C: O(M + N), S.C: O(max(M, N))
2. **Iterative** -- T.C: O(M + N), S.C: O(1)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`21.c`](./21.c)     |    O(m + n)     |       O(1)       |
| C++      | [`21.cpp`](./21.cpp) |    O(m + n)     |       O(1)       |
| Python   | [`21.py`](./21.py)   |    O(m + n)     |       O(1)       |
| Rust     | [`21.rs`](./21.rs)   |    O(m + n)     |       O(1)       |
