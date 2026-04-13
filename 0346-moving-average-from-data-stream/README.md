# 346. Moving Average from Data Stream

---

- **Difficulty:** Easy
- **Tags:** Array, Design, Queue, Data Stream
- **Company:** Google, Amazon, Meta, Microsoft, Bloomberg

---

## 🧠 Problem

Given a stream of integers and a window size `k`, calculate the moving
average of all integers in the sliding window.

Implement the `MovingAverage` class:

- `MovingAverage(int size)` — initializes the object with the size of the
  window `k`.
- `double next(int val)` — returns the moving average of the last `k` values
  of the stream.

### ✳️ Examples

**Example 1:**

- Input:

  ```text
  ["MovingAverage", "next", "next", "next", "next"]
  [[3], [1], [10], [3], [5]]
  ```

- Output: `[null, 1.0, 5.5, 4.66667, 6.0]`
- Explanation:

  ```text
  MovingAverage movingAverage = new MovingAverage(3);
  movingAverage.next(1);  // return 1.0  = 1 / 1
  movingAverage.next(10); // return 5.5  = (1 + 10) / 2
  movingAverage.next(3);  // return 4.66667 = (1 + 10 + 3) / 3
  movingAverage.next(5);  // return 6.0  = (10 + 3 + 5) / 3
  ```

---

## 📌 Constraints

- `1 <= size <= 1000`
- `-10^5 <= val <= 10^5`
- At most `10^4` calls will be made to `next`.

---

## 🚀 Approaches

### Approach 1 — Circular Array (Optimal)

Use a fixed-size circular array to store the last `k` values. Maintain a
running sum — when the window is full, subtract the element being overwritten
before adding the new one. Advance the tail pointer using modulo arithmetic.

Time Complexity: **O(1)** per `next` call.
Space Complexity: **O(k)**.

---

### Approach 2 — Queue

Use a queue to maintain the sliding window. When the queue reaches size `k`,
dequeue the oldest element and subtract it from the running sum before
enqueueing the new value.

Time Complexity: **O(1)** per `next` call.
Space Complexity: **O(k)**.

---

## 💻 Solutions

| Language | File                   | Approach       | Time Complexity | Space Complexity |
| -------- | ---------------------- | -------------- | :-------------: | :--------------: |
| C        | [`346.c`](./346.c)     | Circular Array |      O(1)       |       O(k)       |
| C++      | [`346.cpp`](./346.cpp) | Circular Array |      O(1)       |       O(k)       |
| Python   | [`346.py`](./346.py)   | Circular Array |      O(1)       |       O(k)       |
| Rust     | [`346.rs`](./346.rs)   | Circular Array |      O(1)       |       O(k)       |

---

## ✅ Test Cases

```text
Input:  ["MovingAverage","next","next","next","next"]
        [[3],[1],[10],[3],[5]]
Output: [null,1.0,5.5,4.66667,6.0]

Input:  ["MovingAverage","next"]
        [[1],[4]]
Output: [null,4.0]

Input:  ["MovingAverage","next","next"]
        [[2],[5],[10]]
Output: [null,5.0,7.5]
```
