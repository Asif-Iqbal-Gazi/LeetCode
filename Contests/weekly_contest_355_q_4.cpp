/*
    2791. Count Paths That Can Form a Palindrome in a Tree
    https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/
*/

class Solution {
   private:
    // Approach 5
    unordered_map<int, int> pathMapCount;
    vector<vector<pair<int, char>>> adjList;
    void doDFS(int u, int charMap) {
        pathMapCount[charMap]++;
        // Iterate over all the children of current node (u)
        for (auto [uChild, eChar] : adjList[u]) {
            charMap ^= (1 << (eChar - 'a'));
            doDFS(uChild, charMap);
            charMap ^= (1 << (eChar - 'a'));
        }
    }
    /* Approach 4
    vector<int> pathMap;
    vector<vector<pair<int, char>>> adjList;

    void doDFS(int u, int charMap)
    {
        pathMap[u] = charMap;

        // Iterate over all the children of the current node (u)
        for (auto [uChild, eChar] : adjList[u])
        {
            charMap ^= (1 << (eChar - 'a'));
            doDFS(uChild, charMap);
            charMap ^= (1 << (eChar - 'a'));
        }
    }
    */
    /* Approach 3
    vector<bool> seedMap;
    void doDFS(int p, int u, vector<pair<int, char>> adjList[], vector<bool> pathMap[])
    {
        pathMap[u] = seedMap;
        // Iterate over all the children of the current node (u)
        for (auto [child, pathChar] : adjList[u])
        {
            if (child == p)
                continue; // Skip the parent node
            seedMap[pathChar - 'a'] = !seedMap[pathChar - 'a'];
            doDFS(u, child, adjList, pathMap);
            seedMap[pathChar - 'a'] = !seedMap[pathChar - 'a'];
        }
    }
    *
    /* Approach 2
    vector<int> seedMap;
    void doDFS(int p, int u, vector<pair<int, char>> adjList[], vector<int> pathCharMap[])
    {
        pathCharMap[u] = seedMap;
        // Iterate over all the children of the current node (u)
        for (auto [child, pathChar] : adjList[u])
        {
            if (child == p)
                continue; // Skip the parent node
            seedMap[pathChar - 'a']++;
            doDFS(u, child, adjList, pathCharMap);
            seedMap[pathChar - 'a']--;
        }
    }
    *
    /* Approach 1
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
    */

   public:
    long long countPalindromePaths(vector<int> &parent, string s) {
        /* Approach:
            1. Think from first principles -- T.C: O(N^2 * (N * C))
                -- Iterate over all pairs (u, v) of nodes in the tree
                -- Check if the path from u to v forms a palindrome
            2. Remove the 2nd loop to iterate over all 'v' nodes
                -- The idea is to precompute the pathCharMap for each node from the root (using DFS)
                -- Then for each pair (u, v) we can compute the pathCharMap for (u -> v) in O(C) time
                   To do so we can find the LCA of u and v and then subtract the pathCharMap of LCA from the pathCharMap of u and v
                   Note: Since we are interested in finding the oddCount we can simply add the pathCharMap of u and v (No need to calculate LCA)
                -- Final T.C: O(N^2 * C), S.C: O(N * C)
            3. Same as above but using bollean array -- T.C: O(N^2 * C), S.C: O(N * C)
            4. Same as above but using bitmask -- T.C: O(N^2 * C), S.C: O(N * C)
            5. We can keep a map for pathMap and eliminate the second loop -- T.C: O(N * C), S.C: O(N)
        */

        // Approach 5
        long long ans = 0;
        int n = parent.size();
        // Initialize the private variables
        pathMapCount.clear();
        adjList.assign(n, {});
        // Build the adjacency list (Format: parent -> {children, pathChar})
        for (int i = 1; i < n; i++)
            adjList[parent[i]].push_back({i, s[i]});

        // Precompute the pathMap for each node from the root (using DFS) and fill the pathMapCount
        doDFS(0, 0);  // T.C: O(N)

        // Iterate over the pathMapCount directly
        long long pathMap = 0, count = 0;
        for (auto x : pathMapCount) {
            pathMap = x.first;
            count = x.second;
            // Even Case
            ans += count * (count - 1);
            // Odd Case
            for (int i = 0; i < 26; i++) {
                int other = pathMap ^ (1 << i);
                if (pathMapCount.count(other) == 0)
                    continue;
                ans += count * pathMapCount[other];
            }
        }

        return ans / 2;

        /* Approach 4
        long long ans = 0;
        int n = parent.size();
        // Initialize the private members
        adjList.assign(n, {});
        pathMap.assign(n, 0);
        // Build the adjacency list (Format: parent -> {children, pathChar})
        for (int i = 1; i < n; i++)
        {
            adjList[parent[i]].push_back({i, s[i]});
            // adjList[i].push_back({parent[i], s[i]}); Not Required
        }
        // Precompute the pathMap for each node from the root (using DFS)
        doDFS(0, 0); // T.C: O(N)

        for (int u = 0; u < n - 1; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                // Add the pathCharMap of u and v and check if the path forms a palindrome
                int oddCount = 0;
                for (int i = 0; i < 26; i++)
                {
                    if (pathMap[u][i] ^ pathMap[v][i])
                        oddCount++;
                }
                // for valid palindrome, there can be at most 1 odd count
                if (oddCount <= 1)
                    ans++;
            }
        }
        return ans;
        */

        /* Approach 3
        long long ans = 0;
        int n = parent.size();
        // Build the adjacency list (Format: parent -> {children, pathChar})
        vector<pair<int, char>> adjList[n];
        for (int i = 1; i < n; i++)
        {
            adjList[parent[i]].push_back({i, s[i]});
            adjList[i].push_back({parent[i], s[i]});
        }
        // Precompute the pathMap for each node from the root (using DFS)
        seedMap.assign(26, false);
        vector<bool> pathMap[n];
        doDFS(-1, 0, adjList, pathMap); // T.C: O(N * C)

        for (int u = 0; u < n - 1; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                // Add the pathCharMap of u and v and check if the path forms a palindrome
                int oddCount = 0;
                for (int i = 0; i < 26; i++)
                {
                    if (pathMap[u][i] ^ pathMap[v][i])
                        oddCount++;
                }
                // for valid palindrome, there can be at most 1 odd count
                if (oddCount <= 1)
                    ans++;
            }
        }
        return ans;
        *

        /* Approach 2
        long long ans = 0;
        int n = parent.size();
        // Build the adjacency list (Format: parent -> {children, pathChar})
        vector<pair<int, char>> adjList[n];
        for (int i = 1; i < n; i++)
        {
            adjList[parent[i]].push_back({i, s[i]});
            adjList[i].push_back({parent[i], s[i]});
        }
        // Precompute the pathCharMap for each node from the root (using DFS)
        seedMap.assign(26, 0);
        vector<int> pathCharMap[n];
        doDFS(-1, 0, adjList, pathCharMap); // T.C: O(N * C)

        for (int u = 0; u < n - 1; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                // Add the pathCharMap of u and v and check if the path forms a palindrome
                int oddCount = 0;
                int currCharFreq = 0;
                bool isValid = false;
                for (int i = 0; i < 26; i++)
                {
                    currCharFreq = pathCharMap[u][i] + pathCharMap[v][i];
                    oddCount += currCharFreq % 2;
                    if (currCharFreq)
                        isValid = true;
                }
                // for valid palindrome, there can be at most 1 odd count
                if (isValid && oddCount <= 1)
                    ans++;
            }
        }
        return ans;
        *

        /* Approach 1
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
        */
    }
};