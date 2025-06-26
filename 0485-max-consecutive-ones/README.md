# 485. Max Consecutive Ones

---
**Difficulty:** Easy
**Tags:** Array
**Company:** Google, Microsoft, Amazon, Meta
___
## 🧠 Problem

Given a binary array `nums`, return _the maximum number of consecutive_ `1`_'s in the array_.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [1,1,0,1,1,1]
	**Output:** 3
	**Explanation:** The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

**Example 2:**

	**Input:** nums = [1,0,1,1,0,1]
	**Output:** 2

---
## 📌 Constraints

- `1 <= nums.length <= 105`
- `nums[i]` is either `0` or `1`.


---

## 🚀 Approach

Traverse array and count consecutive ones, resetting count on 0, tracking the maximum


Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`485.c`](./485.c)     |      O(n)       |       O(1)       |
| C++      | [`485.cpp`](./485.cpp) |      O(n)       |       O(1)       |
| Python   | [`485.py`](./485.py)   |      O(n)       |       O(1)       |
| Rust     | [`485.rs`](./485.rs)   |      O(n)       |       O(1)       |
