# 151. Reverse Words in a String

---
**Difficulty:** Medium
**Tags:** String, Two Pointer
**Company:** Google, Amazon, Meta
___
## 🧠 Problem

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return _a string of the words in reverse order concatenated by a single space._

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

### ✳️ Examples

**Example 1:**

	**Input:** s = "the sky is blue"
	**Output:** "blue is sky the"

**Example 2:**

	**Input:** s = "  hello world  "
	**Output:** "world hello"
	**Explanation:** Your reversed string should not contain leading or trailing spaces.

**Example 3:**

	**Input:** s = "a good   example"
	**Output:** "example good a"
	**Explanation:** You need to reduce multiple spaces between two words to a single space in the reversed string.

---
## 📌 Constraints

- `1 <= s.length <= 10^4`
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is **at least one** word in `s`.

---

## 🚀 Approach

1. [Linear Scan] -- T.C: O(N), S.C: O(1)
    - Remove extra spaces (leading, trailing, and in-between)
    - Reverse each word in place.
    - Reverse the whole string to get final order.

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`151.c`](./151.c)     |      O(n)       |       O(1)       |
| C++      | [`151.cpp`](./151.cpp) |      O(n)       |       O(1)       |
| Python   | [`151.py`](./151.py)   |      O(n)       |       O(n)       |
| Rust     | [`151.rs`](./151.rs)   |      O(n)       |       O(n)       |
