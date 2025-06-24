# 26. Remove Duplicates from Sorted Array

---
**Difficulty:** Easy
**Tags:** Two Pointers, Array
**Company:** Google, Meta, Microsoft, Amazon
___
## 🧠 Problem

Given an integer array `nums` **sorted in non-decreasing** order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in `nums`.

- Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
Return `k`.


### ✳️ Examples

**Example 1:**

    Input: nums = [1,1,2]
    Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).

**Example 2:**

    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).

---
## 📌 Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in **non-decreasing order**

---

## 🚀 Approach

Use the **two-pointer technique**

Time Complexity: O(n)
Space complexity: O(1)

---

## 💻 Solutions

| Language | File                  | Time Complexity | Space Complexity |
| -------- | --------------------- | --------------- | ---------------- |
| C        | [`26.c`](./977.c)     | O(n)            | O(1)             |
| C++      | [`26.cpp`](./977.cpp) | O(n)            | O(1)             |
| Python   | [`26.py`](./977.py)   | O(n)            | O(1)             |
| Rust     | [`26.rs`](./977.rs)   | O(n)            | O(1)             |
