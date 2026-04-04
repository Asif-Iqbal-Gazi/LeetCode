# 338. Counting Bits

---

- **Difficulty:** Easy
- **Tags:** Dynamic Programming, Bit Manipulation
- **Company:** Amazon, Meta, Google, Microsoft, Nvidia

---

## 🧠 Problem

Given an integer `n`, return an array `ans` of length `n + 1` such that for
each `i` (`0 <= i <= n`), `ans[i]` is the number of `1`'s in the binary
representation of `i`.

### ✳️ Examples

**Example 1:**

- Input: `n = 2`
- Output: `[0,1,1]`
- Explanation:
  - `0` in binary is `0` → 0 ones
  - `1` in binary is `1` → 1 one
  - `2` in binary is `10` → 1 one

**Example 2:**

- Input: `n = 5`
- Output: `[0,1,1,2,1,2]`
- Explanation:
  - `0` in binary is `0` → 0 ones
  - `1` in binary is `1` → 1 one
  - `2` in binary is `10` → 1 one
  - `3` in binary is `11` → 2 ones
  - `4` in binary is `100` → 1 one
  - `5` in binary is `101` → 2 ones

---

## 📌 Constraints

- `0 <= n <= 10^5`

---

## 🚀 Approaches

### Approach 1 — Bit Manipulation (Brian Kernighan)

For each number `i` from `0` to `n`, count its set bits using Brian
Kernighan's algorithm — `i & (i - 1)` clears the lowest set bit. Repeat
until `i` is zero, counting iterations.

Time Complexity: **O(N log N)**.
Space Complexity: **O(1)** — excluding output array.

---

### Approach 2 — Dynamic Programming (Optimal)

Use the recurrence: `ans[i] = ans[i >> 1] + (i & 1)`.

- `i >> 1` drops the last bit of `i` (divide by 2) — its bit count is already computed.
- `i & 1` adds 1 if `i` is odd (last bit is set), 0 if even.

This builds the answer in a single pass with no repeated work.

Time Complexity: **O(N)**.
Space Complexity: **O(1)** — excluding output array.

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`338.c`](./338.c)     | DP       |      O(N)       |       O(1)       |
| C++      | [`338.cpp`](./338.cpp) | DP       |      O(N)       |       O(1)       |
| Python   | [`338.py`](./338.py)   | DP       |      O(N)       |       O(1)       |
| Rust     | [`338.rs`](./338.rs)   | DP       |      O(N)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  n = 2
Output: [0,1,1]

Input:  n = 5
Output: [0,1,1,2,1,2]

Input:  n = 0
Output: [0]

Input:  n = 1
Output: [0,1]
```
