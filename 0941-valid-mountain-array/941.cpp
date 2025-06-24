/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
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
  bool validMountainArray(vector<int>& arr) {
    /**
    Approach: Two Pointer
         Take two loops, first will iterate from left most element and breaks if immediate next
    element is not greater Second wil iterate from rightmost element and break if immediate previous
    element is not greater. Finally, if left pointer is non-zero and right point is not n-1 indexed
    and are equal then return true, else false.
    */
    int l = 0;
    int r = 0;
    int n = arr.size();

    for (l = 0; l < n - 1; l++) {
      if (arr[l] >= arr[l + 1]) break;
    }

    for (r = n - 1; r > 0; r--) {
      if (arr[r] >= arr[r - 1]) break;
    }

    return (l && (r != n - 1) && (l == r)) ? true : false;
  }
};
// @lc code=end
