/**
Longest Common PrefixJan 17 '12532 / 1577

Write a function to find the longest common prefix string amongst an array of strings. 
*/
class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.empty()) return "";

            int r = strs[0].size() - 1;
            for(vector<string>::size_type i = 1; i!=strs.size(); ++i) {
                for(string::size_type j = 0; j <= r; ++j) {
                    if(strs[i][j] != strs[0][j]) r = j-1;
                }
            }
            return strs[0].substr(0, r+1);

        }
};

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.empty()) return "";

            for(string::size_type i = 0; i!=strs[0].size(); ++i) {
                for(vector<string>::size_type j = 1; j!=strs.size(); ++j) {
                    if(strs[j].size()<=i || strs[j][i]!=strs[0][i])
                        return strs[0].substr(0, i);
                }
            }
            return strs[0];
        }
};
