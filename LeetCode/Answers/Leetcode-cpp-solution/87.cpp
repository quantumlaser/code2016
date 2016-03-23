/*
Scramble StringApr 30 '124644 / 14931

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
#include <iostream>
#include <string>
using namespace std;

int cnt=0;
bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    if(s1==s2) return true;

    cout << "time " << cnt++ << ": " << s1 << ends << s2 << endl;
    for(int i=1; i<s1.size(); ++i) {
        if(isScramble(s1.substr(0,i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s1.size()-i)))
            return true;
        if(isScramble(s1.substr(0,i), s2.substr(s2.size()-i, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(0,s1.size()-i)))
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    while(cin >> s1 >> s2) {
              cout << isScramble(s1, s2) <<endl;
    }
    return 0;
}




//3 dimensional dynamic programming: f(i, j, n) = || ((f(i, j, m) && f(i + m, j + m, n - m)) || f(i, j + n - m, m) && f(i + m, j, n - m)) for 1 < m < n where f(i, j, n) is true iff substring starts at s1[i] and substring starts at s2[j] both with length n are scrambled

boolean isScramble(String s1, String s2) {
    if(s1.equals(s2))
        return true;
    boolean[][][] scrambled = new boolean[s1.length()][s2.length()][s1.length() + 1];
    for(int i = 0; i < s1.length(); i++)
        for(int j = 0; j < s2.length(); j++){
            scrambled[i][j][0] = true; 
            scrambled[i][j][1] = s1.charAt(i) == s2.charAt(j);
        }

    for(int i = s1.length() - 1; i >= 0 ; i--)
        for(int j = s2.length() - 1; j >= 0; j--)
            for(int n = 2; n <= Math.min(s1.length() - i, s2.length() - j); n ++)
                for(int m = 1; m < n; m++){
                    scrambled[i][j][n] |= scrambled[i][j][m] && scrambled[i + m][j + m][n - m] ||
                            scrambled[i][j + n - m][m] && scrambled[i + m][j][n - m];
                    if(scrambled[i][j][n])  break;
                }
    return scrambled[0][0][s1.length()]; 
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return false;

        bool f[n][n][n];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                f[i][j][0] = s1[i] == s2[j];

        for (int l=1; l<n; l++) {
            for (int i=0; i+l<n; i++) {
                for (int j=0; j+l<n; j++) {
                    f[i][j][l] = false;
                    for (int k=0; k<l; k++) {
                        if (f[i][j][k] && f[i+k+1][j+k+1][l-1-k]
                            || f[i][j+l-k][k] && f[i+k+1][j][l-1-k]) {
                            f[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[0][0][n-1];
    }
};