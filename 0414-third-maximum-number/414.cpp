/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
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
  int thirdMax(vector<int>& nums) {
    /* Approach:
       1. Track top 3 unique numbers -- T.C: O(N), S.C: O(1)
          - Use 3 variables (first, second, third), initialized to LLONG_MIN.
          - Skip duplicates while updating the top 3 max values.
    */

    long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

    for (int num : nums) {
      if (num == first || num == second || num == third)
        continue;

      if (num > first) {
        third  = second;
        second = first;
        first  = num;
      } else if (num > second) {
        third  = second;
        second = num;
      } else if (num > third) {
        third = num;
      }
    }

    return (third == LLONG_MIN) ? first : third;
  }
};
// @lc code=end
