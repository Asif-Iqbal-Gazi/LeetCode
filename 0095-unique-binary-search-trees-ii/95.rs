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
impl Solution {
    fn build_all_trees(start: i32, end: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if start > end {
            return vec![None];
        }

        let mut all_trees = vec![];
        for root_val in start..=end {
            let left_trees = Self::build_all_trees(start, root_val - 1);
            let right_trees = Self::build_all_trees(root_val + 1, end);

            for left in &left_trees {
                for right in &right_trees {
                    let root = Rc::new(RefCell::new(TreeNode::new(root_val)));
                    root.borrow_mut().left = left.clone();
                    root.borrow_mut().right = right.clone();
                    all_trees.push(Some(root.clone()));
                }
            }
        }
        all_trees
    }

    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        Self::build_all_trees(1, n)    
    }
}
