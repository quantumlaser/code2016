#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<string.h>
#include <iomanip>
using namespace std;
/*
	用一个unsigned int 表示当前数码管显示情况下9-0的数字能否显示的情况，0表示不能，1表示可能。
	对某种情况下某个数字i能否显示，去看该数的右数第i+1位是否为1。
	如果当前电子管不能显示N对应位的数，则将当前位小于其的数量乘以之后所有电子管能显示的所有数即满足要求。
*/
unsigned int location[6];
// 每个电子管亮的时候数字能否显示情况
const unsigned int light[8] = { 0,01755,01561,01637,01574,00505,01773,01555 };
int bitCount(unsigned int n)
{
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}
bool compareFile(char name1[100], char name2[100]) {
	ifstream inFile1(name1), inFile2(name2);
	char str1[100], str2[100];
	int line = 0;
	bool flag = true;
	while (inFile1.getline(str1,100) && inFile2.getline(str2,100)) {
		line++;
		if (strcmp(str1, str2)) {
			cout << "line: " << line << str1 << " "<<str2 << endl;
			flag = false;
		}
	}
	return flag;
}
int main() {
// #define Str1038
#ifndef Str1038
	std::ifstream in("input00001.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	clock_t start, finish;
	start = clock();
	int S, K, N;
	unsigned int ok_cnt[6];// ok_cnt[i]表示编号i的电子管及之后电子管能够显示的数的总数。
	unsigned int small_cnt[6];// smail_cnt[i]表示当前位置可以显示的比N对应的位置小的数的数目。
	unsigned int each_num[10]; // 表示N第0阶的数。
	int i, j;
	char c;
	int deg;
	int temp;
	int res;

	cin >> S;
	while (S--) {
		cin >> K >> N;
		while(cin.get()!='\n');
		for (i = 0; i < K; i++) {
			location[i] = 0xffff;
			for (j = 0; j < 7; j++) {
				while ((c = cin.get()) == ' ');
				if (c == '\n'|| c == -1) break;
				location[i] = location[i] & light[c - '0'];
			}
			if (j == 7) while(cin.get()!='\n');
			ok_cnt[i] = bitCount(location[i]);// 此时存储当前位置可以显示的数
		}
		deg = 0;
		if (!N) {
			cout << 0 << endl;
			continue;
		}
		temp = N;
		for (i = 0; temp > 0;i++) {
			each_num[i] = temp % 10;
			temp = temp / 10;
		}
		deg = i;
		ok_cnt[K] = 1;
		for (i = K - 2; i >= 0; i--) {
			ok_cnt[i] = ok_cnt[i + 1] * ok_cnt[i]; // 统计累计数
		}
		// 如果数码管数量小于位数，直接返回最大的
		if (K < deg) {
			cout << ok_cnt[0] << endl;
			continue;
		}
		memset(small_cnt, 0, sizeof(small_cnt));
		for (i = K - 1; i >= K - deg; i--) {
			// 统计当前数码管可以显示的比当前数小的数目，如果左移32位会出问题。
			small_cnt[i] = each_num[K-i-1] ?
				bitCount(location[i] <<(32-each_num[K-1-i])) : 0;
		}
		if (K > deg) {
			temp = location[0];
			for (i = 1; i < K - deg; i++) {
				temp = temp & location[i];
			}
			// 在deg之外的只要0不能出现，就返回0。
			if (!(temp & 1)) {
				cout << 0 << endl;
				continue;
			}
		}
		res = 0;
		bool find = false;
		for (i = K-deg; i < K; i++) {
			int cnt = 0;
			res = res + small_cnt[i] * ok_cnt[i+1];
			// 如果当前数码管不能显示当前的数,就可以直接退出，否则继续。
			if (!((location[i] >> each_num[K-i-1]) & 1)) {
				cout << res << endl;
				find = true;
				break;
			}
		}
		if (!find) cout << res << endl;
	}
	// cout << "time: " << double(clock() - start)/CLOCKS_PER_SEC << endl;
	return 0;
}
