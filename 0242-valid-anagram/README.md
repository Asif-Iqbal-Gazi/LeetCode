# 242. Valid Anagram

---

- **Difficulty:** Easy
- **Tags:** String, Hash Table, Sorting
- **Company:** Google, Bloomberg, Microsoft, Amazon, Meta

---

## 🧠 Problem

Given two strings `s` and `t`, return `true` if t is an anagram of `s`, and `false` otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### ✳️ Examples

**Example 1:**

- Input: `s = "anagram`, `t = "nagaram`
- Output: `true`

**Example 2:**

- Input: `s = "rat"`, `t = "car"`
- Output: `false`

---

## 📌 Constraints

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consists of lowercase English letters.

---

## 🚀 Approaches

### Approach 1 -- Hash Table (Frequence Count)

Count the frequency of ech character in `s`, then decrement using t.
If all count returns zero, the strings are arnagrams.

- Time Complexity: **O(n)**
- Space Complexity: **O(1)**

### Approach 2 - Sorting

Sort both strings and compare them. If equal, they are anagrams.

- Time Complexity: **O(n log n)**
- Space Complexity: **O(1)**

---

## 💻 Solutions

| Language | File                   |  Approach  | Time Complexity | Space Complexity |
| -------- | ---------------------- | :--------: | :-------------: | :--------------: |
| C        | [`242.c`](./242.c)     | Hash Table |      O(n)       |       O(n)       |
| C++      | [`242.cpp`](./242.cpp) | Hash Table |      O(n)       |       O(n)       |
| Python   | [`242.py`](./242.py)   | Hash Table |      O(n)       |       O(n)       |
| Rust     | [`242.rs`](./242.rs)   | Hash Table |      O(n)       |       O(n)       |

---

## ✅ Test Cases

```text
Input:  s = "anagram", t = "nagaram"
Output: true

Input:  s = "rat", t = "car"
Output: false

Input:  s = "a", t = "ab"
Output: false

Input:  s = "aacc", t = "ccac"
Output: false
```
