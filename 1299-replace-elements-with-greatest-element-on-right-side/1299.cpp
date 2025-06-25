/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
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
  vector<int> replaceElements(vector<int>& arr) {
    // Approach: Traverse form right maintaining greatest element seen so far.

    int curr      = -1;
    int right_max = -1;
    int r         = arr.size() - 1;

    while (r >= 0) {
      curr     = arr[r];
      arr[r--] = right_max;
      if (curr > right_max) right_max = curr;
    }
    return arr;
  }
};
// @lc code=end
