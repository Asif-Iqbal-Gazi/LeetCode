/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        /*
        Approach:
        1. Using a map first store the restaurant name as key and index as value for the first list.
        2. Now, traverse through the second and check if the restaurant from this list exists in the map. If so, calculate the index sums and check if this index sum is smaller than previous indexSum. If so clear the vector res and push restaurant name to res.
        3. Also, check if the indexSum is equal to the previous index sum, in this case push the restaurant name in the list as well.
        */

        vector<string> res;
        unordered_map<string, int> firstList;
        int m = list1.size(), n = list2.size(), indexSum = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            firstList[list1[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (firstList.find(list2[i]) != firstList.end())
            {
                int curr_indexSum = firstList.find(list2[i])->second + i;
                if (curr_indexSum < indexSum)
                {
                    res.erase(res.begin(), res.end());
                    indexSum = curr_indexSum;
                    res.emplace_back(firstList.find(list2[i])->first);
                }
                else if (curr_indexSum == indexSum)
                {
                    res.emplace_back(firstList.find(list2[i])->first);
                }
            }
        }
        return res;
    }
};
// @lc code=end
