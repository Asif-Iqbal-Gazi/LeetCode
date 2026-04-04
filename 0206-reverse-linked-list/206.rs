// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        /*
         * Approach:
         * 1. Iterative -- T.C: O(N), S.C: O(1)
         *      - Use prev and curr. Reverse the link at each node
         *        and advance forward until curr is None.
         * 2. Recursive -- T.C: O(N), S.C: O(N)
         *      - Recurse to the end of the list, then reverse
         *        links on the way back up the call stack.
         */

        // Approach 1 -- Iterative
        let mut prev = None;
        let mut curr = head;
        while let Some(mut node) = curr {
            curr       = node.next.take(); // detach next
            node.next  = prev;             // reverse link
            prev       = Some(node);       // advance prev
        }
        prev

        /* Approach 2 -- Recursive
        match head {
            None => None,
            Some(mut node) => {
                match node.next.take() {
                    None => Some(node),
                    Some(next) => {
                        let mut new_head = Self::reverse_list(Some(next));
                        // attach current node to end of reversed list
                        let mut tail = &mut new_head;
                        while tail.as_ref().unwrap().next.is_some() {
                            tail = &mut tail.as_mut().unwrap().next;
                        }
                        tail.as_mut().unwrap().next = Some(node);
                        new_head
                    }
                }
            }
        }
        */
    }
}
