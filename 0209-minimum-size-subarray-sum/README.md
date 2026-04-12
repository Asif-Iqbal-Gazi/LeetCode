# 209. Minimum Size Subarray Sum

---

**Difficulty:** Medium
**Tags:** Array, Binary Search, Sliding Window, Prefix Sum
**Company:** Google, Microsoft, Amazon, Meta

---

## 🧠 Problem

Given an array of positive integers `nums` and a positive integer `target`, return *the **minimal length** of a* *subarray* *whose sum is greater than or equal to* `target`. If there is no such subarray, return `0` instead.

### ✳️ Examples

**Example 1:**

    **Input:** target = 7, nums = [2,3,1,2,4,3]
    **Output:** 2
    **Explanation:** The subarray [4,3] has the minimal length under the problem constraint.

**Example 2:**

    **Input:** target = 4, nums = [1,4,4]
    **Output:** 1

**Example 3:**

    **Input:** target = 11, nums = [1,1,1,1,1,1,1,1]
    **Output:** 0

---

## 📌 Constraints

- `1 <= target <= 109`
- `1 <= nums.length <= 10^45`
- `1 <= nums[i] <= 10^4`

---

## 🚀 Approach

Use the **sliding window technique**

- Expand right to add nums[right]
- Shrink left to keep sum >= target

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`209.c`](./209.c)     |      O(n)       |       O(1)       |
| C++      | [`209.cpp`](./209.cpp) |      O(n)       |       O(1)       |
| Python   | [`209.py`](./209.py)   |      O(n)       |       O(1)       |
| Rust     | [`209.rs`](./209.rs)   |      O(n)       |       O(1)       |
