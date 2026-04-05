class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        /*
         * Approach:
         * 1. Hash Set -- T.C: O(N), S.C: O(N)
         *      - Use set, start only from sequence starts.
         * 2. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort and contains consecutive elements.
         */

        // Approach 1 -- Hash Set
        unordered_set<int> s(nums.begin(), nums.end());
        int                longest = 0;

        for (int num : s) {
            if (!s.contains(num - 1)) {
                int curr   = num;
                int streak = 1;

                while (s.contains(curr + 1)) {
                    curr++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;

        /* Approach 2 -- Sorting
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            else if (nums[i] == nums[i - 1] + 1) curr++;
            else {
                longest = max(longest, curr);
                curr = 1;
            }
        }
        return max(longest, curr);
        */
    }
};
