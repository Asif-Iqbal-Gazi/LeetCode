# 1295. Find Numbers with Even Number of Digits

---

- **Difficulty:** Easy
- **Tags:** Array, Math, Weekly Contest 168
- **Company:** Meta, Google, Bloomberg, Amazon, Microsoft

---

## 🧠 Problem

Given an array `nums` of integers, return how many of them contain an _even number_ of digits.

### ✳️ Examples

**Example 1:**

- **Input:** `nums = [12,345,2,6,7896]`
- **Output:** `2`
- **Explanation:**
  - 12 contains 2 digits (even number of digits).
  - 345 contains 3 digits (odd number of digits).
  - 2 contains 1 digit (odd number of digits).
  - 6 contains 1 digit (odd number of digits).
  - 7896 contains 4 digits (even number of digits).
  - Therefore only 12 and 7896 contain an even number of digits.

**Example 2:**

- **Input:** `nums = [555,901,482,1771]`
- **Output:** `1`
- **Explanation:**
  - Only 1771 contains an even number of digits.

---

## 📌 Constraints

- `1 <= nums.length <= 500`
- `1 <= nums[i] <= 10^4`

---

## 🚀 Approach

Traverse the array for each number in `nums`, keep dividing by 10 to count the number of digits.

1. **Math** -- T.C: O(N), S.C: O(1)

---

## 💻 Solutions

| Language | File                     | Time Complexity | Space Complexity |
| -------- | ------------------------ | :-------------: | :--------------: |
| C        | [`1295.c`](./1295.c)     |      O(n)       |       O(1)       |
| C++      | [`1295.cpp`](./1295.cpp) |      O(n)       |       O(1)       |
| Python   | [`1295.py`](./1295.py)   |      O(n)       |       O(1)       |
| Rust     | [`1295.rs`](./1295.rs)   |      O(n)       |       O(1)       |
