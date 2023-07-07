/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
private:
    int primeCountLessThanNum(int n)
    {
        int count = 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i < n; i++)
        {
            if (!primes[i])
                continue;
            for (int p = i * i; p < n; p += i)
                primes[p] = false;
        }

        for (int i = 2; i < n; i++)
        {
            if (primes[i])
                count++;
        }

        return count;
    }

public:
    int countPrimes(int n)
    {
        /* Approach:
            1. Prime Sieve -- T.C: O(n * log log n), S.C: O(1)
        */

        if (n <= 2)
            return 0;
        return primeCountLessThanNum(n);
    }
};
// @lc code=end
