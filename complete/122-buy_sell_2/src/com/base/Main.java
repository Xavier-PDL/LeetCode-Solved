package com.base;

/**
 * for each element consider buy option
 * loop through remaining elements
 * if price is higher, that is sellIndex
 * if price is lower, that is buyIndex
 * if price is neither higher/lower
 */

public class Main {
    public int maxProfit(int[] prices) {
        int buyIndex = -1;
        int sellIndex = -1;
        int gains = 0;
        for (int i = 0; i < prices.length; i++) {
            if(buyIndex < 0 || (prices[i] < prices[buyIndex] && sellIndex < 0)) {
                buyIndex = i;
            } else if (sellIndex < 0 || prices[i] > prices[sellIndex] ) {
                sellIndex = i;
            } else {
                // do sale
                gains += prices[sellIndex] - prices[buyIndex];
                buyIndex = i;
                sellIndex = -1;
            }
        }
        if(buyIndex >= 0 && sellIndex > 0)
            gains += prices[sellIndex] - prices[buyIndex];

        return gains;
    }

    public static void test(int[] prices, int expected){
        Main app = new Main();
        int res = app.maxProfit(prices);
        String str = " result = 2, expected = 2";
        System.out.println(res == expected ? 
                "[SUCCESS]" + str : "[FAILURE]" + str );
    }

    public static void main(String[] args) {
        Main app = new Main();
        int[] prices = {2,4,1};
        test(prices, 2);
        //int maxGains = app.maxProfit(prices);

        //System.out.println(maxGains);
    }
}
