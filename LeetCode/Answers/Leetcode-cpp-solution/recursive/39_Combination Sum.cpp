/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 
*/
class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > rst;
            vector<int> ivec;
            sort(candidates.begin(), candidates.end());
            dfs(rst, candidates, ivec, target, 0);
            return rst;
        }
        void dfs(vector<vector<int> > &rst, vector<int> &c, vector<int> &ivec, int target, int n) {
            if(target==0) {
                rst.push_back(ivec);
                return;
            }
            for(int i=n; i<c.size(); ++i) {
                if(i>0 && c[i]==c[i-i]) continue;
                if(c[i] > target) break;
                ivec.push_back(c[i]);
                dfs(rst, c, ivec, target-c[i], i);
                ivec.pop_back();
            }
        }
};
