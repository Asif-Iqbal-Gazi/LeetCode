/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
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
  int heightChecker(vector<int>& heights) {
    /* Approach:
        1. Counting Sort -- T.C: O(N), S.C: O(N)
            - Use Counting Sort to simulate the sorted order without actually sorting, then count
       mismatches with the original array.
    */

    int n          = heights.size();
    int count[101] = {0};

    // Count frequency of each height
    for (int h : heights) {
      count[h]++;
    }

    int res         = 0;
    int curr_height = 1;
    // Starting from smallest possible height sort without sorting :D
    for (int h : heights) {
      // Skip until non-zero count
      while (count[curr_height] == 0) curr_height++;

      if (h != curr_height) res++;
      count[curr_height]--;
    }

    return res;
  }
};
// @lc code=end
