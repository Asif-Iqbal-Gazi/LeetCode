# 3. Longest Substring Without Repeating Characters

---

- **Difficulty:** Medium
- **Tags:** Hash Table, String, Sliding Window
- **Company:** Google, Amazon, Meta, Microsoft, Apple, Bloomberg, Adobe

---

## 🧠 Problem

Given a string `s`, find the length of the **longest substring** without
repeating characters.

### ✳️ Examples

**Example 1:**

- Input: `s = "abcabcbb"`
- Output: `3`
- Explanation: The answer is `"abc"`, with the length of `3`.

**Example 2:**

- Input: `s = "bbbbb"`
- Output: `1`
- Explanation: The answer is `"b"`, with the length of `1`.

**Example 3:**

- Input: `s = "pwwkew"`
- Output: `3`
- Explanation: The answer is `"wke"`, with the length of `3`.

---

## 📌 Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.

---

## 🚀 Approaches

### Approach 1 — Brute Force

Check every possible substring and verify if it contains all unique
characters. Track the maximum length found.

Time Complexity: **O(N³)** — O(N²) substrings, O(N) uniqueness check each.
Space Complexity: **O(N)** — hash set to check uniqueness.

---

### Approach 2 — Sliding Window with Hash Set

Use two pointers `l` and `r` to maintain a window of unique characters.
Expand `r` to the right — if `s[r]` is already in the set, shrink the
window from the left by advancing `l` until the duplicate is removed.
Track the maximum window size throughout.

Time Complexity: **O(N)**.
Space Complexity: **O(N)** — hash set stores at most N characters.

---

### Approach 3 — Sliding Window with Hash Map (Optimal)

Store the last seen index of each character in a hash map. When a duplicate
is found at `r`, jump `l` directly to `lastSeen[s[r]] + 1` instead of
shrinking one step at a time — avoiding redundant iterations.

Time Complexity: **O(N)**.
Space Complexity: **O(N)**.

---

## 💻 Solutions

| Language | File               | Approach       | Time Complexity | Space Complexity |
| -------- | ------------------ | -------------- | :-------------: | :--------------: |
| C        | [`3.c`](./3.c)     | Sliding Window |      O(N)       |       O(N)       |
| C++      | [`3.cpp`](./3.cpp) | Sliding Window |      O(N)       |       O(N)       |
| Python   | [`3.py`](./3.py)   | Sliding Window |      O(N)       |       O(N)       |
| Rust     | [`3.rs`](./3.rs)   | Sliding Window |      O(N)       |       O(N)       |

---

## ✅ Test Cases

```text
Input:  s = "abcabcbb"
Output: 3

Input:  s = "bbbbb"
Output: 1

Input:  s = "pwwkew"
Output: 3

Input:  s = ""
Output: 0

Input:  s = "au"
Output: 2

Input:  s = " "
Output: 1
```
