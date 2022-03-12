/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        /*
        Approach:
        1. Create a map for array 1.
        2. Then check if array2 element is present in the map.
        3. If yes, then get the frequency from and insert that many elements into the result array. Finally erase the entry from map.
        4. Next, iterate over the map and get the frequencies of the elements and insert them into the result array.
        */
        int k = 0;
        map<int, int> mp;
        vector<int> res = arr1;

        for (int x : arr1)
            mp[x]++;

        for (int x : arr2)
        {
            if (mp.find(x) != mp.end())
            {
                while (mp[x]--)
                {
                    res[k++] = x;
                }
                mp.erase(x);
            }
        }

        for (auto x : mp)
        {
            int count = x.second;
            while (count--)
            {
                res[k++] = x.first;
            }
        }
        return res;
    }
};
// @lc code=end
