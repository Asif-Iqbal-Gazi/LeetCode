# 217. Contains Duplicate
---
- **Difficulty:** Easy
- **Tags:** Array, Hash Table, Sorting
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg, Apple
---
## 🧠 Problem
Given an integer array `nums`, return `true` if any value appears **at least
twice** in the array, and return `false` if every element is distinct.

### ✳️ Examples
**Example 1:**
- Input: `nums = [1,2,3,1]`
- Output: `true`
- Explanation: `1` appears at index `0` and `3`.

**Example 2:**
- Input: `nums = [1,2,3,4]`
- Output: `false`
- Explanation: All elements are distinct.

**Example 3:**
- Input: `nums = [1,1,1,3,3,4,3,2,4,2]`
- Output: `true`

---
## 📌 Constraints
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---
## 🚀 Approaches

### Approach 1 — Brute Force
For each element, check all subsequent elements for a duplicate. Return `true`
if a match is found, otherwise `false`.

Time Complexity: **O(N²)**.
Space Complexity: **O(1)**.

---

### Approach 2 — Sorting
Sort the array. Duplicates will be adjacent — scan for any two consecutive
equal elements.

Time Complexity: **O(N log N)**.
Space Complexity: **O(1)**.

---

### Approach 3 — Hash Set (Optimal)
Traverse the array, inserting each element into a hash set. If an element
already exists in the set, a duplicate is found — return `true`. If traversal
completes without a match, return `false`.

Time Complexity: **O(N)**.
Space Complexity: **O(N)**.

---
## 💻 Solutions
| Language | File                   | Approach  | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------- | :-------------: | :--------------: |
| C        | [`217.c`](./217.c)     | Hash Set  |      O(N)       |       O(N)       |
| C++      | [`217.cpp`](./217.cpp) | Hash Set  |      O(N)       |       O(N)       |
| Python   | [`217.py`](./217.py)   | Hash Set  |      O(N)       |       O(N)       |
| Rust     | [`217.rs`](./217.rs)   | Hash Set  |      O(N)       |       O(N)       |

---
## ✅ Test Cases
```text
Input:  nums = [1,2,3,1]
Output: true

Input:  nums = [1,2,3,4]
Output: false

Input:  nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Input:  nums = [1]
Output: false
```
