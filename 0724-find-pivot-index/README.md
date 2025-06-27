# 724. Find Pivot Index

---
**Difficulty:** Easy
**Tags:** Array, Prefix Sum
**Company:** Meta, IBM, Google, Amazon
___
## 🧠 Problem

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return _the **leftmost pivot index**_. If no such index exists, return `-1`.

### ✳️ Examples

**Example 1:**

	**Input:** nums = [1,7,3,6,5,6]
	**Output:** 3
	**Explanation:**
	The pivot index is 3.
	Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
	Right sum = nums[4] + nums[5] = 5 + 6 = 11

**Example 2:**

	**Input:** nums = [1,2,3]
	**Output:** -1
	**Explanation:**
	There is no index that satisfies the conditions in the problem statement.

**Example 3:**

	**Input:** nums = [2,1,-1]
	**Output:** 0
	**Explanation:**
	The pivot index is 0.
	Left sum = 0 (no elements to the left of index 0)
	Right sum = nums[1] + nums[2] = 1 + -1 = 0

---
## 📌 Constraints

- `1 <= nums.length <= 104`
- `-1000 <= nums[i] <= 1000`

---

## 🚀 Approach

`Prefix Sum` technique.
- Subtract current element from total sum to get right sum, compare with left sum.


Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`724.c`](./724.c)     |      O(n)       |       O(1)       |
| C++      | [`724.cpp`](./724.cpp) |      O(n)       |       O(1)       |
| Python   | [`724.py`](./724.py)   |      O(n)       |       O(1)       |
| Rust     | [`724.rs`](./724.rs)   |      O(n)       |       O(1)       |
