/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
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
    int numSquares(int n)
    {
        /* Approach:
        1. BFS
        */

        // For 'n' less than equal 3 return n.
        if (n <= 3)
            return n;

        // Precompute the squares
        int size = sqrt(n) + 1;
        vector<int> squares;
        squares.reserve(size);
        for (int i = 1; i <= size; i++)
            squares.push_back(i * i);

        int count = 1;
        queue<int> q;
        unordered_set<int> seen;

        q.push(n);
        seen.insert(n);

        while (!q.empty())
        {
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                // Get the queue size for this level
                int curr = q.front();
                q.pop();
                // Now check with squares
                for (auto x : squares)
                {
                    // 'x' is greater than curr, break
                    if (x > curr)
                        break;
                    // 'x' == 'curr' so return coount
                    else if (x == curr)
                        return count;
                    // If we are visiting (curr - x) for the first time, push it to queue and seen set
                    else if (seen.find(curr - x) == seen.end())
                    {
                        seen.insert(curr - x);
                        q.push(curr - x);
                    }
                }
            }
            // Couldn't find in this level, increase count
            count++;
        }
        return count;
    }
};
// @lc code=end
