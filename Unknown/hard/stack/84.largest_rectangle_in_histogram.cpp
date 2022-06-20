/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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
    int largestRectangleArea(vector<int> &heights)
    {
        /* Approach:
        1. Bruteforce --- T.C: O(N^2)
            For each height in the array, find bars to it's left and right that has height greater or equal to it's height.
            Then calculate the area, if this is largest update the global result.
            Do it for all heights.
        2. Using Stack -- T.C: O(N), S.C: O(N)
            Total Pass - 3
            For the height array we will prepare next smallest and prev smallest height arrays using stack.
            Then during traversal of heights array, using previous & next smallest height array we will calculate area.
        3. Using Stak (Efficient Solution) -- T.C: O(N), S.C: O(N)
            No Of Passes - 1
            Just like before we will calculate prev smaller element and the area for a particular bar
            We get the previous smaller during poping from stack
        */

        // Approach 2: Efiicient Solution

        int n = heights.size(), res = 0;
        stack<int> s;

        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                res = max(res, height * width);
            }
            s.push(i);
        }
        return res;

        /* Approach 2
        int n = heights.size(), res = 0;
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        stack<int> s1, s2;

        // Prepare Next Smallest Height Array
        s1.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s1.empty() && heights[s1.top()] >= heights[i])
                s1.pop();
            next[i] = s1.empty() ? n : s1.top();
            s1.push(i);
        }

        // Prepare Prev Smallest Height Array
        s2.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!s2.empty() && heights[s2.top()] >= heights[i])
                s2.pop();
            prev[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }

        // Now calculate area taking each height as smallest
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            curr += (i - prev[i] - 1) * heights[i];
            curr += (next[i] - i - 1) * heights[i];
            res = max(res, curr);
        }
        return res;
        */

        /* Approach 1 (Gets TLE due TC)
        int n = heights.size(), res = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            // Find the bars towards left of the current bar with height greater or equal
            for (int j = i - 1; j >= 0; j--)
            {
                if (heights[j] >= heights[i])
                    // Keep adding the area
                    curr += heights[i];
                else
                    break;
            }
            // Find the bars towards right of the current bar with height greater or equal
            for (int j = i + 1; j < n; j++)
            {
                if (heights[j] >= heights[i])
                    // Keep adding the area
                    curr += heights[i];
                else
                    break;
            }
            // Now update the global result
            res = max(res, curr);
        }
        return res;
        */
    }
};
// @lc code=end
