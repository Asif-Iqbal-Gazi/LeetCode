/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RandomizedSet
{
public:
    /* Approach:
    1. Unordered_map + Vector -- TC: O(1) for insert, remove, getRandom
    */
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
            // Value already present, return false
            return false;

        // Value not present, push it to the back of vector
        // Always last element
        nums.push_back(val);
        map[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
            // Value not present, return false
            return false;
        // For TC: O(1), check if it is the last element simply pop_back()
        // Else, swap last with val and pop_back()
        int last = nums.back(); // Last element
        map[last] = map[val];   // both value and last element points to "val" index in vactor
        nums[map[val]] = last;  // Copy the last element to the index val is pointing
        nums.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
