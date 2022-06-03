/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        /*
        Approach 1:
        1. First find the len of the smallest string.
        2. Run a loop to iterate the first string till "len".
        3. For each char in first string check if other strings in the array contains the char.
        4. If it does not contain the char break the loop, else include it in result.

        Approach 2:
        1. Using a for loop traverse any string (first may be) from the vector.
        2. Inside that loop have another that runs till vecctor size and return the substr(0,i) of first string if we found a miss match between chars from any of the strings or we have reached the end of a string.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        /*Approach 1
        int len = 201;
        string lcp = "";
        for(int i=0; i<strs.size(); i++){
            if(len>strs[i].size())
                len = strs[i].size();
        }
        if(strs.size()==1){
            return strs[0];
        }
        for(int i=0; i<len; i++){
            int t = 1;
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i]==strs[j-1][i])
                   t++;
                else break;
            }
            if(t==strs.size() && t!=1)
                lcp+=strs[0][i];
            else{
                break;
            }
        }
        */
        // Approach 2: Slightly optimised
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
// @lc code=end
