/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
string tables[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rst(1);
        for(int i=0; i<digits.size(); ++i) {
            int n = rst.size();
            string word = tables[digits[i]-'0'];
            for(int j=0; j<word.size(); ++j)
            for(int k=0; k<n; ++k) {
                rst.push_back(rst[k]);
                rst.back().push_back(word[j]);
            }
            rst.erase(rst.begin(), rst.begin()+n);
        }
        return rst;
    }
};

string tables[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        dfs(rst, digits, "", 0);
        return rst;
    }
    void dfs(vector<string> &rst, string &digits, string str, int idx) {
        if(idx == digits.size()) {
            rst.push_back(str);
            return;
        }
        string word = tables[digits[idx]-'0'];
        for(int i=0; i < word.size(); ++i)
            dfs(rst, digits, str + word[i], idx+1);
    }
};

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> rst;
            string s;
            dfs(rst, s, digits, 0);
            return rst;
        }

        void dfs(vector<string> &svec, string &s, string &digits, int n) {
            if(n == digits.size()) {
                svec.push_back(s);
                return;
            }
            string keys = tables[digits[n]-'0'];
            for(int i=0; i!=keys.size(); ++i) {
                s.push_back(keys[i]);
                dfs(svec, s, digits, n+1);
                s.pop_back();
            }
        }
};
