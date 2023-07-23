/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution
{
private:
    bool isValidSubstring(int len, int k, string s)
    {
        int freqMap[26] = {0};
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int n = s.size();

        while (r < n)
        {
            freqMap[s[r] - 'A']++;
            // Exceeded windowSize
            if (r - l + 1 > len)
            {
                freqMap[s[l] - 'A']--;
                l++;
            }
            // Update maxFreq
            maxFreq = max(maxFreq, freqMap[s[r] - 'A']);
            // Check if we have a valid Window
            if (len - maxFreq <= k)
            {
                return true;
            }
            r++;
        }
        return false;
    }

public:
    int characterReplacement(string s, int k)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Binary Search + Sliding Window -- T.C: O(n log n), S.C: O(1)
                Idea from Bruteforce:
                    If substring l to l + i is valid, then, all substring within this range in valid.
                So, we will bianry search over entire length
            3. Purely Sliding Window
        */

        // Approach 3 -- Sliding Window
        /* Dry Run
        s = "AAAABBCC|CCCC"
        k = 2

        l = 2
        r = 8
        ans = 6
        maxFreq = 4
        freqMap = {'A': 2, 'B': 2, 'C': 2}
        */
        int ans = 0;
        int maxFreq = 0;
        int l = 0, r = 0, n = s.size();

        int freqMap[26] = {0};

        while (r < n)
        {
            freqMap[s[r] - 'A']++;
            maxFreq = max(maxFreq, freqMap[s[r] - 'A']);
            r++;

            // Exceeded no of operations
            // No. of ops = currwindowLenght - maxFreq
            while (r - l - maxFreq > k)
            {
                freqMap[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l);
        }

        return ans;

        /* Approach 2 -- Binray Search + Sliding Window
        int l = 1;
        int r = s.size() + 1;
        // Binary Search Invariance
        //    isValidSubstring(l) <= maxLen
        //    !isValidSubstring(r) > maxLen

        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(isValidSubstring(m, k, s))
                l = m;
            else
                r = m;
        }
        return l;
        */

        /* Approach 1 -- Bruteforce
        int ans = 1;
        int i = 0, j = 0, n = s.size();
        int currOps = 0, windowSize = 0;

        for(i = 0; i < n; i++) {
            int maxFreq = 0;
            unordered_map<char, int> charMap;
            for(j = i; j < n; j++) {
                charMap[s[j]]++;
                maxFreq = max(maxFreq, charMap[s[j]]);
                windowSize = (j - i + 1);
                currOps = windowSize - maxFreq;
                if(currOps <= k)
                    ans = max(ans, windowSize);
                else break;
            }

        }
        return ans;
        */
    }
};
// @lc code=end
