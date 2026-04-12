# 28. Find the Index of the First Occurrence in a String

---

**Difficulty:** Easy
**Tags:** String, String Matching, Two Pointer
**Company:** Google, Microsoft, Amazon, Apple

---

## 🧠 Problem

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

### ✳️ Examples

**Example 1:**

    **Input:** haystack = "sadbutsad", needle = "sad"
    **Output:** 0
    **Explanation:** "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

**Example 2:**

    **Input:** haystack = "leetcode", needle = "leeto"
    **Output:** -1
    **Explanation:** "leeto" did not occur in "leetcode", so we return -1.

---

## 📌 Constraints

- `1 <= haystack.length, needle.length <= 104`
- `haystack` and `needle` consist of only lowercase English characters.

---

## 🚀 Approach

Use the KMP Algorithm

Time Complexity: O(m + n)
Space complexity: O(m)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`28.c`](./28.c)     |    O(m + n)     |       O(m)       |
| C++      | [`28.cpp`](./28.cpp) |     O(m +n)     |       O(m)       |
| Python   | [`28.py`](./28.py)   |    O(m + n)     |       O(m)       |
| Rust     | [`28.rs`](./28.rs)   |    O(m + n)     |       O(m)       |
