/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N^2), S.C: O(1)
            2. Using LeftMax + RightMax Array -- T.C: O(N), S.C: O(N)
            3. Using Stack -- T.C: O(N), S.C: O(N)
            4. Using Two Pointers -- T.C: O(N), S.C: O(1)
        */

        // Approach 4
        // Edge Case
        if (height.size() <= 2)
            return 0;

        int res = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int maxLeft = height[0];
        int maxRight = height[n - 1];

        while (l <= r)
        {
            if (maxLeft <= maxRight)
            {
                if (height[l] > maxLeft)
                    maxLeft = height[l]; // Update MaxLeft
                else
                    res += (maxLeft - height[l]); // Update result
                l++;
            }
            else
            {
                if (height[r] > maxRight)
                    maxRight = height[r];
                else
                    res += (maxRight - height[r]);
                r--;
            }
        }
        return res;

        /* Approach 3 -- Using Stack (Tricky Implementation)
        // Edge Case
        if (height.size() <= 2)
            return 0;

        int res = 0;
        stack<int> st;
        int n = height.size();
        // We will maintain a monotonic decreasing stack
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int curr = st.top();
                st.pop();
                // At this time stack might become empty
                if (!st.empty())
                {
                    res += (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[curr]);
                }
            }
            st.push(i);
        }
        return res;
        */

        /* Approach 2
        // Edge Case
        if (height.size() <= 2)
            return 0;

        int res = 0;
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        // Build LeftMax Array
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        // Build rightMax Array
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);

        // Calculating water stored
        for (int i = 0; i < n; i++)
        {
            int waterStored = (min(leftMax[i], rightMax[i]) - height[i]);
            if (waterStored > 0)
                res += waterStored;
        }
        return res;
        */

        /* Approach 1 -- Bruteforce
        // Edge Case
        if (height.size() <= 2)
            return 0;

        int res = 0;
        int n = height.size();
        // For each index find the leftMax & rightMax height
        for (int i = 0; i < n; i++)
        {
            // Find the leftMax height
            int leftMax = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (height[j] > leftMax)
                    leftMax = height[j];
            }
            // Find the rightMax height
            int rightMax = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (height[j] > rightMax)
                    rightMax = height[j];
            }
            int waterStored = min(leftMax, rightMax) - height[i];
            res += waterStored > 0 ? waterStored : 0;
        }
        return res;
        */
    }
};
// @lc code=end
