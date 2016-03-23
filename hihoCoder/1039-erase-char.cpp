#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;


string dealStr(string &s) {
	vector<char> vResult;
	vResult.push_back(s[0]);
	for (int i = 1; i < s.size() - 1; i++) {
		int preI = i - 1;
		while (s[i + 1] == s[i])i++;     //  有连续的好几个字符，则不做任何处理
		if (i - 1 == preI)    // 单独的一个字符，则push进去
			vResult.push_back(s[i]);
	}
	return string(vResult.begin(), vResult.end());
}


int main() {

// #define Str1039
#ifndef Str1039
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif

	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		str = "#" + str + "$";
		int maxCount = 0;
		char c[4] = "ABC";

		for (int i = 1; i < str.size(); i++) {
			for (int k = 0; k < 3; k++) {
				string s(str);
				s.insert(i, 1, c[k]);
				int len = s.size();
				while (true) {
					s = dealStr(s) + "$";
					if (s.size() < len)
						len = s.size();
					else break;
				}
				if (maxCount < (str.size() - s.size() + 1)) {
					maxCount = str.size() - s.size() + 1;
				}
			}

		}
		cout << maxCount << endl;
	}
	return 0;
}
