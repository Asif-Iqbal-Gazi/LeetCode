/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        Approach:
        Use a map
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            if(map.find(target-nums[i])!=map.end()){
                res.emplace_back(map.find(target-nums[i])->second);
                res.emplace_back(i);
                return res;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return res;
    }
};
// @lc code=end

