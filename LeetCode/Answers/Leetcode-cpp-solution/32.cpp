/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/
//Use a stack to keep track of the positions of non-matching '('s. Also need to keep track of the position of the last ')'.
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxc = 0, lastr = -1;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '(') stk.push(i);
            else if(stk.empty()) lastr = i;
            else {
                stk.pop();
                int pos = stk.empty() ? lastr : stk.top();
                maxc = max(maxc, i-pos);
            }
        }
        return maxc;
    }
};



//Find from left to right by a forward iterator and right to left by a reverse iterator. Using template to avoid duplicate code since a reverse iterator overloads the operator +.
class Solution {
public:
    int longestValidParentheses(string s) {
        return max( helper(s.begin(), s.end(), '('), helper(s.rbegin(), s.rend(), ')') );
    }

    template<class Iter>
    int helper(Iter beg, Iter end, char ch) {
        int ret = 0;
        int left = 0, right = 0;
        for ( ; beg != end; ++beg) {
            if (*beg == ch) {
                ++left;
            }
            else if (left > right) {
                ++right;
                if (left == right) {
                    ret = max(ret, left<<1);
                }
            }
            else {
                left = right = 0;
            }
        }
        return ret;
    }
};
//dp[i] means the longest valid parentheses length from the start to s[i]
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int maxl = 0;
        vector<int> dp(len, 0);
        for(int i=1; i<len; ++i) {
            if(s[i]==')') {
                int j = i-1-dp[i-1];
                if(j>=0 && s[j]=='(') {
                    dp[i] = dp[i-1] + 2;
                    if(j-1>=0) dp[i] += dp[j-1];
                }
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};
