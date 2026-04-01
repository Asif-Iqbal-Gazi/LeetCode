# 487. Max Consecutive Ones II

---

- **Difficulty:** Medium
- **Tags:** Array, Sliding Window, Dynamic Programming, Senior Staff
- **Company:** Meta, Google

---

## 🧠 Problem

Given a binary array `nums`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most one* `0`.

### ✳️ Examples

**Example 1:**

    **Input:** nums = [1,0,1,1,0]
    **Output:** 4
    **Explanation:**
    - If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
    - If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
    The max number of consecutive ones is 4.

**Example 2:**

    **Input:** nums = [1,0,1,1,0,1]
    **Output:** 4
    **Explanation:**
    - If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
    - If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
    The max number of consecutive ones is 4.

---

## 📌 Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

---

## 🚀 Approach

Use the **sliding window** technique.

- Expand the window by moving right; if there are more than one zero, move left forward.
  The final window will be the longest with at most one zero.

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`487.c`](./487.c)     |      O(n)       |       O(1)       |
| C++      | [`487.cpp`](./487.cpp) |      O(n)       |       O(1)       |
| Python   | [`487.py`](./487.py)   |      O(n)       |       O(1)       |
| Rust     | [`487.rs`](./487.rs)   |      O(n)       |       O(1)       |
