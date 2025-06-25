# 941. Valid Mountain Array

---
**Difficulty:** Easy
**Tags:**  Array
**Company:** Meta, Amazon, Google, Microsoft
___
## 🧠 Problem

Given an array of integers `arr`, return `true` if and only if it is a valid mountain array.

Recall that `arr` is a mountain array if and only if:

- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
	- `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] `
	- `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

### ✳️ Examples

**Example 1:**

    Input: arr = [2,1]
    Output: false


**Example 2:**

    Input: arr = [3,5,5]
    Output: false

**Example 3:**

    Input: arr = [0,3,2,1]
    Output: true

---
## 📌 Constraints

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`

---

## 🚀 Approach

Use the **two-pointer technique**
- Starting from beginning check if we are monotonically increasing, break otherwise
- Starting from end check if we are monotonically decreasing, break otherwise
- Finally check the index to verify if we are at the peak

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`941.c`](./941.c)     |      O(n)       |       O(1)       |
| C++      | [`941.cpp`](./941.cpp) |      O(n)       |       O(1)       |
| Python   | [`941.py`](./941.py)   |      O(n)       |       O(1)       |
| Rust     | [`941.rs`](./941.rs)   |      O(n)       |       O(1)       |
