class Solution {
private:
    vector<vector<int> > rst;
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> tmp;
        rst.clear();
        combine_recur(tmp, n, k, 1);
        return rst;
    }
    
    void combine_recur(vector<int> tmp, int n, int k, int idx) {
        if(k==0) rst.push_back(tmp);
        for(int i=idx; i<=n; ++i) {
            tmp.push_back(i);
            combine_recur(tmp, n, k-1, i + 1);
            tmp.pop_back();
        }
    }
};