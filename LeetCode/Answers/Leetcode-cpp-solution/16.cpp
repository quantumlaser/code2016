/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int rst = num[0] + num[1] + num[2];
            sort(num.begin(), num.end());
            for(int k = 0; k<num.size()-2; ++k) {
                if(k>0 && num[k]==num[k-1]) continue;
                int i=k+1, j=num.size()-1;
                while(i<j) {
                    int s = num[i] + num[j] + num[k];
                    if(abs(s-target) < abs(rst-target)) rst=s;
                    if(rst == target) return target;
                    s<target ? i++ : j--;
                }
            }
            return rst;
        }
};

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        if(len<3) return -1;
        sort(num.begin(), num.end());
        int res = accumulate(num.begin(), num.begin()+3, 0);
        for(int k=0; k<len-2; ++k) {
            if(k>0 && num[k-1]==num[k]) continue;
            int i=k+1, j=len-1;
            while(i<j) {
                if(i>k+1 && num[i]==num[i-1]) {i++;continue;}
                if(j<len-1 && num[j]==num[j+1]) {j--; continue;}
                int s=num[k]+num[i]+num[j];
                if(abs(s-target)<abs(res-target)) {
                    res = s;
                    if(res ==target) return res;
                }
                s<target ? i++ : j--;
            }
        }
        return res;
    }
};