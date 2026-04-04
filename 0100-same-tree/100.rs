use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn is_same_tree(p: Node, q: Node) -> bool {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Recursively check if current nodes are equal, then verify
         *        left and right subtrees match.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Use a queue to traverse both trees simultaneously,
         *        comparing nodes level by level.
         */

        // Approach 1 -- Recursive DFS
        match (p, q) {
            (None, None) => true,
            (Some(a), Some(b)) => {
                let (a, b) = (a.borrow(), b.borrow());
                a.val == b.val
                    && Self::is_same_tree(a.left.clone(), b.left.clone())
                    && Self::is_same_tree(a.right.clone(), b.right.clone())
            }
            _ => false,
        }

        /* Approach 2 -- Iterative BFS
        let mut dq = VecDeque::new();
        dq.push_back((p, q));
        while let Some((np, nq)) = dq.pop_front() {
            match (np, nq) {
                (None, None) => continue,
                (Some(a), Some(b)) => {
                    let (a, b) = (a.borrow(), b.borrow());
                    if a.val != b.val { return false; }
                    dq.push_back((a.left.clone(),  b.left.clone()));
                    dq.push_back((a.right.clone(), b.right.clone()));
                }
                _ => return false,
            }
        }
        true
        */
    }
}
