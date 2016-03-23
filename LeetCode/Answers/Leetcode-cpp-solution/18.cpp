/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/
class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > rst;
            if(num.size() < 4) return rst;
            sort(num.begin(), num.end());
            int n = num.size();
            for(int i=0; i<n-3; ++i) {
                if(i>0 && num[i]==num[i-1]) continue;
                for(int j=i+1; j<n-2; ++j) {
                    if(j>i+1 && num[j]==num[j-1]) continue;
                    int k = j+1, l = n-1;
                    while(k<l) {
                        int s = num[i] + num[j] + num[k] + num[l];
                        if(s==target) {
                            if(k>j+1 && num[k]==num[k-1]) {k++, l--;continue;}
                            vector<int> ivec(4);
                            ivec[0]=num[i], ivec[1]=num[j], ivec[2]=num[k++], ivec[3]=num[l--];
                            rst.push_back(ivec);
                        }
                        else s<target ? k++ : l--;
                    }
                }
            }
            return rst;
        }
};
