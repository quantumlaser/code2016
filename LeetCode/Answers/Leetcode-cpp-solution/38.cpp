/*
Count and SayMar 6 '121648 / 4460

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
    public:
        string countAndSay(int n) {
            string s = "1";
            while(--n) {
                ostringstream ss; 
                int cnt = 1;
                for(int i=1; i!=s.size(); ++i) {
                    if(s[i-1]==s[i]) cnt++;
                    else {ss<<cnt<<s[i-1];cnt=1;}
                }
                ss<<cnt<<s.back();
                s = ss.str();
            }
            return s;
        }
};
