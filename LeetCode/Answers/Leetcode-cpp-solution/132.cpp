/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
*/
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int *dp = new int[len];
        bool **palin = new bool*[len];
        for(int i=0; i<len; ++i) {
            dp[i] = i + 1;
            palin[i] = new bool[len];
            fill_n(palin[i], len, false);
        }
        for(int i = 1; i<len; ++i) 
            for(int j = i; j>=0; --j)
                if(s[j]==s[i] && (i-j<2 || palin[j+1][i-1])) {
                    palin[j][i] = true;
                    if(j==0) dp[i] = 1;
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
        return dp[len-1] - 1;
    }
};