#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int main() {

// #define Str1038
#ifndef Str1038
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif
	int M, N;
	int i, j;
	int value[501];
	int need[501];
	int dp[100001];
	while (cin >> N >> M) {
		for (i = 1; i <= N; i++) {
			cin >> need[i] >> value[i];
		}
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= N; i++) {
			for (j = M; j >= need[i]; j--) {
				dp[j] = dp[j]>dp[j - need[i]] + value[i] ? dp[j] : dp[j - need[i]] + value[i];
			}
		}
		cout << dp[M ] << endl;
	}
	return 0;
}
