# 252. Meeting Rooms

---

- **Difficulty:** Easy
- **Tags:** Array, Sorting
- **Company:** Apple, Google, TikTok, Amazon, Meta, Microsoft

---

## 🧠 Problem

Given an array of meeting time intervals where `intervals[i] = [start_i, end_i]`, determine if a person could attend all meetings.

A person cannot attend two meetings if they overlap.

---

## ✳️ Examples

**Example 1:**

- Input: `intervals = [[0,30],[5,10],[15,20]]`
- Output: `false`

**Example 2:**

- Input: `intervals = [[7,10],[2,4]]`
- Output: `true`

---

## 📌 Constraints

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i < end_i <= 10^6`

---

## 🚀 Approaches

### Approach 1 — Sorting

Sort the intervals by start time.
Then check for any overlap between consecutive intervals.
If `current.start < previous.end`, there is a conflict.

- Time Complexity: **O(N log N)** — sorting
- Space Complexity: **O(1)** or **O(N)** depending on sorting

---

### Approach 2 — Brute Force

Compare every pair of intervals to check if any overlap exists.

Time Complexity: **O(N²)**
Space Complexity: **O(1)**

---

## 💻 Solutions

| Language | File                   | Approach | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------- | :-------------: | :--------------: |
| C        | [`252.c`](./252.c)     | Sorting  |   O(N log N)    |       O(1)       |
| C++      | [`252.cpp`](./252.cpp) | Sorting  |   O(N log N)    |       O(1)       |
| Python   | [`252.py`](./252.py)   | Sorting  |   O(N log N)    |       O(1)       |
| Rust     | [`252.rs`](./252.rs)   | Sorting  |   O(N log N)    |       O(1)       |

---

## ✅ Test Cases

```text
Input:  intervals = [[0,30],[5,10],[15,20]]
Output: false

Input:  intervals = [[7,10],[2,4]]
Output: true

Input:  intervals = []
Output: true

Input:  intervals = [[1,5],[5,10]]
Output: true
```
