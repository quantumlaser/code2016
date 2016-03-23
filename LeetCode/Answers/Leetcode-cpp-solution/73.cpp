/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(!matrix[i][j]) {
                    rows[i] = true;
                    cols[j] = true;
                }
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(rows[i] || cols[j])
                    matrix[i][j] = 0;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(!m) return;
        int n = matrix[0].size();
        if(!n) return;
        bool b_row0 = false, b_col0 = false;  //use two flag to store the status of row 0 and col 0
        for(int i=0; i<m; ++i) {
            if(!matrix[i][0]) {
                b_col0 = true;
                break;
            }
        }
        for(int j=0; j<n; ++j) {
            if(!matrix[0][j]) {
                b_row0 = true;
                break;
            }
        }
        for(int i=1; i<m; ++i) {  //use the space in row 0 and col 0 to store the status of other positions
            for(int j=1; j<n; ++j) {
                if(!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;       
            }
        }
        for(int i=1; i<m; ++i) {  //set zeros using the flags in row 0 and col 0
            for(int j=1; j<n; ++j) {
                if(!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
            }
        }
        if(b_row0) 
            fill(matrix[0].begin(), matrix[0].end(), 0);
        if(b_col0) 
            for(int i=0; i<m; ++i)
                matrix[i][0] = 0;
    }
};