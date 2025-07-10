# 14. Longest Common Prefix
---
**Difficulty:** Easy
**Tags:** Array, String, Trie
**Company:** Google, Meta, Amazon, Apple
___
## 🧠 Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

### ✳️ Examples

**Example 1:**

	**Input:** strs = ["flower","flow","flight"]
	**Output:** "fl"

**Example 2:**

	**Input:** strs = ["dog","racecar","car"]
	**Output:** ""
	**Explanation:** There is no common prefix among the input strings.

---
## 📌 Constraints

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

---

## 🚀 Approach
1. **Horizontal Scanning** -- T.C: O(n * m), S.C: O(1)
	- Initialize prefix length as length of first string.
	- For each other string, compare characters with first string.
	- Shrink the prefix length when mismatch found.


Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`14.c`](./14.c)     |    O(n * m)     |       O(1)       |
| C++      | [`14.cpp`](./14.cpp) |    O(n * m)     |       O(1)       |
| Python   | [`14.py`](./14.py)   |    O(n * m)     |       O(1)       |
| Rust     | [`14.rs`](./14.rs)   |    O(n * m)     |       O(1)       |
