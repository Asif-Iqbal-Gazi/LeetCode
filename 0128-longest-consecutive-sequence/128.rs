
use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        /*
         * Approach:
         * 1. Hash Set -- T.C: O(N), S.C: O(N)
         *      - Use set, start only from sequence starts.
         * 2. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort and count consecutive elements.
         */

        // Approach 1 -- Hash Set
        let set: HashSet<i32> = nums.iter().cloned().collect();
        let mut longest = 0;

        for &num in &set {
            if !set.contains(&(num - 1)) {
                let mut curr = num;
                let mut streak = 1;

                while set.contains(&(curr + 1)) {
                    curr += 1;
                    streak += 1;
                }

                longest = longest.max(streak);
            }
        }

        longest

        /* Approach 2 -- Sorting
        let mut nums = nums;
        if nums.is_empty() { return 0; }
        nums.sort();
        let mut longest = 1;
        let mut curr = 1;
        for i in 1..nums.len() {
            if nums[i] == nums[i-1] { continue; }
            else if nums[i] == nums[i-1] + 1 { curr += 1; }
            else {
                longest = longest.max(curr);
                curr = 1;
            }
        }
        longest.max(curr)
        */
    }
}
