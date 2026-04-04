class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        /*
         * Approach:
         * 1. One Pass (Greedy) -- T.C: O(N), S.C: O(1)
         *      - Track minimum price so far and update max profit.
         * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
         *      - Try every pair (i, j) where j > i.
         */

        // Approach 1 -- One Pass (Greedy)
        if (prices.size() <= 1)
            return 0;

        int minPrice  = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }

        return maxProfit;

        /* Approach 2 -- Brute Force
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > maxProfit)
                    maxProfit = prices[j] - prices[i];
            }
        }
        return maxProfit;
        */
    }
};
