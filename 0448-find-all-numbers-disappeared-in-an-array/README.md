# 448. Find All Numbers Disappeared in an Array

---
**Difficulty:** Easy
**Tags:** Array, Hash Table
**Company:** Google, Amazon, Bloomberg
___
## 🧠 Problem

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return _an array of all the integers in the range_ `[1, n]` _that do not appear in_ `nums`.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [4,3,2,7,8,2,3,1]
	**Output:** [5,6]

**Example 2:**

	**Input:** nums = [1,1]
	**Output:** [2]

---
## 📌 Constraints

- `n == nums.length`
- `1 <= n <= 105`
- `1 <= nums[i] <= n`

---

## 🚀 Approach

Use **In-Place Marking** 
- Iterate through the array and for each number `num`, mark the index `abs(num) - 1` as visited by negating the number at that index.
- Then collect indices where the number is still positive → those indices were not visited.

Time Complexity: O(n)
Space complexity: O(1) (excluding result container)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`448.c`](./448.c)     |      O(n)       |       O(1)       |
| C++      | [`448.cpp`](./448.cpp) |      O(n)       |       O(1)       |
| Python   | [`448.py`](./448.py)   |      O(n)       |       O(1)       |
| Rust     | [`448.rs`](./448.rs)   |      O(n)       |       O(1)       |
