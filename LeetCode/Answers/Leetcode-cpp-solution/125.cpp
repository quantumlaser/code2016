/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/
class Solution {
    public:
        bool isPalindrome(string s) {
            if(!s.size()) return true;
            int i=0, j=s.size()-1;
            while(!isalpha(s[i]) &&!isdigit(s[i]) && i<=j) i++;
            while(!isalpha(s[j]) &&!isdigit(s[j]) && j>=i) j--;
            if(i>=j) return true;
            if(tolower(s[i])!=tolower(s[j])) return false;
            return isPalindrome(s.substr(i+1, j-i-1));
        }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j) {
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};