#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;
string num1, num2;
int result[2048] = { 0 };
int order;
void bigMulti();
bool check();
int main() {
	// #define bigMulti
#ifndef bigMulti
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	cin >> num1 >> num2;
	bigMulti();
	if (!check()) {
		cout << "false" << endl;
	}
}
void bigMulti() {
	int len1 = num1.size();
	int len2 = num2.size();
	int cat, temp;
	for (int i = len1-1; i >=0; i--) {
		cat = 0;
		for (int j = len2-1; j >=0; j--) {
			temp = result[len1+len2-i-j-2] + cat + (num1[i]-'0') * (num2[j]-'0');
			result[len1 + len2 - i - j - 2] = temp % 10;
			cat = temp / 10;
		}
		result[len1 + len2 - i-1] = cat;
	}
	order = len1 + len2;
	while (result[order-1] == 0&&order>0) order--;
	if (!order) order = 1;
	int k = order - 1;
	while (k > (order-1) / 2) {
		temp = result[k];
		result[k] = result[order - k - 1];
		result[order - k - 1] = temp;
		k--;
	}
	for (int i = 0; i < order; i++) {
		cout << result[i];
	}
	cout << endl;
}
bool check() {
	long long int iNum1, iNum2;
	iNum1 = stoi(num1);
	iNum2 = stoi(num2);
	long long int res = iNum1*iNum2;
	cout << res << endl;
	int i = 0;
	while(res) {
		if (res % 10 != result[order - i - 1]) {
			return false;
		}
		res = res / 10;
		i++;
	}
	return true;
}