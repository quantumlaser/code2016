/*
Climbing StairsApr 3 '126879 / 13083

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> r(n);
        r[0] = 1;
        r[1] = 2;
        for(int i = 2; i<n; ++i) 
            r[i] = r[i-1] + r[i-2];
        return r[n-1];
    }
};
