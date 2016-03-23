/*
Minimum Path SumMar 29 '124242 / 9379

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > s(m+1, vector<int>(n+1, INT_MAX));
        s[m-1][n] = 0;
        for(int i=m-1; i>=0; --i) 
            for(int j=n-1; j>=0; --j) {
                s[i][j] = grid[i][j] + min(s[i+1][j], s[i][j+1]);    
            }
        return s[0][0];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n; ++j)
                dp[j+1] = min(dp[j], dp[j+1]) + grid[i][j];
        return dp[n];
    }
};