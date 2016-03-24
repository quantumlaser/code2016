#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
void sort3(int a[3]);
void vanish(int xyz[3], int C[3]);
int main() {
	// #define Str1038
#ifndef Str1038
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	int xyz[3];
	int C[3] = { 0,0,0 };
	int max_num = 0;
	int temp;
	char c;
	cin >> xyz[0] >> xyz[1] >> xyz[2];
	sort3(xyz);
	// cin.get();
	// string str;cin>>str;
	while (cin>>c) {
		switch (c) {
		case 'R':
			C[0]++;
			break;
		case 'Y':
			C[1]++;
			break;
		case 'B':
			C[2]++;
			break;
		default: cout << "Wrong Input!" << endl;
		}
		max_num = max(max_num, C[0] + C[1] + C[2]);
		vanish(xyz, C);
	}
	cout << max_num << endl;
}
void vanish(int xyz[3], int C[3]) {
	int D[3];
	D[0] = abs(C[0] - C[1]);
	D[1] = abs(C[1] - C[2]);
	D[2] = abs(C[2] - C[0]);
	sort3(D);
	if (D[0] == xyz[0] && D[1] == xyz[1] && D[2] == xyz[2]) {
		C[0] = 0;
		C[1] = 0;
		C[2] = 0;
	}
}
void sort3(int a[]) {
	int temp;
	if (a[1] < a[0]) {
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	if (a[2] < a[1]) {
		temp = a[2];
		a[2] = a[1];
		if (temp < a[0]) {
			a[1] = a[0];
			a[0] = temp;
		}
		else {
			a[1] = temp;
		}
	}
}