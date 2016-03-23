/*
Length of Last WordMar 27 '124669 / 11260

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int lastb = -1, lastc = -1;
            bool flag = 0;
            for(int i=0; s[i]!='\0'; ++i) {
                if(s[i]==' ') flag = 0;
                else {
                    if(flag==0) lastb = i-1;
                    flag = 1;
                    lastc = i;
                }
            }
            return (lastc-lastb);
        }
};

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int cnt = 0;
            while(*s) {
                if(*(s++) != ' ') cnt++;
                else if(*s && *s != ' ') cnt = 0;
            }
            return cnt;
        }
};
class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int cnt = 0;
            while(*s) {
                if(*(s++) != ' ') cnt++;
                else if(*s && *s != ' ') cnt = 0;
            }
            return cnt;
        }
};
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt=0, l=0;
        for(int i=0; s[i]!='\0'; ++i)
            if(s[i] == ' ') cnt = 0;
            else l = ++cnt;
        return l;
    }
};