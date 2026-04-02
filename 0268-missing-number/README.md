# 268. Missing Number

---

- **Difficulty:** Easy
- **Tags:** Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
- **Company:** Google, Amazon, Bloomberg, Meta, Nvidia

---

## 🧠 Problem

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return _the only number in the range that is missing from the array_.

### ✳️ Examples

**Example 1:**

- Input: `nums = [3,0,1]`
- Output: `2`
- Explanation:
  - `n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. 2 is the missing number in the range since it does not appear in `nums`.

**Example 2:**

- Input: `nums = [0,1]`
- Output: `2`
- Explanation:
  - `n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. 2 is the missing number in the range since it does not appear in `nums`.

**Example 3:**

- Input: `nums = [9,6,4,2,3,5,7,0,1]`
- Output: `8`
- Explanation:
  - `n = 9 since t`here are 9 numbers, so all numbers are in the range [`0,9]`. 8 is the missing number in the range since it does not appear in `nums`.

---

## 📌 Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

---

## 🚀 Approach

1. **Math Algebra** -- T.C: O(N), S.C: O(1)
2. **Xor Technique** -- T.C: O(N), S.C: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`268.c`](./268.c)     |      O(n)       |       O(n)       |
| C++      | [`268.cpp`](./268.cpp) |      O(n)       |       O(n)       |
| Python   | [`268.py`](./268.py)   |      O(n)       |       O(n)       |
| Rust     | [`268.rs`](./268.rs)   |      O(n)       |       O(n)       |
