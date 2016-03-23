/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
//Submission Result: Memory Limit Exceeded
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), lmax = 0;
        string rst;
        bool **palin = new bool*[n];
        for(int i=0; i<n; ++i) {
            palin[i] = new bool[n];
            fill_n(palin[i], n, false);
        }
        for(int i=0; i<n; ++i) 
            for(int j=0; j<=i; ++j)
                if(s[i]==s[j] && (i-j<2 || palin[j+1][i-1])) {
                    palin[j][i] = true;
                    if(i-j+1 > lmax) {
                        lmax = i-j+1;
                        rst = s.substr(j, i+1);
                    }
                }
        for(int i=0; i<n; ++i) 
            delete palin[i];
        delete []palin;
        return rst;
    }
};

class Solution {
public:
    string expandAroundCenter(string s, int l, int r) {
        while(l>=0 && r<s.size() && s[l]==s[r]) l--, r++;
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(!n) return "";
        string longest = s.substr(0, 1);
        for(int i=0; i<n-1; ++i) {
            string tmp = expandAroundCenter(s, i, i);
            if(tmp.size() > longest.size()) 
                longest = tmp;
            tmp = expandAroundCenter(s, i, i+1);
            if(tmp.size() > longest.size()) 
                longest = tmp;
        }
        return longest;
    }
};