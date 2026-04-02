impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        // Approach 1: Xor Technique -- T.C: O(N), S.C: O(1)
        
        let mut missing: i32 = nums.len() as i32;

        for (i, num) in nums.iter().enumerate() {
            missing ^= i as i32 ^ num;
        }
        missing
    }
}
