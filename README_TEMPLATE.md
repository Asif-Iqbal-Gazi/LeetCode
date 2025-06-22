# 977. Squares of Sorted Array

---
**Difficulty:** Easy
**Tags:** Two Pointers, Array, Sorting
**Company:** 
___
## 🧠 Problem

Given an integer array `nums` **sorted in non-decreasing order**, return an array of the **squares** of each number, also sorted in non-decreasing order.

### ✳️ Examples

**Example 1:**

    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].

**Example 2:**

    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]

---
## 📌 Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in **non-decreasing order**

---

## 🚀 Approach

Use the **two-pointer technique**

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------------- | ---------------- |
| C        | [`977.c`](./977.c)     | O(n)            | O(n)             |
| C++      | [`977.cpp`](./977.cpp) | O(n)            | O(n)             |
| Python   | [`977.py`](./977.py)   | O(n)            | O(n)             |
| Rust     | [`977.rs`](./977.rs)   | O(n)            | O(n)             |
