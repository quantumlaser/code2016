/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
*/
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		int len = s.length();
		if (len == 1)
			return s;
		string pStr = "";
		int maxLen = 1, maxStart = 0, tempLen;
		int left, right;
		for (int i = 0; i<2 * len - 1; i++) {
			if ((len - 1) - i / 2 <= maxLen / 2)
				break;
			left = (i / 2) * 2;
			right = ((i + 1) / 2) * 2;
			tempLen = 0;
			while (left >= 0 && right<2 * len - 1) {
				if (s[left / 2] != s[right/2]) {
					if (maxLen < tempLen) {
						maxLen = tempLen;
						maxStart = left + 2;
					}
					break;
				}
				else {
					tempLen = right / 2 - left / 2 + 1;
					left = left - 2;
					right = right + 2;
				}
			}
			if (maxLen < tempLen) {
				maxLen = tempLen;
				maxStart = left + 2;
			}
		}
		pStr = s.substr(maxStart / 2, maxLen);

		return pStr;
	}
};

int main() {
	string s = "aabacaca";
	Solution solution;
	cout << solution.longestPalindrome(s) << endl;
	cout << solution.longestPalindrome("a")<<endl;
	cout << solution.longestPalindrome("abbac") << endl;
	cout << solution.longestPalindrome("ababbac") << endl;
	return 0;
}

