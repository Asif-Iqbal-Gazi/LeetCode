/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        /* Approach:
            1. Bruteforce + Unordered_Set -- T.C: O(N^3), S.C: O(N) -- Gets TLE
            2. Optimizated Approach 1 -- T.C: O(N^3), S.C: O(N) -- Gets TLE
            3. Sorting + Two Sum -- T.C: O(N^2), S.C: O(1)
        */

        // Approach 3 -- Optimal Solution
        int n = nums.size();
        vector<vector<int>> ans;
        // Sorting
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // To avoid duplication
            // Two Sum Using two pointers
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int threeSum = nums[i] + nums[l] + nums[r];
                if (threeSum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++; // To avoid duplication
                    while (l < r && nums[r] == nums[r - 1])
                        r--; // To avoid duplication
                    l++;
                    r--;
                }
                else if (threeSum < 0)
                    l++;
                else
                    r--;
            }
        }
        return ans;

        /* Approach 2
        int n = nums.size();
        unordered_set<string> s; // To avoid duplication
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        // Sort for using as unique key
                        sort(temp.begin(), temp.end());
                        string key = "";
                        for(auto x : temp){
                            key += to_string(x);
                        }

                        if( s.find(key) == s.end() )
                            ans.push_back({nums[i],nums[j],nums[k]});
                        s.insert(key);
                    }
                }
            }
        }
        return ans;
        */

        /* Approach 1
        int n = nums.size();
        unordered_set<string> s; // To avoid duplication
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        string i_s = to_string(nums[i]);
                        string j_s = to_string(nums[j]);
                        string k_s = to_string(nums[k]);

                        if( s.find(i_s+j_s+k_s) == s.end() ||
                            s.find(i_s+k_s+j_s) == s.end() ||
                            s.find(k_s+j_s+i_s) == s.end() ||
                            s.find(k_s+i_s+j_s) == s.end() ||
                            s.find(j_s+i_s+k_s) == s.end() ||
                            s.find(j_s+k_s+i_s) == s.end() ){
                            ans.push_back({nums[i],nums[j],nums[k]});
                        }
                        s.insert(i_s+j_s+k_s);
                        s.insert(i_s+k_s+j_s);
                        s.insert(k_s+j_s+i_s);
                        s.insert(k_s+i_s+j_s);
                        s.insert(j_s+i_s+k_s);
                        s.insert(j_s+k_s+i_s);
                    }
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
