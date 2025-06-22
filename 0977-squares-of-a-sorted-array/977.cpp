/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
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
  vector<int> sortedSquares(vector<int>& nums) {
    /*
    Approach: Two Pointers
    Take leftmost and rightmost element, compare their absolute value, square the max and put into
    the ans array
    */
    int         n = nums.size();
    int         l = 0, r = n - 1, i = n - 1;
    vector<int> ans(n, 0);
    while (l <= r) {
      if (abs(nums[l]) > abs(nums[r])) {
        ans[i--] = nums[l] * nums[l];
        l++;
      } else {
        ans[i--] = nums[r] * nums[r];
        r--;
      }
    }
    return ans;
  }
};
// @lc code=end
