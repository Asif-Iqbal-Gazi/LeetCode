use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        /*
         * Approach:
         * 1. Brute Force -- T.C: O(N^2),     S.C: O(1)
         *      - For each element, check all subsequent elements for a duplicate.
         * 2. Sorting     -- T.C: O(N log N), S.C: O(1)
         *      - Sort the array. Duplicates will be adjacent.
         * 3. Hash Set    -- T.C: O(N),       S.C: O(N)
         *      - Insert each element into a hash set.
         *        If already present, a duplicate is found.
         */

        // Approach 3 -- Hash Set
        let mut seen = HashSet::new();
        for num in nums {
            if !seen.insert(num) {
                return true;
            }
        }
        false

        /* Approach 2 -- Sorting
        let mut nums = nums;
        nums.sort();
        for i in 1..nums.len() {
            if nums[i] == nums[i - 1] {
                return true;
            }
        }
        false
        */

        /* Approach 1 -- Brute Force
        for i in 0..nums.len() {
            for j in (i + 1)..nums.len() {
                if nums[i] == nums[j] {
                    return true;
                }
            }
        }
        false
        */
    }
}
