/*
    2798. Number of Employees Who Met the Target
    https://leetcode.com/problems/number-of-employees-who-met-the-target/description/
*/

class Solution {
   public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        int ans = 0;

        for (int x : hours) {
            if (x >= target)
                ans++;
        }
        return ans;
    }
};