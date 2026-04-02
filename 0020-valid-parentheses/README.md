# 20. Valid Parentheses

---

- **Difficulty:** Easy
- **Tags:** String, Stack
- **Company:** Google, Bloomberg, Amazon, Meta, LinkedIn, Nvidia

---

## 🧠 Problem

Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

### ✳️ Examples

**Example 1:**:

- Input: s = "()"
- Output: true

**Example 2:**:

- Input: s = "()[]{}"
- Output: true

**Example 3:**:

- Input: s = "(]"
- Output: false

**Example 4:**:

- Input: s = "([])"
- Output: true

**Example 5:**:

- Input: s = "([)]"
- Output: false

---

## 📌 Constraints

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `()[]{}`

---

## 🚀 Approach

1. **Stack** -- T.C: O(N), S.C: O(N)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`20.c`](./20.c)     |      O(n)       |       O(n)       |
| C++      | [`20.cpp`](./20.cpp) |      O(n)       |       O(n)       |
| Python   | [`20.py`](./20.py)   |      O(n)       |       O(n)       |
| Rust     | [`20.rs`](./20.rs)   |      O(n)       |       O(n)       |
