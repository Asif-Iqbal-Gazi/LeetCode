# 1346. Check If N and Its Double Exist

---
**Difficulty:** Easy
**Tags:** Two Pointers, Array, Sorting, Binary Search, Hash Table
**Company:** Google, Amazon, Bloomberg, Meta, Microsoft
___
## 🧠 Problem

Given an array `arr` of integers, check if there exist two indices `i` and `j` such that :

- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`
 

### ✳️ Examples

**Example 1:**

    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

**Example 2:**

    Input: arr = [3,1,7,11]
    Output: false
    Explanation: There is no i and j that satisfy the conditions.

---
## 📌 constraints

- `2 <= arr.length <= 500`
- `-10^3 <= nums[i] <= 10^3`

---

## 🚀 Approach

Use **hashset**

Time Complexity: O(n)
Space complexity: O(n)

---

## 💻 Solutions

| Language | File                  | Time Complexity | Space Complexity |
| :------- | --------------------- | --------------- | ---------------- |
| C        | [`1346.c`](./977.c)   | O(n)            | O(n)             |
| C++      | ❌                     | ❌               | ❌                |
| Python   | [`1346.py`](./977.py) | O(n)            | O(n)             |
| Rust     | [`1346.rs`](./977.rs) | O(n)            | O(n)             |
|          |                       |                 |                  |
