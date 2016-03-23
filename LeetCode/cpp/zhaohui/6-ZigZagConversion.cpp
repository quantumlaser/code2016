#include<iostream>
#include<string>
using std::cout;
using std::string;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int  len = s.size();
		string sZig = "";
		int index = 0;
		//int i, n;
		for (int n = 0; (index = (2 * n )*(numRows - 1))<len; n++) {
			sZig = sZig + s[index];
		}
		for (int i = 1; i < numRows - 1; i++) {
			for (int n = 0; (index = 2 * n*(numRows - 1) - i) < len; n++) {
				if (index >= 0)
					sZig = sZig + s[index];
				if ((index = 2 * n*(numRows - 1) + i) < len)
					sZig = sZig + s[index];
			}
		}
		if (numRows - 1 > 0) {
			for (int n = 0; (index = (2 * n + 1)*(numRows - 1))<len; n++) {
				sZig = sZig + s[index];
			}
		}
		return sZig;
	}
};


int main()
{
	string s = "abcdefghijklmn";
	int numRows = 3;
	Solution solution;
	cout << solution.convert(s, numRows) << std::endl;
	cout << solution.convert("a", 1) << std::endl;
	return 0;
}
