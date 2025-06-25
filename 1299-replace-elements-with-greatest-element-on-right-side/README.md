# 1299. Replace Elements with Greatest Element on Right Side

---
**Difficulty:** Easy
**Tags:** Array
**Company:** Google, Amazon, Meta
___
## 🧠 Problem

Given an array `arr`, replace every element in that array with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

### ✳️ Examples

**Example 1:**

    Input: arr = [17,18,5,4,6,1]
    Output: [18,6,6,6,1,-1]
    Explanation: 
    - index 0 --> the greatest element to the right of index 0 is index 1 (18).
    - index 1 --> the greatest element to the right of index 1 is index 4 (6).
    - index 2 --> the greatest element to the right of index 2 is index 4 (6).
    - index 3 --> the greatest element to the right of index 3 is index 4 (6).
    - index 4 --> the greatest element to the right of index 4 is index 5 (1).
    - index 5 --> there are no elements to the right of index 5, so we put -1.

**Example 2:**

    Input: arr = [400]
    Output: [-1]
    Explanation: There are no elements to the right of index 0.

---
## 📌 Constraints

- `1 <= arr.length <= 10^4`
- `1 <= nums[i] <= 10^5`

---

## 🚀 Approach

Traverse from right, tracking the greatest element.

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                     | Time Complexity | Space Complexity |
| -------- | ------------------------ | :-------------: | :--------------: |
| C        | [`1299.c`](./1299.c)     |      O(n)       |       O(1)       |
| C++      | [`1299.cpp`](./1299.cpp) |      O(n)       |       O(1)       |
| Python   | [`1299.py`](./1299.py)   |      O(n)       |       O(1)       |
| Rust     | [`1299.rs`](./1299.rs)   |      O(n)       |       O(1)       |
