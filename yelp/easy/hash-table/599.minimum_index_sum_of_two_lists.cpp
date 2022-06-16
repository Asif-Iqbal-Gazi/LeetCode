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
        1. Bruteforce -- O(N*M)
        2. Unordered_Map - O(M + N), SC: O(min(M,N))
            Using a map first store the restaurant name as key and index as value for the first list.
            Now, traverse through the second and check if the restaurant from this list exists in the map. If so, calculate the index sums and check if this index sum is smaller than previous indexSum. If so clear the vector res and push restaurant name to res.
            Also, check if the indexSum is equal to the previous index sum, in this case push the restaurant name in the list as well.
        */

        /* Bruteforce
        vector<string> result;
        int n1 = list1.size(), n2 = list2.size(), currIndexSum = 0, sumIndex = INT_MAX;

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (list1[i] == list2[j])
                { // Found a Match
                    currIndexSum = (i + j);
                    if (currIndexSum < sumIndex)
                    { // Found a least index, empty container and push the new entry
                        result.clear();
                        sumIndex = currIndexSum;
                        result.emplace_back(list1[i]);
                    }
                    else if (currIndexSum == sumIndex)
                        // Found a Tie
                        result.emplace_back(list1[i]);
                }
            }
        }
        return result;
        */

        // Using Unordered_Map
        vector<string> result;
        unordered_map<string, int> map;

        int n1 = list1.size(), n2 = list2.size(), indexSum = INT_MAX;
        // For O(min(N1, N2)) Space complexity
        if (n1 > n2)
            return findRestaurant(list2, list1);
        // Building the Map
        for (int i = 0; i < n1; i++)
            map[list1[i]] = i;

        for (int i = 0; i < n2; i++)
        {
            auto it = map.find(list2[i]);
            if (it != map.end())
            {
                // Found a Match
                int currIndexSum = i + it->second;
                if (currIndexSum < indexSum)
                {
                    // Current Index is less, Empty Container and Push
                    result.clear();
                    // Update indexSum
                    indexSum = currIndexSum;
                    result.emplace_back(list2[i]);
                }
                else if (currIndexSum == indexSum)
                    // Tie Situation
                    result.emplace_back(list2[i]);
            }
        }
        return result;
    }
};
// @lc code=end
