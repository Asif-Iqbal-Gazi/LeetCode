int maxProfit(int *prices, int pricesSize) {
    /*
     * Approach:
     * 1. One Pass (Greedy) -- T.C: O(N), S.C: O(1)
     *      - Track minimum price so far and update max profit.
     * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
     *      - Try every pair (i, j) where j > i.
     */

    // Approach 1 -- One Pass (Greedy)
    if (pricesSize <= 1)
        return 0;

    int minPrice  = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }

    return maxProfit;

    /* Approach 2 -- Brute Force
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] - prices[i] > maxProfit)
                maxProfit = prices[j] - prices[i];
        }
    }
    return maxProfit;
    */
}
