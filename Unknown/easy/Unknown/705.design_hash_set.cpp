/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MyHashSet
{
    /* Approach:
    1. Using Simple Array of Size (10^6 + 1) -- TC: O(1) for given operation
    2. Using STL continer List & Hash
    */

    // Approach 1
public:
    MyHashSet()
    {
        hash.resize(1e6 + 1, false);
    }

    void add(int key)
    {
        hash[key] = true;
    }

    bool contains(int key)
    {
        return hash[key];
    }

    void remove(int key)
    {
        hash[key] = false;
    }

private:
    vector<int> hash;

    /* Approach 2
public:
    MyHashSet()
    {
        vec = vector<list<int>>(128);
    }

    inline int GetHash(int key)
    {
        int h = hash<int>{}(key);
        int hash_mod = h % vec.size();
        return hash_mod;
    }

    void add(int key)
    {
        int hash = GetHash(key);
        if (contains(key, hash))
            return;
        auto &l = vec[hash];
        l.push_back(key);
        return;
    }

    inline void remove(int key, int hash)
    {
        auto &l = vec[hash];
        auto it = l.begin();
        while (it != l.end())
        {
            if (*it != key)
            {
                ++it;
                continue;
            }
            l.erase(it);
            return;
        }
        return;
    }
    void remove(int key)
    {
        remove(key, GetHash(key));
        return;
    }

    // Returns true if this set contains the specified element
    inline bool contains(int key, int hash)
    {
        const auto &l = vec[hash];
        for (int n : l)
        {
            if (n == key)
                return true;
        }
        return false;
    }
    bool contains(int key)
    {
        return contains(key, GetHash(key));
    }

private:
    vector<list<int>> vec;
    */
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
