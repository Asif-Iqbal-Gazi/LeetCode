/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        /* Approach:
            1. Traverse the string and add the values -- T.C: O(n), S.C: O(1)
        */

        // Approach 1
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'I':
                // Check next char to see if we have 'IV' situation
                if (i + 1 < n && s[i + 1] == 'V')
                {
                    ans += 4;
                    i++;
                }
                else if (i + 1 < n && s[i + 1] == 'X')
                {
                    ans += 9;
                    i++;
                }
                else
                    ans += 1;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                // Check next char to see if we have 'XL' situation
                if (i + 1 < n && s[i + 1] == 'L')
                {
                    ans += 40;
                    i++;
                }
                else if (i + 1 < n && s[i + 1] == 'C')
                {
                    ans += 90;
                    i++;
                }
                else
                    ans += 10;
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                // Check next char to see if we have 'CD' situation
                if (i + 1 < n && s[i + 1] == 'D')
                {
                    ans += 400;
                    i++;
                }
                else if (i + 1 < n && s[i + 1] == 'M')
                {
                    ans += 900;
                    i++;
                }
                else
                    ans += 100;
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            default:
                printf("Invalid Input\n");
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
