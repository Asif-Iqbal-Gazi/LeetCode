/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        /* Approach:
            As we can observe, both word1 & word2 length needs to be same
            word1 & word2 needs to have same constituents charcters
            Value of the frequency maps are basically permutations
            Linear Scan -- T.C: O(n + m), S.C: O(26)
        */

        // Approach 1
        int n = word1.size();
        int m = word2.size();

        // Check same length
        if (n != m)
            return false;

        int charMap1[26] = {0};
        int charMap2[26] = {0};

        // Build charMap for word1
        for (char c : word1)
            charMap1[c - 'a']++;

        // Build charMap for word2
        for (char c : word2)
            charMap2[c - 'a']++;

        // Same char set Check
        for (int i = 0; i < 26; i++)
        {
            if ((charMap1[i] || charMap2[i]) && !(charMap1[i] && charMap2[i]))
                return false;
        }

        // Sort the charMaps
        sort(charMap1, charMap1 + 26);
        sort(charMap2, charMap2 + 26);

        // Check the permutations of frequency
        for (int i = 25; i >= 0; i--)
        {
            if (charMap1[i] != charMap2[i])
                return false;
        }

        return true;
    }
};
// @lc code=end
