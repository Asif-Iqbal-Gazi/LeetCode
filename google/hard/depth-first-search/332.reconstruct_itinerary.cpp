/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
   private:
    int totalTickets;
    bool doDFS(string src, vector<string> &itenary, unordered_map<string, map<string, int>> &adjList) {
        // Base Case
        if (totalTickets + 1 == itenary.size())
            return true;

        // For this src, check all of the des
        // As we have a map, everything will be lexicographically sorted.
        for (auto &[des, count] : adjList[src]) {
            if (count == 0) continue;          // We have already exhausted
            count--;                           // Utilised one ticket
            itenary.push_back(des);            // Push this destination in our itenary
            if (doDFS(des, itenary, adjList))  // Recursively call for this des
                return true;
            itenary.pop_back();  // Backtrack
            count++;             // Increment the ticket count back
        }

        return false;
    }

   public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        /* Approach:
            1. DFS with backtracking -- T.C: O(V + E), S.C: O(V + E)
                - Build the adjacency list
                - Do DFS with backtracking
                    - Base Case: If we have exhausted all the tickets, return true
                    - For this src, check all of the des
                        - If we have already exhausted this des, continue
                        - Else, decrement the count of this des
                        - Push this destination in our itenary
                        - Recursively call for this des
                        - If we get true, return true
                        - Else, backtrack
                        - Increment the ticket count back
                    - Return false
        */

        totalTickets = tickets.size();
        // Build the adjacency list
        unordered_map<string, map<string, int>> adjList;

        for (vector<string> t : tickets)  // T.C: O(E)
            adjList[t[0]][t[1]]++;

        string currAirport = "JFK";
        vector<string> currItenary = {currAirport};
        doDFS(currAirport, currItenary, adjList);  // T.C: O(V + E)
        return currItenary;
    }
};
// @lc code=end
