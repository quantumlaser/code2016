/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
class Solution {
    public:
        int uniquePaths(int m, int n) {
            return backtracking(1, 1, m, n);
        }

        int backtracking(int r, int c, int m, int n) {
            if(r==m && c==n) return 1;
            if(r>m || c>n) return 0;
            return backtracking(r+1, c, m, n) + backtracking(r, c+1, m, n);
        }
};


class Solution {
    public:
        int uniquePaths(int m, int n) {
            int **mem = new int*[m+1];
            for(int i=0; i<=m; ++i) {
                mem[i] = new int[n+1];
                for(int j=0; j<=n; ++j)
                    mem[i][j] = -1;
            }
            return backtracking(0, 0, m-1, n-1, mem);
        }

        int backtracking(int r, int c, int m, int n, int **mem) {
            if(r==m && c==n) return 1;
            if(r>m || c>n) return 0;
            if(mem[r+1][c]==-1) mem[r+1][c]=backtracking(r+1, c, m, n, mem);
            if(mem[r][c+1]==-1) mem[r][c+1]=backtracking(r, c+1, m, n, mem);
            return mem[r+1][c] + mem[r][c+1];
        }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int **mem = new int*[m];
        for(int i = 0; i<m; ++i) {
            mem[i] = new int[n];
            for(int j=0; j<n-1; ++j) 
                mem[i][j] = (i==m-1)?1:-1;
            mem[i][n-1] = 1;
        }
        return backtrack(0, 0, m-1, n-1, mem);
    }
    int backtrack(int r, int c, int m, int n, int **mem) {
        if(r==m || c==n) return mem[r][c];
        if(mem[r+1][c]==-1) mem[r+1][c]=backtrack(r+1, c, m, n, mem);
        if(mem[r][c+1]==-1) mem[r][c+1]=backtrack(r, c+1, m, n, mem);
        return mem[r+1][c] + mem[r][c+1];
    }
};

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int> > mem(m+1, vector<int>(n+1, -1));
            return backtracking(0, 0, m-1, n-1, mem);
        }

        int backtracking(int r, int c, int m, int n, vector<vector<int> > &mem) {
            if(r==m && c==n) return 1;
            if(r>m || c>n) return 0;
            if(mem[r+1][c]==-1) mem[r+1][c]=backtracking(r+1, c, m, n, mem);
            if(mem[r][c+1]==-1) mem[r][c+1]=backtracking(r, c+1, m, n, mem);
            return mem[r+1][c] + mem[r][c+1];
        }
};

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int> > mem(m+1, vector<int>(n+1, 0));
            mem[m-1][n] = 1;
            for(int r=m-1; r>=0; --r)
                for(int c=n-1; c>=0; --c)
                    mem[r][c] =  mem[r+1][c] + mem[r][c+1];
            return mem[0][0];
        }
};

