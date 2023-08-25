/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
   private:
    int N;
    int maxWidth;
    int alreadyTaken;
    vector<int> preFixLength;
    bool isPossible(int count) {  // T.C: O(1)
        int spaceNeeded = count - alreadyTaken - 1;
        int totalWordsLen = preFixLength[count] - preFixLength[alreadyTaken];
        return (totalWordsLen + spaceNeeded) <= maxWidth;
    }
    int fitWords(int fromIndex, vector<string> &words, vector<string> &ans) {
        // Binary Search
        int l = alreadyTaken, r = N + 1;
        // Invariance
        // isPossible(l) is always true
        // isPossible(r) is always false
        while (l + 1 < r) {  // T.C: O(log n)
            int m = l + (r - l) / 2;
            if (isPossible(m))
                l = m;
            else
                r = m;
        }
        // We can place (alreadyTaken, l] in our curr
        int wordCount = l - alreadyTaken;
        int totalWordsLen = preFixLength[l] - preFixLength[alreadyTaken];
        int spaceNeeded = maxWidth - totalWordsLen;
        int gapNeeded = 1, extraGap = 0;
        if (wordCount > 1 && l != N) {
            gapNeeded = spaceNeeded / (wordCount - 1);
            extraGap = spaceNeeded % (wordCount - 1);
        }
        int k = 0;
        string curr(maxWidth, ' ');               // T.C: O(maxWidth)
        for (int i = alreadyTaken; i < l; i++) {  // T.C: O(maxWidth)
            for (int j = 0; j < words[i].size(); j++) {
                curr[k++] = words[i][j];
            }
            // Put Spaces
            k += gapNeeded;
            if (extraGap) {
                k++;
                extraGap--;
            }
        }
        // Update alreadyTaken
        alreadyTaken = l;
        ans.push_back(curr);
        return l;
    }

   public:
    vector<string> fullJustify(vector<string> &words, int _maxWidth) {
        /* Approach:
            1. Binary Search -- T.C: O(n * (maxWidth + log n)), S.C: O(n)
        */

        // Approach 1
        alreadyTaken = 0;
        N = words.size();
        maxWidth = _maxWidth;
        preFixLength.assign(N + 1, 0);
        // Calculate Prefix Length
        for (int i = 1; i <= N; i++) {
            preFixLength[i] = preFixLength[i - 1] + words[i - 1].size();
        }

        vector<string> ans;

        int i = 0;
        while (i < N) {  // T.C: O(n * (maxWidth + log n))
            i = fitWords(i, words, ans);
        }
        /* Reasoning behind the time complexity:
            In the worst case, we are given such words, that our output contains only one word in each line
            Complexity of our fitWords() function is O(maxWidth + log (Search Range))
            In this case:
                i is incremented by 1 and serach space reduces by 1
                so the while loop will run 'N' times to call fitWords() function
                Time Complexity:
                    [maxWidth + log (N)] + [maxWidth + log (N - 1)] + . . . . . [maxWidth + log (2)]
                    Which is = N * (maxWidth + log N)
        */
        return ans;
    }
};
// @lc code=end
