class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    /* Approach:
     *   1. [Bruteforce] -- T.C: O(N^2), S.C: O(1)
     *   2. [Hash Table] -- T.C: O(N), S.C: O(N)
     */

    /* Approach 1 - Bruteforce
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (target - nums[i] == nums[j])
          return {i, j};
      }
    }
    return {-1, -1};
    */

    // Approach 2 - Hash Table
    int                     n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      auto it = mp.find(target - nums[i]);
      if (it != mp.end())
        return {it->second, i};
      mp[nums[i]] = i;
    }
    return {-1, -1};
  }
};
