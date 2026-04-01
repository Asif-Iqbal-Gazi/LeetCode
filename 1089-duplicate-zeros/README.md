# 1089. Duplicate Zeros

---

- **Difficulty:** Easy
- **Tags:** Two Pointers, Array, Weekly Contest 141, Senior
- **Company:** Google, Amazon, Microsoft, Bloomberg, Yahoo

---

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

### Approach 1 -- Brute Force (Two Pointer, Left to Right)

Use the **two-pointer technique** starting from both ends of the array:

- Start from left, when a zero is encountered
- Insert two new zeros
- pop element from right to maintain size

Time Complexity: **O(n^2)** - each zero triggers an O(n) shift.
Space Complexity: **O(1)**.

### Approach 2 -- Two-Pass In-Place (Optimal)

**Pass 1 - Find the rightmost surviving element:**
Simulate the duplication to determine which element in the original array maps to the last position in the final array.

- Track an `elementCount`, incrementing by 2 for zeros and 1 for non-zeros.
- Stop when `elementCount` reaches or exceeds `arrSize`.
- If the break fires at the last index (`right == arrSize - 1`), the array needs no shifting - return early.

**Pass 2 - Fill from right to left:**
Starting from the rightmost surviving element, copy values backwards into their final positions, duplicating zeros as we go.

**Edge Case:** If the rightmost surviving element is a zero that lands exactly on the boundary, only one copy of it fits. Write the single copy and advance both pointers before entering the main fill loop.

Time Complexity: **O(n)**.
Space Complexity: **O(1)**.

---

## 💻 Solutions

| Language | File                     | Time Complexity | Space Complexity |
| -------- | ------------------------ | --------------- | ---------------- |
| C        | [`1089.c`](./1089.c)     | O(n)            | O(1)             |
| C++      | [`1089.cpp`](./1089.cpp) | O(n^2)          | O(1)             |
| Python   | [`1089.py`](./1089.py)   | O(n^2)          | O(1)             |
| Rust     | [`1089.rs`](./1089.rs)   | O(n^2)          | O(1)             |

---

## ✅ Test Cases

You can validate all implementations with the following inputs:

```text
Input:  [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]

Input:  [1, 2, 3]
Output: [1, 2, 3]

Input:  [1,5,2,0,6,8,0,6,0]
Output: [1,5,2,0,0,6,8,0,0]

```
