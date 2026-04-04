#include <unordered_set>

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
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
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;

        /* Approach 2 -- Sorting
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
        */

        /* Approach 1 -- Brute Force
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return true;
        return false;
        */
    }
};
