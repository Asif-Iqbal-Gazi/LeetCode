# 167. Two Sum II - Input Is Sorted

---

**Difficulty:** Medium
**Tags:** Array, Two Pointer, Binary Search
**Company:** Google, Meta, Amazon

---

## 🧠 Problem

Given a **1-indexed** array of integers `numbers` that is already ***sorted in non-decreasing order***, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the indices of the two numbers,* `index1` *and* `index2`*, **added by one** as an integer array* `[index1, index2]` *of length 2.*

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

### ✳️ Examples

**Example 1:**

    **Input:** numbers = [2,7,11,15], target = 9
    **Output:** [1,2]
    **Explanation:** The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

**Example 2:**

    **Input:** numbers = [2,3,4], target = 6
    **Output:** [1,3]
    **Explanation:** The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

**Example 3:**

    **Input:** numbers = [-1,0], target = -1
    **Output:** [1,2]
    **Explanation:** The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

---

## 📌 Constraints

- `2 <= numbers.length <= 3 * 10^4`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in **non-decreasing order**.
- `-1000 <= target <= 1000`
- The tests are generated such that there is **exactly one solution**.

---

## 🚀 Approach

Use the **two-pointer technique**

- The Array is sorted
- Move left pointer rightwards to increase sum; move right pointer leftwards to decrease sum
- Stop when sum == target

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                   | Time Complexity | Space Complexity |
| -------- | ---------------------- | :-------------: | :--------------: |
| C        | [`167.c`](./167.c)     |      O(n)       |       O(1)       |
| C++      | [`167.cpp`](./167.cpp) |      O(n)       |       O(1)       |
| Python   | [`167.py`](./167.py)   |      O(n)       |       O(1)       |
| Rust     | [`167.rs`](./167.rs)   |      O(n)       |       O(1)       |
