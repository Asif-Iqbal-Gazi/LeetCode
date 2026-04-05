# 128. Longest Consecutive Sequence

---

- **Difficulty:** Medium
- **Tags:** Array, Hash Table, Union Find
- **Company:** Google, Amazon, Meta, Microsoft, Apple, Nvidia

---

## 🧠 Problem

Given an unsorted array of integers `nums`, return _the length of the longest consecutive elements sequence_.

You must write an algorithm that runs in **O(N)** time.

---

## ✳️ Examples

**Example 1:**

- Input: `nums = [100,4,200,1,3,2]`
- Output: `4`

**Example 2:**

- Input: `nums = [0,3,7,2,5,8,4,6,0,1]`
- Output: `9`

**Example 3:**

- Input: `nums = [0,1,2]`
- Output: `3`

---

## 📌 Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## 🚀 Approaches

### Approach 1 — Hash Set

Insert all elements into a set. For each number, check if it is the start of a sequence (`num - 1` not in set), then count consecutive elements.

Time Complexity: **O(N)**
Space Complexity: **O(N)**

---

### Approach 2 — Sorting

Sort the array and count consecutive elements while handling duplicates.

Time Complexity: **O(N log N)**
Space Complexity: **O(1)** or **O(N)** depending on sorting

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`128.c`](./128.c)     | Hash Set |      O(N)       |       O(N)       |
| C++      | [`128.cpp`](./128.cpp) | Hash Set |      O(N)       |       O(N)       |
| Python   | [`128.py`](./128.py)   | Hash Set |      O(N)       |       O(N)       |
| Rust     | [`128.rs`](./128.rs)   | Hash Set |      O(N)       |       O(N)       |

---

## ✅ Test Cases

```text
Input:  nums = [100,4,200,1,3,2]
Output: 4

Input:  nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Input:  nums = []
Output: 0

Input:  nums = [1,2,0,1]
Output: 3
```
