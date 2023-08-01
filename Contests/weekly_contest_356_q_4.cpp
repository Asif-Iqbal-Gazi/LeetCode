/*
    2801. Count Stepping Numbers in Range
    https://leetcode.com/problems/count-stepping-numbers-in-range/
*/

class Solution {
   private:
    int N;
    string MAX;
    const int MOD = 1e9 + 7;
    int dp[2][2][10][101];

    string subOne(string num) {
        // As per the constraints, num will be a valid number
        int j = num.size() - 1;
        while (j >= 0 && num[j] == '0') {
            num[j--] = '9';
        }
        if (j >= 0)
            num[j]--;
        return num;
    }

    int noOfSteppingNumbersLessThanEqualMAX(bool leadingZero, bool isSmaller, int ind, int lastDigit) {
        // Base Case
        if (ind == N)
            return 1;

        int &ans = dp[leadingZero][isSmaller][lastDigit][ind];
        if (ans != -1)
            return ans;

        ans = 0;
        int end = isSmaller ? 9 : MAX[ind] - '0';
        for (int i = 0; i <= end; i++) {
            if (!leadingZero && abs(i - lastDigit) != 1) continue;
            /*  Explanation:
                1. If leadingZero is already false, then it will remain false,
                    however if it is true, and we have picked a non-zero digit, then it will become false for next iteration.
                2. If isSmaller is already true, then it will remain true,
                    however if it is false, and we have picked a digit == MAX[ind], then it will become true for next iteration.
            */
            ans = (ans + noOfSteppingNumbersLessThanEqualMAX(!leadingZero ? false : (i == 0), isSmaller ? true : (i != end), ind + 1, i)) % MOD;
        }
        return ans;
    }

    int noOfSteppingNumbersLessThan(string num) {
        N = num.size();
        MAX = num;                   // T.C: O(n), S.C: O(n
        memset(dp, -1, sizeof(dp));  // T.C: O(n), S.C: O(n)
        return noOfSteppingNumbersLessThanEqualMAX(true, false, 0, 0);
    }

   public:
    int countSteppingNumbers(string low, string high) {
        /* Approach:
            1. BruteForce -- T.C: O(n), S.C: O(1)
                Can check if the number is stepping number or not in O(D) time, D = number of digits
                Thus we can check for all numbers in range [low, high] in O(n * D) time
                Given constraints are (int)low <= (int)high <= 10^100
                Surely, bruteforce will give TLE
            1. Digit DP -- T.C: O(40 * n), S.C: O(40 * n)
                We can use digit dp to solve this problem
                We can find the number of stepping numbers less than equal to 'high' in O(n) time
                We can find the number of stepping numbers less than equal to 'low - 1' in O(n) time
                Thus, the answer will be (number of stepping numbers less than equal to 'high') - (number of stepping numbers less than equal to 'low - 1'
        */

        return (noOfSteppingNumbersLessThan(high) - noOfSteppingNumbersLessThan(subOne(low)) + MOD) % MOD;
    }
};