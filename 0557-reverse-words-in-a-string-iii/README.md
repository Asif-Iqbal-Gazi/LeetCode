# 557. Reverse Words in a String III

---

**Difficulty:** Easy
**Tags:** String, Two Pointer
**Company:** Amazon, Google, Microsoft, Apple

---

## 🧠 Problem

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

### ✳️ Examples

**Example 1:**

    **Input:** s = "Let's take LeetCode contest"
    **Output:** "s'teL ekat edoCteeL tsetnoc"

**Example 2:**

    **Input:** s = "Mr Ding"
    **Output:** "rM gniD"

---

## 📌 Constraints

- `1 <= s.length <= 5 * 104`
- `s` contains printable **ASCII** characters.
- `s` does not contain any leading or trailing spaces.
- There is **at least one** word in `s`.
- All the words in `s` are separated by a single space.

---

## 🚀 Approach

1. [Linear Scan] -- T.C: O(N), S.C: O(N)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`557.c`](./557.c)     |      O(n)       |       O(1)       |
| C++      | [`557.cpp`](./557.cpp) |      O(n)       |       O(1)       |
| Python   | [`557.py`](./557.py)   |      O(n)       |       O(n)       |
| Rust     | [`557.rs`](./557.rs)   |      O(n)       |       O(n)       |
