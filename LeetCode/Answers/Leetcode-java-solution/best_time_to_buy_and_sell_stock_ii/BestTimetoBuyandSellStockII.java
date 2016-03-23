package best_time_to_buy_and_sell_stock_ii;

public class BestTimetoBuyandSellStockII {

    public class Solution {
        public int maxProfit(int[] prices) {
            if (prices.length == 0) {
                return 0;
            }
            int profit = 0;
            for (int i = 1; i < prices.length; i++) {
                profit += Math.max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
    }

    public static class UnitTest {

    }
}
