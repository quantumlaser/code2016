/*
Best Time to Buy and Sell StockOct 30 '122818 / 6447

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int i = 0, j = 0, t = 0, max = 0;
            for(int k = 1; k<prices.size(); ++k) {
                if(prices[k] - prices[t] > max) i=t, j=k, max=prices[j]-prices[i];
                else if(prices[k] < prices[t]) t=k;
            }
            return max;
        }
};

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if(!prices.size()) return 0;
            int t = prices[0], m = 0;
            for(int k = 1; k<prices.size(); ++k) {
                t = min(prices[k], t);
                m = max(m, prices[k]-t);
            }
            return m;
        }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp = 0, k = 0;    //k is the index of current minumum element
        for(int i = 1; i<prices.size(); ++i) {
            if(prices[i] < prices[k]) k = i;  //update k
            maxp = max(maxp, prices[i]-prices[k]); //update maximum profit
        }
        return maxp;
    }
};