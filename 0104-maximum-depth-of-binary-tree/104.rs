// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn max_depth(root: Node) -> i32 {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Depth at current node is 1 + max(left, right).
         *        Base case: null node returns 0.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Traverse level by level, incrementing depth counter
         *        for each level processed.
         */

        // Approach 1 -- Recursive DFS
        match root {
            None => 0,
            Some(node) => {
                let n     = node.borrow();
                let left  = Self::max_depth(n.left.clone());
                let right = Self::max_depth(n.right.clone());
                1 + left.max(right)
            }
        }

        /* Approach 2 -- Iterative BFS
        if root.is_none() {
            return 0;
        }
        let mut dq    = VecDeque::new();
        let mut depth = 0;
        dq.push_back(root);
        while !dq.is_empty() {
            let size = dq.len();
            for _ in 0..size {
                if let Some(Some(node)) = dq.pop_front() {
                    let n = node.borrow();
                    if n.left.is_some()  { dq.push_back(n.left.clone()); }
                    if n.right.is_some() { dq.push_back(n.right.clone()); }
                }
            }
            depth += 1;
        }
        depth
        */
    }
}
