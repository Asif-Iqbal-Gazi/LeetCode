class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        /*
        Approach:
        1. In a set store all the jewels.
        2. While traversing the stones string, check if it is present in the jewels set.
        3. If so, increment the count.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        unordered_set<char> set;

        for (char c : jewels)
            set.insert(c);

        for (char c : stones)
        {
            if (set.find(c) != set.end())
                count++;
        }

        return count;
    }
};