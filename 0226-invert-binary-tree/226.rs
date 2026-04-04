use std::cell::RefCell;
use std::rc::Rc;
use std::collections::VecDeque;

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn invert_tree(root: Node) -> Node {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Recursively invert left and right subtrees, then swap them.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Use a queue to traverse level by level, swapping children at each node.
         */

        // Approach 1 -- Recursive DFS
        if let Some(node) = root.as_ref() {
            let mut n      = node.borrow_mut();
            let left       = Self::invert_tree(n.left.take());
            let right      = Self::invert_tree(n.right.take());
            n.left         = right;
            n.right        = left;
        }
        root

        /* Approach 2 -- Iterative BFS
        if root.is_none() {
            return None;
        }
        let mut q = VecDeque::new();
        q.push_back(root.clone());
        while let Some(Some(node)) = q.pop_front() {
            let mut n  = node.borrow_mut();
            let left   = n.left.take();
            let right  = n.right.take();
            n.left     = right;
            n.right    = left;
            if n.left.is_some()  { q.push_back(n.left.clone()); }
            if n.right.is_some() { q.push_back(n.right.clone()); }
        }
        root
        */
    }
}
