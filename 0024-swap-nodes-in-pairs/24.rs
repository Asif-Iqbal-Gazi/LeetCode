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
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode {val: 0, next: head}));
        let mut prev = &mut dummy;

        while let Some(ref mut node1) = prev.as_mut().unwrap().next {
            if let Some(mut node2) = node1.next.take() {
                node1.next = node2.next.take();
                node2.next = Some(node1.clone());
                prev.as_mut().unwrap().next = Some(node2);

                prev = &mut prev.as_mut().unwrap().next.as_mut().unwrap().next;
            } else {
                break;
            }
        }

        dummy.unwrap().next
    }
}
