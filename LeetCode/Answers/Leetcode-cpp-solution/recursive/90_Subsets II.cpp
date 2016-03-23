/*
Subsets IIJun 25 '124769 / 13419

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > rst(1);
        int presize=0;
        for(int i=0; i!=S.size(); ++i) {
            int cursize=rst.size();
            int j=rst.size();
            while(j--) {
                if (i==0 || S[i]!=S[i-1] || j>=presize) {
                    rst.push_back(rst[j]);
                    rst.back().push_back(S[i]);
                }
            }
            presize = cursize;
        }
        return rst;
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > rst(1);
        sort(S.begin(), S.end());
        int lastLen = 0;
        for(int i=0; i<S.size(); ++i) {
            int curLen = rst.size();
            for(int j=curLen-1; j>=0; --j) {
                if(i==0 || S[i]!=S[i-1] || j>=lastLen) {
                    rst.push_back(rst[j]);
                    rst.back().push_back(S[i]);
                }
            }
            lastLen = curLen;
         }                    
         return rst;  
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > rst(1);
        sort(S.begin(), S.end());
        int lastlen = -1;
        for(int i=0; i<S.size(); ++i) {
            int curlen = rst.size();     //current size 
            int j = 0;                   //position of element which will be copied and inserted
            if(i>0 && S[i]==S[i-1]) j = lastlen;  //handle the duplicate situation, eg., 0 1 2 2 when i=3, we've got [],[1],[2],[12],then j should start from position 2
            for(; j<curlen; ++j) {
                rst.push_back(rst[j]);
                rst.back().push_back(S[i]);
            }
            lastlen = curlen;
        }
        return rst;
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > rst;
        vector<int> path;
        sort(S.begin(), S.end());
        sub(rst, path, S, 0);
        return rst;
    }
    void sub(vector<vector<int> > &rst, vector<int> &path, vector<int> &S, int idx) {
        rst.push_back(path);
        for(int i=idx; i<S.size(); ++i) {
            if(i>idx && S[i]==S[i-1]) continue;
            path.push_back(S[i]);
            sub(rst, path, S, i+1);
            path.pop_back();
        }
    }
};