/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        /* Approach:
            1. Using Map -- T.C: O(n), S.C: O(52)
            2. Same as Above (Space Optimised) -- T.C: O(n), S.C: O(26)
        */

        // Approach 2
        int charFreqMap[26] = {0};

        for (char c : magazine)
        {
            charFreqMap[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            charFreqMap[c - 'a']--;
            if (charFreqMap[c - 'a'] < 0)
                return false;
        }

        return true;

        /* Approach 1
        int charMapNote[26] = {0};
        int charMapMagazine[26] = {0};

        for (char c : ransomNote)
        {
            charMapNote[c - 'a']++;
        }

        for (char c : magazine)
        {
            charMapMagazine[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (charMapMagazine[i] < charMapNote[i])
                return false;
        }

        return true;
        */
    }
};
// @lc code=end
