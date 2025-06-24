/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
const static auto fast = [] {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    /** Approach: Two Pointers
     */
    int l   = 1;
    int pos = 1;
    int n   = nums.size();

    while (l < n) {
      if (nums[l] != nums[pos - 1]) nums[pos++] = nums[l];
      l++;
    }
    return pos;
  }
};
// @lc code=end
