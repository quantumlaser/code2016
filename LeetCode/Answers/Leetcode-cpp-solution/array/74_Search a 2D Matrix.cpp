/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m*n;
        while(l<h) {
            int mid = l + (h - l)/2;
            int x = matrix[mid/n][mid%n];
            if(x == target) return true;
            if(x < target) l = mid+1;
            else h = mid;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        for(int r=0, c=n-1; r<m && c>=0; ) {
            if(matrix[r][c] == target) 
                return true;
            matrix[r][c] < target ? r++ : c--;
        }
        return false;
    }
};