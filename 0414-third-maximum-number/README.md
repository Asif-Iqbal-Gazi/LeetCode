# 977. Squares of Sorted Array

---
**Difficulty:** Easy
**Tags:** Array, Sorting
**Company:** Google, Bloomberg
___
## 🧠 Problem

Given an integer array `nums`, return _the **third distinct maximum** number in this array. If the third maximum does not exist, return the **maximum** number_.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [3,2,1]
	**Output:** 1
	**Explanation:**
	The first distinct maximum is 3.
	The second distinct maximum is 2.
	The third distinct maximum is 1.

**Example 2:**

	**Input:** nums = [1,2]
	**Output:** 2
	**Explanation:**
	The first distinct maximum is 2.
	The second distinct maximum is 1.
	The third distinct maximum does not exist, so the maximum (2) is returned instead.

**Example 3:**

	**Input:** nums = [2,2,3,1]
	**Output:** 1
	**Explanation:**
	The first distinct maximum is 3.
	The second distinct maximum is 2 (both 2's are counted together since they have the same value).
	The third distinct maximum is 1.

---
## 📌 Constraints

- `1 <= nums.length <= 104`
- `-2^31 <= nums[i] <= 2^31 - 1`

---

## 🚀 Approach

Track top 3 unique numbers
  - Use 3 variables (first, second, third), initialized to `LLONG_MIN` (`nums[i]` can be `INT_MIN`).
  - Skip duplicates while updating the top 3 max values.
 

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`414.c`](./414.c)     |      O(n)       |       O(1)       |
| C++      | [`414.cpp`](./414.cpp) |      O(n)       |       O(1)       |
| Python   | [`414.py`](./414.py)   |      O(n)       |       O(1)       |
| Rust     | [`414.rs`](./414.rs)   |      O(n)       |       O(1)       |
