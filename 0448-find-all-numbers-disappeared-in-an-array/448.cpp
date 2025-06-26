/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    /* Approach:
       1. In-Place Marking -- T.C: O(N), S.C: O(1) (excluding result)
          - Iterate through the array and for each number num, mark the index abs(num) - 1 as
       visited by negating the number at that index.
          - Then iterate again and collect the indices where the nubmer is still positive, as those
       indices were not visited.
    */

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] > 0)
        nums[index] = -nums[index];
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0)
        res.emplace_back(i + 1);
    }
    return res;
  }
};
// @lc code=end
