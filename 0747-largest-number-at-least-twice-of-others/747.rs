impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
       use std::i32::MIN;
       let mut index: usize = 0;
       let (mut largest, mut second_largest): (i32, i32) = (MIN, MIN);

       for (i, &num) in nums.iter().enumerate() {
           if num > largest {
               second_largest = largest;
               largest = num;
               index = i;
           } else if num > second_largest {
               second_largest = num;
           }
       }

       if largest >= 2 * second_largest {
           index as i32
       }
       else {
           -1
       }
    }
}
