/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution
{
private:
    bool isValidChar(char c)
    {
        if (c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.')
            return false;
        return true;
    }

public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        /* Approach :
            1. Naive Method
                Remove all punctuation, convert everything to lowercase.
                Extract each word and build a word map
        */

        string ans;
        int count = INT_MIN;
        int n = paragraph.size();
        unordered_map<string, int> wordMap;
        // Banned Set
        unordered_set<string> banSet(banned.begin(), banned.end());

        // Extract word from paragraph & build wordmap
        int r = 0;
        while (r < n)
        {
            string word;
            while (r < n && isValidChar(paragraph[r]))
            {
                char c = paragraph[r];
                // If in upper case convert to lowercase
                if (c <= 90 && c >= 65)
                    c += 32;
                word += c;
                r++;
            }
            // Check if word is banned
            if (word.size() != 0 && banSet.find(word) == banSet.end())
                wordMap[word]++;
            // Update the index
            r++;
        }

        // Traverse the wordMap to get the most frequnt word
        for (auto it : wordMap)
            if (it.second > count)
            {
                count = it.second;
                ans = it.first;
            }

        return ans;
    }
};
// @lc code=end
