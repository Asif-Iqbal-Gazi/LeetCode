# 779. K-th Symbol in Grammar

---
**Difficulty:** Medium
**Tags:** Math, Bit Manipulation, Recursion, Weekly Contest 70
**Company:** 
___
## 🧠 Problem

We build a table of `n` rows (**1-indexed**). We start by writing `0` in the `1st` row. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

- For example, for `n = 3`, the `1st` row is `0`, the `2nd` row is `01`, and the `3rd` row is `0110`.

Given two integer `n` and `k`, return the `kth` (**1-indexed**) symbol in the `nth` row of a table of `n`rows.

### ✳️ Examples

**Example 1:**

	**Input:** n = 1, k = 1
	**Output:** 0
	**Explanation:** row 1: 0

**Example 2:**

	**Input:** n = 2, k = 1
	**Output:** 0
	**Explanation:** 
	row 1: 0
	row 2: 01

**Example 3:**

	**Input:** n = 2, k = 2
	**Output:** 1
	**Explanation:** 
	row 1: 0
	row 2: 01

---
## 📌 Constraints

- `1 <= n <= 30`
- `1 <= k <= 2^(n - 1)`

---

## 🚀 Approach

**Observation**:
Observe, for n = 4 our rows are:
        0
        0 1
        0 1 1 0
        0 1 1 0 1 0 0 1
    => Each row doubles the previous row.
    => First half of the row = same as previous row.
    => Second half of the row = inverted previous row.

1. **Recursion** -- T.C: O(n), S.C: O(n)
    - Base Case: first symbol is always 0.
    - Find mid of current row.
    - If k <= mid -> same as previous row.
    - Else -> inverted previous row.
2. **Math** -- T.C: O(log k), S.C: O(1)
    - Number of of set bits in (k - 1) tells how many times the symbol flipped.
    - Even flips -> 0; odd flips -> 1.
 


---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`779.c`](./779.c)     |    O(log K)     |       O(1)       |
| C++      | [`779.cpp`](./779.cpp) |    O(log K)     |       O(1)       |
| Python   | [`779.py`](./779.py)   |    O(log K)     |       O(1)       |
| Rust     | [`779.rs`](./779.rs)   |    O(log K)     |       O(1)       |
