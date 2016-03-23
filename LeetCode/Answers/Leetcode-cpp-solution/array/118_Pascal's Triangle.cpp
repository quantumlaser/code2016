/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri;
        for(int i=0; i<numRows; ++i) {
            vector<int> ivec(i+1, 1);
            for(int j=1; j<i; ++j) 
                ivec[j] = tri[i-1][j-1] + tri[i-1][j];
            tri.push_back(ivec);
        }
        return tri;
    }
};