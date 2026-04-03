# 70. Climbing Stairs

---

- **Difficulty:** Easy
- **Tags:** Math, Recursion, Dynamic Programming, Memoization
- **Company:** Google, Amazon, Meta, Microsoft, Apple, Bloomberg

---

## 🧠 Problem

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways
can you climb to the top?

### ✳️ Examples

**Example 1:**

- Input: `n = 2`
- Output: `2`
- Explanation: There are two ways to climb to the top.
  1. `1 step + 1 step`
  2. `2 steps`

**Example 2:**

- Input: `n = 3`
- Output: `3`
- Explanation: There are three ways to climb to the top.
  1. `1 step + 1 step + 1 step`
  2. `1 step + 2 steps`
  3. `2 steps + 1 step`

---

## 📌 Constraints

- `1 <= n <= 45`

---

## 🚀 Approaches

### Approach 1 — Recursion (Brute Force)

At each step, we have two choices — climb 1 step or climb 2 steps. Recursively
compute the number of ways to reach the top from each position. This leads to
an exponential number of redundant subproblems.

Time Complexity: **O(2^N)**.
Space Complexity: **O(N)** — recursion call stack.

---

### Approach 2 — Dynamic Programming (Optimal)

Observe that the number of ways to reach step `n` is the sum of ways to reach
step `n-1` and step `n-2` — identical to the Fibonacci sequence. Use two
variables to track the previous two values, advancing forward until `n`.

Time Complexity: **O(N)**.
Space Complexity: **O(1)**.

---

## 💻 Solutions

| Language | File                 | Approach | Time Complexity | Space Complexity |
| -------- | -------------------- | -------- | :-------------: | :--------------: |
| C        | [`70.c`](./70.c)     | DP       |      O(n)       |       O(1)       |
| C++      | [`70.cpp`](./70.cpp) | DP       |      O(n)       |       O(1)       |
| Python   | [`70.py`](./70.py)   | DP       |      O(n)       |       O(1)       |
| Rust     | [`70.rs`](./70.rs)   | DP       |      O(n)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  n = 1
Output: 1

Input:  n = 2
Output: 2

Input:  n = 3
Output: 3

Input:  n = 45
Output: 1836311903
```
