/**
Generate ParenthesesFeb 13 '12621 / 1568

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/
//work in vc, but cannot in leetcode oj
//problem solved, rst.clear() should be called first.
class Solution {
private:
	vector<string> rst;

public:
	vector<string> generateParenthesis(int n) {
		stack<char> stk;
		string s;
		dfs(stk, s, n, n);
		return rst;
	}

	void dfs(stack<char> &stk, string s, int i, int j) {
		if(!i && !j) {
			rst.push_back(s);
			return;
		}
		if(i) {
			s.push_back('(');
			stk.push('(');
			dfs(stk, s, i-1, j);
			//s.erase(s.size()-1);
			stk.pop();
		}
		if(!stk.empty() && j) {
			s.push_back(')');
			stk.pop();
			dfs(stk, s, i, j-1);
			//s.erase(s.size()-1);
			stk.push('(');
		}
	}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        generator(rst, "", 0, 0, n);
        return rst;
    }
    
    void generator(vector<string> &rst, string s, int l, int r, int n) {
        if(l == n) {
            rst.push_back(s.append(n-r, ')'));
            return;
        }
        generator(rst, s+'(', l+1, r, n);
        if(l>r) generator(rst, s+')', l, r+1, n);
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        generator(rst, "", n, n);
        return rst;
    }
    
    void generator(vector<string> &rst, string s, int l, int r) {
         if(l==0) {
             rst.push_back(s.append(r, ')'));
             return;
         }
         generator(rst, s+'(', l-1, r);
         if(r>l) generator(rst, s+')', l, r-1);
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > all;
        vector<string> cstr;
        cstr.push_back("");
        if(n == 0) return cstr;
        all.push_back(cstr);
        cstr.resize(0);
        cstr.push_back("()");
        if(n == 1) return cstr;
        all.push_back(cstr);
        int i = 2;
        cstr.resize(0);
        while( i < n+1 ) {
            for(int j = 0; j < i; j++) {
                for(int k = 0; k < all[j].size(); k++) {
                    for(int m = 0; m < all[i-j-1].size(); m++) {
                        cstr.push_back("("+all[j][k]+")"+all[i-j-1][m]);
                    }
                }
            }
            all.push_back(cstr);
            cstr.resize(0);
            i++;
        }
        return all[all.size()-1];
    }
};

