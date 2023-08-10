/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Hash Map -- T.C: O(n), S.C: O(n)
                -- Create a map of 101 elements.
                -- Iterate through the nums and set the frequencies in the map array.
                -- Create a new map for storing the cumulative frequency.
                -- Iterate through the map array and new map to build the cumulative frequency.
                -- Iterate through the nums array and take each element as key find the updated frequency from map array and push it into result vector.
            3. Sorting -- T.C: O(nlogn), S.C: O(n)
                -- Create a vector of pairs of nums and index.
                -- Sort the vector.
                -- Iterate through the vector and check if the previous element is same as current element, if yes then update the frequency of current element with the frequency of previous element.
                -- Iterate through the nums array and take each element as key find the updated frequency from map array and push it into result vector.
        */

        // Approach 3 -- Sorting
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], i};

        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            if (v[i].first == v[i - 1].first)
                res[v[i].second] = res[v[i - 1].second];
            else
                res[v[i].second] = i;
        }
        return res;

        /* Approach 2 -- Hash Map
        int n = nums.size();
        vector<int> map(101, 0);
        vector<int> c_map(101, 0);
        vector<int> res(n, 0);

        // Get the normal frequency
        for (int i : nums)
            map[i]++;
        // Build the cumulative frequencies
        for (int i = 1; i < 101; i++)
            c_map[i] = c_map[i - 1] + map[i - 1];
        // Build the result vector from cumulative frequency
        for (int i = 0; i < n; i++) {
            res[i] = c_map[nums[i]];
        }
        return res;
        */

        /* Approach 1 -- Bruteforce
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (i != j && nums[i] > nums[j])
                    count++;
            res[i] = count;
        }
        return res;
        */
    }
};
// @lc code=end
