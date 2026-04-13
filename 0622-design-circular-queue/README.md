# 622. Design Circular Queue

---

- **Difficulty:** Medium
- **Tags:** Array, Linked List, Design, Queue
- **Company:** Google, Cloudflare, Microsoft, Apple, Amazon, Meta

---

## 🧠 Problem

Design your implementation of the circular queue. A circular queue is a
linear data structure in which the operations are performed based on FIFO
(First In First Out) principle, and the last position is connected back to
the first position to make a circle.

Implement the `MyCircularQueue` class:

- `MyCircularQueue(k)` — initializes the queue with a maximum size of `k`.
- `bool enQueue(int value)` — inserts an element into the circular queue.
  Returns `true` if the operation is successful.
- `bool deQueue()` — deletes an element from the circular queue. Returns
  `true` if the operation is successful.
- `int Front()` — gets the front item from the queue. Returns `-1` if the
  queue is empty.
- `int Rear()` — gets the last item from the queue. Returns `-1` if the
  queue is empty.
- `bool isEmpty()` — checks whether the circular queue is empty or not.
- `bool isFull()` — checks whether the circular queue is full or not.

You must solve the problem **without using the built-in queue data structure**
in your programming language.

### ✳️ Examples

**Example 1:**

- Input:
  ```text
    ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
    [[3], [1], [2], [3], [4], [], [], [], [4], []]
  ```
- Output: `[null, true, true, true, false, 3, true, true, true, 4]`
- Explanation:

  ```text
    MyCircularQueue myCircularQueue = new MyCircularQueue(3);
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False, the queue is full
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();     // return 4
  ```

  ***

## 📌 Constraints

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`,
  `isEmpty`, and `isFull`.

---

## 🚀 Approaches

### Approach 1 — Array Based

Use a fixed-size array with `head` and `tail` pointers. Advance both pointers
using modulo arithmetic to wrap around. Track the current size to distinguish
between full and empty states.

Time Complexity: **O(1)** — all operations are constant time.
Space Complexity: **O(k)** — fixed-size array of capacity `k`.

---

### Approach 2 — Linked List Based

Use a singly linked list with `head` and `tail` pointers. Enqueue by appending
to the tail, dequeue by removing from the head. Track size to enforce the
capacity constraint.

Time Complexity: **O(1)** — all operations are constant time.
Space Complexity: **O(k)**.

---

## 💻 Solutions

| Language | File                   | Approach    | Time Complexity | Space Complexity |
| -------- | ---------------------- | ----------- | :-------------: | :--------------: |
| C        | [`622.c`](./622.c)     | Array Based |      O(1)       |       O(k)       |
| C++      | [`622.cpp`](./622.cpp) | Array Based |      O(1)       |       O(k)       |
| Python   | [`622.py`](./622.py)   | Array Based |      O(1)       |       O(k)       |
| Rust     | [`622.rs`](./622.rs)   | Array Based |      O(1)       |       O(k)       |

---

## ✅ Test Cases

```text
Input:  ["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
        [[3],[1],[2],[3],[4],[],[],[],[4],[]]
Output: [null,true,true,true,false,3,true,true,true,4]

Input:  ["MyCircularQueue","enQueue","deQueue","Front"]
        [[1],[1],[],[]]
Output: [null,true,true,-1]

Input:  ["MyCircularQueue","enQueue","Rear","isFull","deQueue","isEmpty"]
        [[2],[5],[],[],[],[]]
Output: [null,true,5,false,true,true]
```
