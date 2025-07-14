# 1. Two Sum

---
**Difficulty:** Easy
**Tags:** Array, Hash Table
**Company:** Google, Amazon, Meta, Microsoft
___
## 🧠 Problem

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.

You can return the answer in any order.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [2,7,11,15], target = 9
	**Output:** [0,1]
	**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**

	**Input:** nums = [3,2,4], target = 6
	**Output:** [1,2]

**Example 3:**

	**Input:** nums = [3,3], target = 6
	**Output:** [0,1]

---
## 📌 Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **Only one valid answer exists.**

---

## 🚀 Approach

Use a *hash map**

Time Complexity: O(n)
Space complexity: O(n)

---

## 💻 Solutions

| Language | File               | Time Complexity | Space Complexity |
| -------- | ------------------ | :-------------: | :--------------: |
| C        | [`1.c`](./1.c)     |      O(n)       |       O(n)       |
| C++      | [`1.cpp`](./1.cpp) |      O(n)       |       O(n)       |
| Python   | [`1.py`](./1.py)   |      O(n)       |       O(n)       |
| Rust     | [`1.rs`](./1.rs)   |      O(n)       |       O(n)       |
