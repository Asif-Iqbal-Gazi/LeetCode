/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
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
  bool checkIfExist(vector<int>& arr) {
    // Approach: unordered_set
    int                n = arr.size();
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
      if (set.count(2 * arr[i]) > 0 || (arr[i] % 2 == 0 && set.count(arr[i] / 2) > 0))
        return true;
      else
        set.insert(arr[i]);
    }
    return false;
  }
};
// @lc code=end
