impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        /*
         * Approach:
         * 1. One Pass (Greedy) -- T.C: O(N), S.C: O(1)
         *      - Track minimum price so far and update max profit.
         * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
         *      - Try every pair (i, j) where j > i.
         */

        // Approach 1 -- One Pass (Greedy)
        if prices.len() <= 1 {
            return 0;
        }

        let mut min_price = prices[0];
        let mut max_profit = 0;

        for i in 1..prices.len() {
            if prices[i] < min_price {
                min_price = prices[i];
            } else if prices[i] - min_price > max_profit {
                max_profit = prices[i] - min_price;
            }
        }

        max_profit

        /* Approach 2 -- Brute Force
        let mut max_profit = 0;
        for i in 0..prices.len() {
            for j in i + 1..prices.len() {
                if prices[j] - prices[i] > max_profit {
                    max_profit = prices[j] - prices[i];
                }
            }
        }
        max_profit
        */
    }
}
