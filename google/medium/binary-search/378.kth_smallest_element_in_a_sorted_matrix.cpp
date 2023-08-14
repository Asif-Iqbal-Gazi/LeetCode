/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        // Approach 1 -- Linear Scan
        int n = matrix.size();

        int i = 0, j = n - 1, count = 0;
        while (i < n && j >= 0) {
            count += j + 1;
            cout << count << endl;
            if (count == k) {
                return matrix[i][j];
            } else if (count < k) {
                i++;
            } else {
                count -= j + 1;
                j--;
            }
        }
        return -1;
    }
};
// @lc code=end
