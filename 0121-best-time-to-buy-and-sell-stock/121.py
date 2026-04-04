class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Approach:
        1. One Pass (Greedy) -- T.C: O(N), S.C: O(1)
             - Track minimum price so far and update max profit.
        2. Brute Force -- T.C: O(N^2), S.C: O(1)
             - Try every pair (i, j) where j > i.
        """

        # Approach 1 -- One Pass (Greedy)
        if len(prices) <= 1:
            return 0

        min_price = prices[0]
        max_profit = 0

        for i in range(1, len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            elif prices[i] - min_price > max_profit:
                max_profit = prices[i] - min_price

        return max_profit

        # Approach 2 -- Brute Force
        # max_profit = 0
        # for i in range(len(prices)):
        #     for j in range(i + 1, len(prices)):
        #         if prices[j] - prices[i] > max_profit:
        #             max_profit = prices[j] - prices[i]
        # return max_profit
