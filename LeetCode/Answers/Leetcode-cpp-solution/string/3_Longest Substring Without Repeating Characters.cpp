/**
Longest Substring Without Repeating CharactersMay 16 '11872 / 2812

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring 

without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with 

the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exist[26] = {false};
        int maxlen = 0, i, j;
        for(i=0, j=0; j!=s.size(); ++j) {
            if(exist[s[j]-'a']) {
                maxlen = max(maxlen, j-i);
                while(s[i++] != s[j]) exist[s[i-1]-'a'] = false;
            }
            else exist[s[j]-'a'] = true;
        }
        return max(maxlen, j-i);
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool dict[26] = {false};
        int maxl = 0;
        for(int i=0,j=-1; i<s.size(); ++i) {
            if(!dict[s[i]-'a']) {
                dict[s[i]-'a'] = true;
                maxl = max(maxl, i-j);
            }
            else while(s[++j]!=s[i]) dict[s[j]-'a'] = false;
        }
        return maxl;
    }
};