/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > rst;
        vector<int> ivec;
        sort(num.begin(), num.end());
        dfs(rst, ivec, num, target, 0);
        return rst;
    }
    void dfs(vector<vector<int> > &rst, vector<int> &ivec, vector<int> &num, int target, int idx) {
        if(!target) {
            rst.push_back(ivec);
            return;
        }
        for(int i=idx; i<num.size(); ++i) {
            if(i>idx && num[i]==num[i-1]) continue;
            if(num[i]>target) break;
            ivec.push_back(num[i]);
            dfs(rst, ivec, num, target-num[i], i+1);
            ivec.pop_back();
        }
    }
};