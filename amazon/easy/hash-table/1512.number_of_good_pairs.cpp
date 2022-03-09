class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        /*
        Approach:
        1. Use an unordred_map to capture frequencies of all unique elements.
        2. Observe, that if a unique number has frequency n then there are n*(n-1)/2 good pairs.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> map;
        int result = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            int i = it->second;
            result += ((i - 1) * i) / 2;
        }
        return result;
    }
};