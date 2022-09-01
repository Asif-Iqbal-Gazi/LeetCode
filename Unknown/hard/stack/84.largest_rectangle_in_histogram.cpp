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

        // Approach 3 -- Efficient Algorithm
        int res = 0;
        stack<int> s;
        int n = heights.size();

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
        int res = 0;
        int n = heights.size();
        stack<int> s;
        int prevSmaller[n];
        int nextSmaller[n];

        // Calculate prevSmaller array
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            prevSmaller[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }

        // Empty the stack for reuse in nextSmaller array calculation
        while (!s.empty())
            s.pop();

        // Calculate nextSmaller array
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            nextSmaller[i] = s.empty() ? n - 1 : s.top() - 1;
            s.push(i);
        }

        // Next pass to calculate the area
        for (int i = 0; i < n; i++)
        {
            int curr_area = heights[i] * (nextSmaller[i] - prevSmaller[i] + 1);
            res = max(res, curr_area);
        }

        return res;
        */

        /* Approach 1 -- Bruteforce
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int curr_area = heights[i];
            // Find bars towards left with height >= heights[i]
            for (int j = i - 1; j >= 0; j--)
            {
                if (heights[j] >= heights[i])
                    // Keep adding the area
                    curr_area += heights[i];
                else
                    break;
            }
            // Find bars towards right with height >= heights[i]
            for (int j = i + 1; j < n; j++)
            {
                if (heights[i] <= heights[j])
                    // Keep adding the area
                    curr_area += heights[i];
                else
                    break;
            }
            // Update the res varibale
            res = max(res, curr_area);
        }
        return res;
        */
    }
};
// @lc code=end
