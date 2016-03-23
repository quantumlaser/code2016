/*
Unique Paths IIMar 29 '124246 / 10718

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int **mem = new int*[m+1];
        for(int i=0; i<m; ++i) {
            mem[i] = new int[n+1];
            for(int j=0; j<n; ++j) 
                mem[i][j] = obstacleGrid[i][j] ? 0 : -1;
            mem[i][n] = -1;
        }
        mem[m] = new int[n+1];
        for(int j=0; j<n+1; ++j) mem[m][j] = -1;
        if(!obstacleGrid[m-1][n-1]) mem[m-1][n-1] = 1;
        return backtrack(0, 0, m, n, mem);
    }
    
    int backtrack(int r, int c, int m, int n, int **mem) {
        if(r==m-1 && c==n-1) return mem[r][c];
        if(r>=m || c>=n) return 0;
        if(!mem[r][c]) return 0;
        if(mem[r+1][c] == -1) mem[r+1][c] = backtrack(r+1, c, m, n, mem);
        if(mem[r][c+1] == -1) mem[r][c+1] = backtrack(r, c+1, m, n, mem);
        return mem[r+1][c] + mem[r][c+1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]) return 0;
        for(int i=m-1; i>=0; --i) 
            for(int j=n-1; j>=0; --j) {
                if(obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if(i==m-1 && j==n-1) obstacleGrid[i][j] = 1;
                if(i!=m-1) obstacleGrid[i][j] += obstacleGrid[i+1][j];
                if(j!=n-1) obstacleGrid[i][j] += obstacleGrid[i][j+1];
            }
        return obstacleGrid[0][0];
    }
};