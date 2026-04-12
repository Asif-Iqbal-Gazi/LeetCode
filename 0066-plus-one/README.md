# 66. Plus One

---

**Difficulty:** Easy
**Tags:** Array, Math
**Company:**

---

## 🧠 Problem

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]`is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return *the resulting array of digits*.

### ✳️ Examples

**Example 1:**

    **Input:** digits = [1,2,3]
    **Output:** [1,2,4]
    **Explanation:** The array represents the integer 123.
    Incrementing by one gives 123 + 1 = 124.
    Thus, the result should be [1,2,4].

**Example 2:**

    **Input:** digits = [4,3,2,1]
    **Output:** [4,3,2,2]
    **Explanation:** The array represents the integer 4321.
    Incrementing by one gives 4321 + 1 = 4322.
    Thus, the result should be [4,3,2,2].

**Example 3:**

    **Input:** digits = [9]
    **Output:** [1,0]
    **Explanation:** The array represents the integer 9.
    Incrementing by one gives 9 + 1 = 10.
    Thus, the result should be [1,0].

---

## 📌 Constraints

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading `0`'s.

---

## 🚀 Approach

Use the **simulation technique**

- Traverse from right to left, initialize carry to 1
- Update digit = (digit[i] + carry) % 10, and carry = sum / 10
- If carry remain insert it at the beginning.

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                 | Time Complexity | Space Complexity |
| -------- | -------------------- | :-------------: | :--------------: |
| C        | [`66.c`](./66.c)     |      O(n)       |       O(1)       |
| C++      | [`66.cpp`](./66.cpp) |      O(n)       |       O(1)       |
| Python   | [`66.py`](./66.py)   |      O(n)       |       O(1)       |
| Rust     | [`66.rs`](./66.rs)   |      O(n)       |       O(1)       |
