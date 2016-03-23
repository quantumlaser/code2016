/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
*/
class Solution {
private:
    vector<vector<int> > rst;
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        rst.clear();
       // sort(num.begin(), num.end());不可通过排序，然后检验相邻元素是否相同的办法，因为每次进入dfs，顺序都乱了，相同元素不一定相邻
        dfs(num, 0);
        return rst;
    }
    
    void dfs(vector<int> &num, int i) {
        if(i == num.size()-1) {
            rst.push_back(num);
            return;
        }
        bool flag[19] = {false};
        for(int k = i; k != num.size(); ++k) {
            if(flag[num[k] + 9]) continue;
            flag[num[k] + 9] = true;
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