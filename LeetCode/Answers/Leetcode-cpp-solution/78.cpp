/*SubsetsApr 18 '126226 / 16269
Given a set of distinct integers, S, return all possible subsets.
Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/
class Solution {
private:
    vector<vector<int> > rst;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        rst.clear();
        sort(S.begin(), S.end());
        gen_subsets(S, S.size() - 1);
        return rst;
    }
    
    void gen_subsets(vector<int> &S, int idx) {
        if(idx == -1)
            rst.push_back(vector<int>());
        else {
            gen_subsets(S, idx - 1);
            vector<vector<int> > new_subsets;
            for(int i = 0; i != rst.size(); ++i) {
                vector<int> vtmp(rst[i]);
                vtmp.push_back(S[idx]);
                new_subsets.push_back(vtmp);
            }
            rst.insert(rst.end(), new_subsets.begin(), new_subsets.end());
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > rst;
        sort(S.begin(), S.end());
        subsets(S, S.size()-1, rst);
        return rst;
    }
    void subsets(vector<int> &S, int idx, vector<vector<int> > &rst) {
        if(idx<0) {
            rst.push_back(vector<int>());
            return;
        }
        subsets(S, idx-1, rst);
        int len = rst.size();
        for(int i=0; i<len; ++i) {
            vector<int> tmp(rst[i]);
            tmp.push_back(S[idx]);
            rst.push_back(tmp);
        }
    }      
};

class Solution { 
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > rst(1);
        for(int i=0; i != S.size(); ++i) {
            int j = rst.size();
            while(j--) {
                rst.push_back(rst[j]);
                rst.back().push_back(S[i]);
            }
        }
        return rst;
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > rst;
        vector<int> ivec;
        sort(S.begin(), S.end());
        dfs(rst, ivec, S, 0);
        return rst;
    }
    void dfs(vector<vector<int> > &rst, vector<int> &ivec, vector<int> &S, int idx) {
        rst.push_back(ivec);
        for(int i=idx; i<S.size(); ++i) {
            ivec.push_back(S[i]);
            dfs(rst, ivec, S, i+1);
            ivec.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > rst;
        sort(S.begin(), S.end());
        for(vector<int>::size_type i = 0; i != (1<<S.size()); ++i) {
            int j = i, idx = 0;
            vector<int> vtmp;
            while(j) {
                if(j & 1) 
                    vtmp.push_back(S[idx]);
                j >>= 1;
                idx++;
            }
            rst.push_back(vtmp);
        }
        return rst;
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > rst;
        sort(S.begin(), S.end());
        for(vector<int>::size_type i = 0; i != (1<<S.size()); ++i) {
            vector<int> vtmp;
            for(int j = 0; i>>j; ++j) {
                if(i & (1<<j)) 
                    vtmp.push_back(S[j]);
            }
            rst.push_back(vtmp);
        }
        return rst;
    }
};