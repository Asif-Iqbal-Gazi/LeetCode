/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /* Approach : Two Pointers */
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    if (n == 0) return;

    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    // If nums2 has any leftover
    while (j >= 0) nums1[k--] = nums2[j--];
  }
};
// @lc code=end
