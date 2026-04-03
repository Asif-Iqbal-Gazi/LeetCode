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
use std::rc::Rc;
use std::cell::RefCell;
type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    fn serialize(node: &Node) -> String {
        match node {
            None => ",#".to_string(),
            Some(n) => {
                let n = n.borrow();
                format!(
                    ",{}{}{}",
                    n.val,
                    Self::serialize(&n.left),
                    Self::serialize(&n.right)
                )
            }
        }
    }

    fn is_same_tree(p: &Node, q: &Node) -> bool {
        match (p, q) {
            (None, None) => true,
            (Some(a), Some(b)) => {
                let (a, b) = (a.borrow(), b.borrow());
                a.val == b.val
                    && Self::is_same_tree(&a.left, &b.left)
                    && Self::is_same_tree(&a.right, &b.right)
            }
            _ => false,
        }
    }

    pub fn is_subtree(root: Node, sub_root: Node) -> bool {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(M * N), S.C: O(M + N)
         *      - For each node in root, check if subRoot matches starting from that node.
         *      - M = nodes in root, N = nodes in subRoot
         * 2. Serialization -- T.C: O(M + N), S.C: O(M + N)
         *      - Serialize both trees into strings, then check if subRoot's
         *        serialization is a substring of root's serialization.
         *      - Use delimiters to avoid false matches e.g [12] matching [2]
         */

        // Approach 2 -- Serialization
        let root_str = Self::serialize(&root);
        let sub_str  = Self::serialize(&sub_root);
        root_str.contains(&sub_str)

        // Approach 1 -- DFS
        // match &root {
        //     None => false,
        //     Some(n) => {
        //         let n = n.borrow();
        //         Self::is_same_tree(&root, &sub_root)
        //             || Self::is_subtree(n.left.clone(), sub_root.clone())
        //             || Self::is_subtree(n.right.clone(), sub_root.clone())
        //     }
        // }
    }
}
