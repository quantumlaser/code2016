#include "TestSuite.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a < b;
}

bool isAnagram(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> rst;
		sort(strs.begin(), strs.end(), cmp);
		int cnt = 1;
		for(int i=1; i<strs.size(); ++i) {
			if(isAnagram(strs[i], strs[i-1])) cnt++;
			else if(cnt == 1) cnt = 0;
			else rst.insert(rst.end(),  &strs[i - cnt], &strs[i]);
		}
		return rst;
	}

};

int main(int argc, char *argv[]) {
//	testEightQueen();
	//testIO();
	getchar();
	return 1;	
}

