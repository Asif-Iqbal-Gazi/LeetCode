/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
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
  int dominantIndex(vector<int>& nums) {
    /* Approach:
       1. [Math Logic] -- T.C: O(N), S.C: O(1)
        - Track largest and second largest elements in a single pass.
        - Return index of the largest if it is at least twice the second largest.
    */

    int n              = nums.size();
    int largest        = 0;
    int second_largest = 0;
    int max_index      = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] > largest) {
        second_largest = largest;
        largest        = nums[i];
        max_index      = i;
      } else if (nums[i] > second_largest) {
        second_largest = nums[i];
      }
    }
    return (largest >= 2 * second_largest) ? max_index : -1;
  }
};
// @lc code=end
