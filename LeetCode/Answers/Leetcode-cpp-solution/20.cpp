/**
Valid ParenthesesJan 30 '12566 / 1448

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
    public:
        bool isValid(string s) {
            stack<char> cstk;
            for(string::size_type i = 0; i!=s.size(); ++i) {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[') cstk.push(s[i]);
                else if(cstk.empty()) return false;
                else if(s[i]==')'&&cstk.top()=='(' || s[i]=='}'&&cstk.top()=='{' || (s[i]==']'&&cstk.top()=='[')) cstk.pop();
                else return false;
            }
            return cstk.empty() ? true : false;
        }
};

class Solution {
    public:
        bool isValid(string s) {
            map<char, char> cmap;
            cmap.insert(make_pair('(',')'));
            cmap.insert(make_pair('{','}'));
            cmap.insert(make_pair('[',']'));
            stack<char> cstk;
            for(string::size_type i = 0; i!=s.size(); ++i) {
                if(!cstk.empty() && cmap[cstk.top()]==s[i]) cstk.pop();
                else cstk.push(s[i]);
            }
            return cstk.empty() ? true : false;
        }
};
