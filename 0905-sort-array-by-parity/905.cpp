/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
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
  vector<int> sortArrayByParity(vector<int>& nums) {
    /* Approach:
        1. Using Two Pointer -- T.C: O(N), S.C: O(1)
    */

    int l    = 0;
    int temp = 0;
    int n    = nums.size();
    int r    = nums.size() - 1;

    while (l < r) {
      if (nums[l] & 1) {
        // Odd, Swap it
        temp      = nums[l];
        nums[l]   = nums[r];
        nums[r--] = temp;
      } else
        l++;
    }
    return nums;
  }
};
// @lc code=end
