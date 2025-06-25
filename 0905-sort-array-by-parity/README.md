# 905. Sort Array By Parity

---
**Difficulty:** Easy
**Tags:** Two Pointers, Array, Sorting
**Company:** 
___
## 🧠 Problem

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return `any array` that satisfies this condition.

### ✳️ Examples

**Example 1:**

    Input: nums = [3,1,2,4]
    Output: [2,4,3,1]
    Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

**Example 2:**

    Input: nums = [0]
    Output: [0]

---
## 📌 Constraints

- `1 <= nums.length <= 5000`
- `0 <= nums[i] <= 5000`

---

## 🚀 Approach

Use the **two-pointer technique**

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`905.c`](./905.c)     |      O(n)       |       O(1)       |
| C++      | [`905.cpp`](./905.cpp) |      O(n)       |       O(1)       |
| Python   | [`905.py`](./905.py)   |      O(n)       |       O(1)       |
| Rust     | [`905.rs`](./905.rs)   |      O(n)       |       O(1)       |
