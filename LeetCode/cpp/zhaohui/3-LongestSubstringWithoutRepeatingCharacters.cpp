#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int sHash[128];
		for (int i = 0; i < 128; i++)
			sHash[i] = -1;
		int maxLen = 0,len = 0;
		int start = 0;
		for (int i = 0; i < s.size(); i++) {
			if (sHash[s[i]]>-1) {
				start = max(start, sHash[s[i]] + 1);
			}
			len = i - start + 1;
			if (maxLen < len)
				maxLen = len;
			sHash[s[i]] = i;
		}
		
		if (maxLen < len) 
			maxLen = len;
		return maxLen;
	}
};

int main(){
	Solution solution;
	cout << solution.lengthOfLongestSubstring("cdd") << endl;
	cout << solution.lengthOfLongestSubstring("abcdaed") << endl;
}