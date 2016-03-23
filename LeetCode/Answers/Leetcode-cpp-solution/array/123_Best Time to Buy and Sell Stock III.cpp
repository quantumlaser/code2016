/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*
First consider the case that when we are only allowed to make one transaction. we can handle this easily with DP. If we move forward, any new price we meet will only affect our history result by two ways:

    will it be so low that it beats our previous lowest price?
    will it be so high that we should instead sell on this time to gain a higher profit (than the history record)? Similarly, we can move backward with the highest price and profit in record. Either way would take O(n) time.

Now consider the two transaction case. Since there will be no overlaps, we are actually dividing the whole time into two intervals.

We want to maximize the profit in each of them so the same method above will apply here. We are actually trying to break the day at each time instance, by adding the potential max profit before and after it together. By recording history and future for each time point, we can again do this within O(n) time.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(!len) return 0;
        vector<int> profitLeft(len, 0);
        vector<int> profitRight(len, 0);
        int maxp = 0, low = prices[0], high = prices[len-1];
        for(int i=1; i<len; ++i) {
            if(prices[i] < low) low = prices[i];
            profitLeft[i] = max(profitLeft[i-1], prices[i]-low);
        }
        for(int i=len-2; i>=0; --i) {
            if(prices[i] > high) high = prices[i];
            profitRight[i] = max(profitRight[i+1], high-prices[i]);
            maxp = max(maxp, profitLeft[i]+profitRight[i]);
        }
        return maxp;
    }
};


/*
A new problem of completing at most m transactions can be efficiently solved by using the method below.

The profit of one transaction is price[i]-price[j] where i > j. We then can rewrite the expression to be: price[i]-price[i-1] + price[i-1]-price[i-2] + ... + price[j+1]-price[j]. If we construct an array of {diff[i]} = {price[i+1]-price[i]}, then the problem can be reduced to the maximum m segments sum problem on diff[], where m = 2 in this case. Then we can play the fancy dynamic programming to solve it.

Here is one solution of the maximum m segments sum problem. The running time is O(NM).

Let f[i][j] to be the maximum sum of j segments from the first i numbers, where the last element we choose is a[i]. We have two strategies to achieve it:

    Choosing the optimal j-1 segments from the first k numbers, and starting a new segment with a[i]:

    f[i][j] = f[k][j-1] + a[i], where j-1 <= k <= i-1.

However, f[k][j-1] is the subproblems that we've already solved. If we memorize the optimal j-1 segments, namely g[j-1] = max(f[k][j-1]), the state transition can be achieved in O(1):

    f[i][j] = g[j-1] + a[i]

    Appending a[i] to the last segment in the first i-1 numbers

    f[i][j] = f[i-1][j] + a[i].

Here is why we must choose a[i] in our strategies. If f[i-1][j] is not ends at a[i-1], then appending a[i] to f[i-1][j] will get j+1 segments, which violates the definition of f[i][j].
*/
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int f[3] = {0};
            int g[3] = {0};

            int n = prices.size() - 1;
            for (int i = 0; i < n; ++i) {
                int diff = prices[i+1] - prices[i];
                int m = min(i+1, 2);
                for (int j = m; j >= 1; --j) {
                    f[j] = max(f[j], g[j-1]) + diff;
                    g[j] = max(g[j], f[j]);
                }
            }
            return max(g[1], g[2]);
        }
    };

