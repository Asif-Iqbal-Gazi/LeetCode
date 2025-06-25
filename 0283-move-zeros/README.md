# 283. Move Zeros

---
**Difficulty:** Easy
**Tags:** Array, Two Pointers
**Company:** Google, Microsoft, Amazon, Meta
___
## 🧠 Problem

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

`Note` that you must do this in-place without making a copy of the array.


### ✳️ Examples

**Example 1:**

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

**Example 2:**

    Input: nums = [0]
    Output: [0]

---
## 📌 Constraints

- `1 <= nums.length <= 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`

---

## 🚀 Approach

Using a pointer first fill in the non-zero elements, then fill the rest of the array with zeros.

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`283.c`](./283.c)     |      O(n)       |       O(1)       |
| C++      | [`283.cpp`](./283.cpp) |      O(n)       |       O(1)       |
| Python   | [`283.py`](./283.py)   |      O(n)       |       O(1)       |
| Rust     | [`283.rs`](./283.rs)   |      O(n)       |       O(1)       |
