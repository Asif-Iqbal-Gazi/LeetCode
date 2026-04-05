# 238. Product of Array Except Self

---

- **Difficulty:** Medium
- **Tags:** Array, Prefix Sum
- **Company:** Google, Microsoft, Amazon, Meta, Apple, Bloomberg

---

## 🧠 Problem

Given an integer array `nums`, return an array `answer` such that `answer[i]`
is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a
32-bit integer.

You must write an algorithm that runs in `O(N)` time and without using the
division operation.

### ✳️ Examples

**Example 1:**

- Input: `nums = [1,2,3,4]`
- Output: `[24,12,8,6]`

**Example 2:**

- Input: `nums = [-1,1,0,-3,3]`
- Output: `[0,0,9,0,0]`

---

## 📌 Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is guaranteed to fit in a
  32-bit integer.

---

## 🚀 Approaches

### Approach 1 — Brute Force

For each element, iterate over the entire array multiplying all elements
except the current one.

Time Complexity: **O(N²)**.
Space Complexity: **O(1)** — excluding output array.

---

### Approach 2 — Prefix and Suffix Arrays

Build a prefix product array and a suffix product array. For each index,
`answer[i] = prefix[i] * suffix[i]`.

Time Complexity: **O(N)**.
Space Complexity: **O(N)** — two extra arrays.

---

### Approach 3 — Prefix and Suffix (Space Optimized)

Use the output array to store prefix products in a first pass. In a second
pass, maintain a running suffix product and multiply it into the output
array in place — no extra arrays needed.

Time Complexity: **O(N)**.
Space Complexity: **O(1)** — excluding output array.

---

## 💻 Solutions

| Language | File                   | Approach        | Time Complexity | Space Complexity |
| -------- | ---------------------- | --------------- | :-------------: | :--------------: |
| C        | [`238.c`](./238.c)     | Prefix + Suffix |      O(N)       |       O(1)       |
| C++      | [`238.cpp`](./238.cpp) | Prefix + Suffix |      O(N)       |       O(1)       |
| Python   | [`238.py`](./238.py)   | Prefix + Suffix |      O(N)       |       O(1)       |
| Rust     | [`238.rs`](./238.rs)   | Prefix + Suffix |      O(N)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]

Input:  nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Input:  nums = [0,0]
Output: [0,0]

Input:  nums = [1,1]
Output: [1,1]

Input:  nums = [-1,-1]
Output: [-1,-1]
```
