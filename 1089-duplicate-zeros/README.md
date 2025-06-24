# 1089. Duplicate Zeros

---
**Difficulty:** Easy
**Tags:** Two Pointers, Array, Sorting
**Company:** Google, Amazon, Microsoft, Yahoo
___
## 🧠 Problem

Given a fixed-length integer array `arr`, duplicate each occurrence of zero, shifting the remaining elements to the right.

`Note` that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

### ✳️ Examples

**Example 1:**

    Input: arr = [1,0,2,3,0,4,5,0]
    Output: [1,0,0,2,3,0,0,4]
    Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

**Example 2:**

    Input: arr = [1,2,3]
    Output: [1,2,3]
    Explanation: After calling your function, the input array is modified to: [1,2,3]

---
## 📌 Constraints

- `1 <= arr.length <= 10^4`
- `0 <= nums[i] <= 9`

---

## 🚀 Approach

Use the **two-pointer technique** starting from both ends of the array:

- Start from left, when a zero is encountered
- Insert two new zeros
- pop element from right to maintain size

Time Complexity: **O(n^2)**.
Space Complexity: **O(1)**.

---

## 💻 Solutions

| Language | File                     | Time Complexity | Space Complexity |
| -------- | ------------------------ | --------------- | ---------------- |
| C        | [`1089.c`](./1089.c)     | O(n)            | O(1)             |
| C++      | [`1089.cpp`](./1089.cpp) | O(n)            | O(1)             |
| Python   | [`1089.py`](./1089.py)   | O(n)            | O(1)             |
| Rust     | [`1089.rs`](./1089.rs)   | O(n)            | O(1)             |

---

## ✅ Test Cases

You can validate all implementations with the following inputs:

```text
Input:  [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]

Input:  [1, 2, 3]
Output: [1, 2, 3]
```
