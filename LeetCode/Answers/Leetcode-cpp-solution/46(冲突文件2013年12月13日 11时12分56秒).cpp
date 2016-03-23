class Solution {
private:
    vector<vector<int> > rst;
    
public:
    vector<vector<int> > permute(vector<int> &num) {
        rst.clear();
        dfs(num, 0);
        return rst;
    }
    
    void dfs(vector<int> &num, int i) {
        if(i == num.size()-1) {
            rst.push_back(num);
            return;
        }
        for(int k = i; k != num.size(); ++k) {
            xchg(num[k], num[i]);
            dfs(num, i + 1);
            xchg(num[k], num[i]);
        }
    }
    
    void xchg(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
};

#define exchange(a, b) {int t=b; b=a; a=t;}
class Solution {
private:
    vector<vector<int> > rst;
public:
    vector<vector<int> > permute(vector<int> &num) {
        rst.clear();
        sort(num.begin(), num.end());
        permutehelper(num, 0);
        return rst;
    }
    
    void permutehelper(vector<int> &num, int idx) {
        if(idx==num.size()-1) rst.push_back(num);
        else {
            for(int i=idx; i < num.size(); ++i) {
                if(i>idx && num[i]==num[i-1]) continue;
                exchange(num[i], num[idx]);
                permutehelper(num, idx+1);
                exchange(num[i], num[idx]);
            }
        }
    }
};