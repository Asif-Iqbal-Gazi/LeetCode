/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    int binarySearch(vector<int> &row)
    {
        int l = 0, m = 0;
        int r = row.size();

        while (l < r)
        {
            m = l + (r - l) / 2;
            if (row[m] == 1)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        /* Approach:
            1. Naive Method -- T.C: O(m * (n + log m)), S.C: O(n)
            2. Optimised Naive Method -- T.C: O(m * (log (n*m))), S.C: O(n)
            3. Using Priority Queue -- T.C: O(m * log (n*k)), S.C : O(k)
            4. Optimal (Vertical Iteration) -- T.C: O(m*n), S.C: O(1)
        */

        // Approach 4
        int m = mat.size();
        int n = mat[0].size();

        int currIndex = 0;
        vector<int> ans(k, 0);

        // Do vertical serach, if encountered '0' check if previous element was '1'
        for (int j = 0; j < n && currIndex < k; j++)
        {
            for (int i = 0; i < m && currIndex < k; i++)
            {
                if (mat[i][j] == 0 && (j == 0 || mat[i][j - 1] == 1))
                    ans[currIndex++] = i;
            }
        }

        // For those row which only has 1s
        for (int i = 0; currIndex < k; i++)
        {
            if (mat[i][n - 1] == 1)
                ans[currIndex++] = i;
        }

        return ans;

        /* Approach 3
        int m = mat.size();
        int n = mat[0].size();

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < m; i++)
        {
            int sCount = binarySearch(mat[i]); // T.C: O(log n)
            pq.push({sCount, i});              //
            if (pq.size() > k)                 // T.C: O(log k)
                pq.pop();                      //
        }                                      // T.C : (m * log (n * k))

        vector<int> ans(k, 0);
        while (pq.size())
        {
            ans[k - 1] = pq.top().second;
            pq.pop();
            k--;
        } // T.C : O(k log k)
        return ans;
        */

        /* Approach 2
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> sVec;

        for (int i = 0; i < m; i++)
        {
            int rowStrength = binarySearch(mat[i]); // T.C: O(log n)
            sVec.push_back({rowStrength, i});
        } // T.C : O(m * log(n))

        sort(sVec.begin(), sVec.end()); // T.C : O(m log m)

        vector<int> ans;
        for (auto x : sVec)
        {
            if (k == 0)
                break;
            ans.push_back(x.second);
            k--;
        } // T.C : O(k)
        return ans;
        */

        /* Approach 1
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> sVec;

        for (int i = 0; i < m; i++)
        {
            int rowStrength = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j])
                    rowStrength++;
            } // T.C: O(n)
            sVec.push_back({rowStrength, i});
        } // T.C: O(m * n)

        sort(sVec.begin(), sVec.end()); // T.C: O(mlogm)

        vector<int> ans;
        for (auto x : sVec)
        {
            if (k == 0)
                break;
            ans.push_back(x.second);
            k--;
        } // T.C : O(k)

        return ans;
        */
    }
};
// @lc code=end
