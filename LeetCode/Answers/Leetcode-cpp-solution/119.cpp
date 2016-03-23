/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/
//Submission Result: Time Limit Exceeded
class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ivec(1, 1);
            if(rowIndex<1) return ivec;
            for(int i=1; i<=rowIndex; ++i) {
                vector<int> tmp(i+1, 1);
                for(int j=1; j<i; ++j) 
                    tmp[j] = ivec[j-1] + ivec[j];
                ivec.assign(tmp.begin(), tmp.end());
            }
            return ivec;
        }
};


class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ivec(1, 1);
            if(rowIndex<1) return ivec;
            for(int i=1; i<=rowIndex; ++i) {
                int tmp2 = 1, tmp1;
                for(int j=1; j<i; ++j) {
                    tmp1 = tmp2;
                    tmp2 = ivec[j];
                    ivec[j] = tmp1+tmp2;
                }
                ivec.push_back(1);
            }
            return ivec;
        }
};
