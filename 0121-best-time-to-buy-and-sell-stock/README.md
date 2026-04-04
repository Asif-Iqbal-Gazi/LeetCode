# 121. Best Time to Buy and Sell Stock

---

- **Difficulty:** Easy
- **Tags:** Array, Dynamic Programming
- **Company:** Google, Meta, Amazon, Bloomberg, Microsoft, Visa, TikTok

---

## 🧠 Problem

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the _maximum profit you can achieve from this transaction_. If you cannot achieve any profit, return `0`.

---

## ✳️ Examples

**Example 1:**

- Input: `prices = [7,1,5,3,6,4]`
- Output: `5`

**Example 2:**

- Input: `prices = [7,6,4,3,1]`
- Output: `0`

---

## 📌 Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

---

## 🚀 Approaches

### Approach 1 — One Pass (Greedy)

Track the minimum price seen so far and compute the profit for each day. Update the maximum profit accordingly.

Time Complexity: **O(N)**
Space Complexity: **O(1)**

---

### Approach 2 — Brute Force

Try every pair `(i, j)` where `j > i` and compute the profit.

Time Complexity: **O(N²)**
Space Complexity: **O(1)**

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`121.c`](./121.c)     | One Pass |      O(N)       |       O(1)       |
| C++      | [`121.cpp`](./121.cpp) | One Pass |      O(N)       |       O(1)       |
| Python   | [`121.py`](./121.py)   | One Pass |      O(N)       |       O(1)       |
| Rust     | [`121.rs`](./121.rs)   | One Pass |      O(N)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  prices = [7,1,5,3,6,4]
Output: 5

Input:  prices = [7,6,4,3,1]
Output: 0

Input:  prices = [1]
Output: 0

Input:  prices = [2,4,1]
Output: 2
```
