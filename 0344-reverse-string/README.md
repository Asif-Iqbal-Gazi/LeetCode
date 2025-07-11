# 344. Reverse String

---
**Difficulty:** Easy
**Tags:** String, Two Pointer
**Company:** Amazon, Google, Bloomberg, Microsoft
___
## 🧠 Problem

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

### ✳️ Examples

**Example 1:**

	**Input:** s = ["h","e","l","l","o"]
	**Output:** ["o","l","l","e","h"]

**Example 2:**

	**Input:** s = ["H","a","n","n","a","h"]
	**Output:** ["h","a","n","n","a","H"]

---
## 📌 Constraints

- `1 <= s.length <= 105`
- `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

---

## 🚀 Approach

Use the **two-pointer technique**

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`344.c`](./344.c)     |      O(n)       |       O(1)       |
| C++      | [`344.cpp`](./344.cpp) |      O(n)       |       O(1)       |
| Python   | [`344.py`](./344.py)   |      O(n)       |       O(1)       |
| Rust     | [`344.rs`](./344.rs)   |      O(n)       |       O(1)       |
