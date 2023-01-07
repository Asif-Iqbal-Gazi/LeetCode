/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
class Solution
{
private:
    static bool comparator(string l1, string l2)
    {
        // Extract identifier & log content
        int p1 = l1.find(' ');
        string id1 = l1.substr(0, p1);
        string content1 = l1.substr(p1 + 1, l1.size());
        int p2 = l2.find(' ');
        string id2 = l2.substr(0, p2);
        string content2 = l2.substr(p2 + 1, l2.size());

        // Letter logs come before digit logs
        if (!isdigit(content1[0]) && isdigit(content2[0]))
            return true;
        else if (!isdigit(content1[0]) && !isdigit(content2[0]))
        {
            if (content1.compare(content2) == 0)
                return id1 < id2;
            else
                return content1 < content2;
        }
        else
            return false;
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        /* Approach:
            1. Use stable_sort with custom comparator
        */

        // Approach 1
        stable_sort(logs.begin(), logs.end(), comparator);
        return logs;
    }
};
// @lc code=end
