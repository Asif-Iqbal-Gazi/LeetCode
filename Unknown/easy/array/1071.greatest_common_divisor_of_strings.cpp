/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
private:
    /* Approach 1
    string buildRepString(const string &base, int k) {
        string ans = "";
        while(k--) {
            ans += base;
        }
        return ans;
    }

    bool isValid(const string &str1, const string &str2, int sz) {
        int n = str1.size();
        int m = str2.size();
        // Check if base can actually constitute str1 or str2
        if(n % sz > 0 || m % sz > 0)
            return false;
        string base = str1.substr(0, sz);       // O(sz)
        int s1Rep = n / sz;
        int s2Rep = m / sz;

        return str1 == buildRepString(base, s1Rep) &&
               str2 ==  buildRepString(base, s2Rep); // O(m + n)
    }
    */
public:
    string gcdOfStrings(string str1, string str2)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(min(m, n) * (m + n)), S.C: O(min(m, n))
            2. GCD Approach -- T.C: O(m + n), S.C: O(m + n)
        */

        // Approach 2
        // By Definition if there exist a GCD string then following should be true
        if (str1 + str2 != str2 + str1)
            return "";

        // We are here means there exist a GCD string
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);

        /* Approach 1
        int n = str1.size();
        int m = str2.size();

        // Start from bigger sized base
        for(int i = min(n, m); i > 0; i--) {        // O(min(m, n) * (m + n))
            if(isValid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }

        return "";
        */
    }
};
// @lc code=end
