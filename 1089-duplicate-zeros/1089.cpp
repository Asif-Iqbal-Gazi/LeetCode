/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
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
  void duplicateZeros(vector<int>& arr) {
    /* Approach: Two Pointer
       Start from left, when zero is encountered insert another one, pop one from right.
    */
    int n = arr.size();
    int l = 0;
    int r = n - 1;

    while (l < r) {
      if (arr[l] == 0) {
        arr.insert(arr.begin() + l, 0);
        arr.pop_back();
        l += 2;
        continue;
      }
      l++;
    }
  }
};
// @lc code=end
