/*
    2791. Count Paths That Can Form a Palindrome in a Tree
    https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/
*/

class Solution
{
private:
    bool doDFS(int p, int u, int v, vector<pair<int, char>> adj[], vector<int> &pathCharMap)
    {
        // Check if we have reached the destination node (v)
        if (u == v)
            return true;

        // Iterate over all the children of the current node (u)
        for (auto [child, pathChar] : adj[u])
        {
            if (child == p)
                continue; // Skip the parent node
            // Add the path char to the pathCharMap
            pathCharMap[pathChar - 'a']++;
            if (doDFS(u, child, v, adj, pathCharMap))
                return true; // Path found no need to continue
            // Remove the path char from the pathCharMap
            pathCharMap[pathChar - 'a']--;
        }

        return false;
    }

public:
    long long countPalindromePaths(vector<int> &parent, string s)
    {
        /* Approach:
            1. Think from first principles -- T.C: O(N^2 * (N * C))
                -- Iterate over all pairs (u, v) of nodes in the tree
                -- Check if the path from u to v forms a palindrome
        */

        // Approach 1
        long long ans = 0;
        int n = parent.size();
        // Build the adjacency list (Format: parent -> {children, pathChar})
        vector<pair<int, char>> adjList[n];
        for (int i = 1; i < n; i++)
        {
            adjList[parent[i]].push_back({i, s[i]});
            adjList[i].push_back({parent[i], s[i]});
        }

        vector<int> pathCharMap(26, 0);
        doDFS(-1, 2, 3, adjList, pathCharMap); // T.C: O(N)

        for (int u = 0; u < n - 1; u++) // T.C: O(N^2 * (N * C)
        {
            for (int v = u + 1; v < n; v++) // T.C: O(N * (N + C))
            {
                // Iterating over all pairs of nodes
                // Find the path from u to v using DFS (This will give us the path charMap)
                vector<int> pathCharMap(26, 0);
                doDFS(-1, u, v, adjList, pathCharMap); // T.C: O(N)
                // Check if the path forms a palindrome
                int oddCount = 0;
                bool isValid = false;
                for (int i = 0; i < 26; i++) // T.C: O(C)
                {
                    if (pathCharMap[i])
                    {
                        isValid = true;
                        oddCount += pathCharMap[i] % 2;
                    }
                }
                // for valid palindrome, there can be at most 1 odd count
                if (isValid && oddCount <= 1)
                {
                    cout << '(' << u << " , " << v << ")\n";
                    ans++;
                }
            }
        }

        return ans;
    }
};