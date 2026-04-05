# 5. Longest Palindromic Substring

---

- **Difficulty:** Medium
- **Tags:** String, Dynamic Programming, Two Pointers
- **Company:** Google, Amazon, Meta, Microsoft, Apple, Bloomberg, Adobe

---

## 🧠 Problem

Given a string `s`, return the **longest palindromic substring** in `s`.

### ✳️ Examples

**Example 1:**

- Input: `s = "babad"`
- Output: `"bab"`
- Explanation: `"aba"` is also a valid answer.

**Example 2:**

- Input: `s = "cbbd"`
- Output: `"bb"`

---

## 📌 Constraints

- `1 <= s.length <= 1000`
- `s` consists of only digits and English letters.

---

## 🚀 Approaches

### Approach 1 — Brute Force

Check every possible substring and verify if it is a palindrome. Track the
longest one found.

Time Complexity: **O(N³)** — O(N²) substrings, O(N) palindrome check each.
Space Complexity: **O(1)**.

---

### Approach 2 — Dynamic Programming

Build a 2D boolean table where `dp[i][j]` is `true` if `s[i..j]` is a
palindrome. A substring is a palindrome if its outer characters match and
the inner substring is also a palindrome. Fill the table for increasing
lengths.

Time Complexity: **O(N²)**.
Space Complexity: **O(N²)** — 2D table.

---

### Approach 3 — Expand Around Center (Optimal)

For each character (and each gap between characters), expand outward as long
as the characters on both sides match. Track the longest palindrome found.
Handles both odd-length (`"aba"`) and even-length (`"abba"`) palindromes.

Time Complexity: **O(N²)**.
Space Complexity: **O(1)**.

---

### Approach 4 — Manacher's Algorithm

Preprocess the string by inserting separators between characters to unify
odd and even length cases. Use previously computed palindrome radii to avoid
redundant comparisons.

Time Complexity: **O(N)**.
Space Complexity: **O(N)**.

---

## 💻 Solutions

| Language | File               | Approach             | Time Complexity | Space Complexity |
| -------- | ------------------ | -------------------- | :-------------: | :--------------: |
| C        | [`5.c`](./5.c)     | Expand Around Center |      O(N²)      |       O(1)       |
| C++      | [`5.cpp`](./5.cpp) | Expand Around Center |      O(N²)      |       O(1)       |
| Python   | [`5.py`](./5.py)   | Expand Around Center |      O(N²)      |       O(1)       |
| Rust     | [`5.rs`](./5.rs)   | Expand Around Center |      O(N²)      |       O(1)       |

---

## ✅ Test Cases

```text
Input:  s = "babad"
Output: "bab"

Input:  s = "cbbd"
Output: "bb"

Input:  s = "a"
Output: "a"

Input:  s = "ac"
Output: "a"

Input:  s = "racecar"
Output: "racecar"

Input:  s = "abacaba"
Output: "abacaba"
```
