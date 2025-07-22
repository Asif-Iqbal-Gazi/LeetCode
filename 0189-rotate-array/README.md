# 189. Rotate Array

---
**Difficulty:** Medium
**Tags:** Array, Math, Two Pointer
**Company:** Google, Bloomberg, Meta, Microsoft, Apple, Amazon
___
## 🧠 Problem

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [1,2,3,4,5,6,7], k = 3
	**Output:** [5,6,7,1,2,3,4]
	**Explanation:**
	rotate 1 steps to the right: [7,1,2,3,4,5,6]
	rotate 2 steps to the right: [6,7,1,2,3,4,5]
	rotate 3 steps to the right: [5,6,7,1,2,3,4]

**Example 2:**

	**Input:** nums = [-1,-100,3,99], k = 2
	**Output:** [3,99,-1,-100]
	**Explanation:** 
	rotate 1 steps to the right: [99,-1,-100,3]
	rotate 2 steps to the right: [3,99,-1,-100]

---
## 📌 Constraints

- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`

---

## 🚀 Approach

**Reverse In-Place** -- T.C: O(N), S.C: O(1)
    - Rotating the array right by k is equivalent to:
        a) Reverse first n - k elements
        b) Reverse last k elements
        c) Reverse the entire array
    - Example:
        Original:       1, 2, 3, 4, 5, 6, 7
        Step 1:         4, 3, 2, 1, 5, 6, 7     (reverse first 4)
        Step 2:         4, 3, 2, 1, 7, 6, 5     (reverse last 3)
        Step 3:         5, 6, 7, 1, 2, 3, 4     (reverse all)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`189.c`](./189.c)     |      O(n)       |       O(n)       |
| C++      | [`189.cpp`](./189.cpp) |      O(n)       |       O(n)       |
| Python   | [`189.py`](./189.py)   |      O(n)       |       O(n)       |
| Rust     | [`189.rs`](./189.rs)   |      O(n)       |       O(n)       |
