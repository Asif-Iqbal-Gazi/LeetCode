# 125. Valid Palindrome

---

- **Difficulty:** Easy
- **Tags:** Two Pointers, String
- **Company:** Meta, Google, Microsoft, Bloomberg, Apple, Amazon

---

## 🧠 Problem

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.

Given a string `s`, return `true` _if it is a **palindrome**, or `false` otherwise_.

---

## ✳️ Examples

**Example 1:**

- Input: `s = "A man, a plan, a canal: Panama"`
- Output: `true`

**Example 2:**

- Input: `s = "race a car"`
- Output: `false`

**Example 3:**

- Input: `s = " "`
- Output: `true`

---

## 📌 Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters

---

## 🚀 Approaches

### Approach 1 — Two Pointers

Use two pointers from both ends, skip non-alphanumeric characters, and compare characters in lowercase.

Time Complexity: **O(N)**
Space Complexity: **O(1)**

---

### Approach 2 — String Filtering

Filter out non-alphanumeric characters, convert to lowercase, then check if the string equals its reverse.

Time Complexity: **O(N)**
Space Complexity: **O(N)**

---

## 💻 Solutions

| Language | File                   | Approach     | Time Complexity | Space Complexity |
| -------- | ---------------------- | ------------ | :-------------: | :--------------: |
| C        | [`125.c`](./125.c)     | Two Pointers |      O(N)       |       O(1)       |
| C++      | [`125.cpp`](./125.cpp) | Two Pointers |      O(N)       |       O(1)       |
| Python   | [`125.py`](./125.py)   | Two Pointers |      O(N)       |       O(1)       |
| Rust     | [`125.rs`](./125.rs)   | Two Pointers |      O(N)       |       O(1)       |

---

## ✅ Test Cases

```text
Input:  s = "A man, a plan, a canal: Panama"
Output: true

Input:  s = "race a car"
Output: false

Input:  s = " "
Output: true

Input:  s = "0P"
Output: false
```
