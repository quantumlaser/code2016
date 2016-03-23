#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int countLeap(int date1[3], int date2[3]);
int countLeap(int a, int b);
bool isLeap(int year) {
	return year % 4 == 0 && (year % 100 != 0) || year % 400 == 0 ? true : false;
}
void getDate(int date[], string &monthStr, char dayStr[3], int year)
{
	string str[12] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
	for (int i = 0; i < 12; i++) {
		if (monthStr == str[i]) {
			date[0] = i + 1;
			break;
		}
	}
	if (dayStr[1] == ',') {
		date[1] = dayStr[0] - '0';
	}
	else {
		date[1] = (dayStr[0] - '0') * 10 + dayStr[1] - '0';
	}
	date[2] = year;
	return;
}
int countLeap(int st, int en);
int main() {

#define Str1048
#ifndef Str1048
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	string monthStr;
	char dayStr[4];
	int year;
	int date1[3], date2[3];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> monthStr >> dayStr >> year;
		getDate(date1, monthStr, dayStr, year);
		//cout << date1[0]<<" "<<date1[1]<<" "<<date1[2] << endl;

		cin >> monthStr >> dayStr >> year;
		getDate(date2, monthStr, dayStr, year);
		//cout << date2[0] << " " << date2[1] << " " << date2[2] << endl;
		cout << "Case #" << i + 1 << ": " << countLeap(date1, date2)<<endl;
	}
	return 0;
}

int countLeap(int date1[3], int date2[3]) {
	int yearStart = date1[2], yearEnd = date2[2];
	if (date1[0] < 2 || (date1[0] == 2 && date1[1] <= 29)) {
		yearStart--;
	}
	if (date2[0] < 2 || (date2[0] == 2 && date2[1] < 29)) {
		yearEnd--;
	}
	return countLeap(yearStart, yearEnd);
}
int countLeap(int a, int b) {
	int cnt4 = ((b - b % 4) - (a - a % 4)) / 4;
	int cnt100 = ((b - b % 100) - (a - a % 100)) / 100;
	int cnt400 = ((b - b % 400) - (a - a % 400)) / 400;
	return cnt4 - cnt100 + cnt400;
}
