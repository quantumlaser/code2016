/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > rst(n, vector<int>(n));
        int num = 1;
        for(int l = 0; l<n/2; ++l) {
            for(int i=l; i<n-l-1; ++i) 
                rst[l][i] = num++;
            for(int i=l; i<n-l-1; ++i) 
                rst[i][n-l-1] = num++;
            for(int i=l; i<n-l-1; ++i) 
                rst[n-l-1][n-i-1] = num++;
            for(int i=l; i<n-l-1; ++i) 
                rst[n-i-1][l] = num++;
        }
        if(n & 0x01) rst[n/2][n/2] = num;
        return rst;
    }
};


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n,0) );
        int y=0, x=0;
        for (int i=0; i<n*n; ++i) {
            ans[y][x]=i+1;
            if (y>=n-1-x && y<x)
                y++;
            else if (x>n-1-y && x<=y)
                x--;
            else if (y>x+1 && y<=n-1-x)
                y--;
            else
                x++;
        }
        return ans;
    }
};

