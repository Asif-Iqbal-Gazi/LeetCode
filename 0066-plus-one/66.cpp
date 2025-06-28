/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
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
  vector<int> plusOne(vector<int>& digits) {
    /* Approach:
       1. [Simulation] -- T.C: O(N), S.C: O(1)
          - Start with carry = 1 (since we're adding one)
          - Traverse digits from right to ledt.
          - Update digit: digit = (digit + carry) % 10
          - Carry becomes (digit + carry) / 10
          - After loop, if carry is still 1, insert it at the front.
    */
    int carry    = 1;
    int curr_num = 0;
    int n        = digits.size();

    for (int i = n - 1; i >= 0; i--) {
      curr_num  = digits[i] + carry;
      carry     = curr_num / 10;
      digits[i] = curr_num % 10;
    }

    if (carry) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
// @lc code=end
