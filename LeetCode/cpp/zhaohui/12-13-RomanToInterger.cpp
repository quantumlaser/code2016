/*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
*/
#include<iostream>
#include<string>
#include<unordered_map>
using std::string;
using std::cout;
using std::endl;
using std::unordered_map;

class Solution {
public:
	//hash_map,直观但是效率一般
	int romanToInt1(string s) {
		string numStr = "IVXLCDM";
		int numList[] = { 1,5,10,50,100,500,1000 };
		unordered_map<char, int> romanMap;
		for (int i = 0; i<7; i++)
			romanMap[numStr[i]] = numList[i];

		int res = 0, len = s.length(),temp;
		for (int i = 0; i<len; i++) {
			temp = romanMap[s[i]];
			if (i < len - 1 && temp < romanMap[s[i + 1]]) {
				temp = -temp;
			}
			res = res + temp;
		}
		return res;

	}
	int romanToInt(string s) {
		int res = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			char c = s[i];
			switch (c) {
			case 'I':
				res += (res >= 5 ? -1 : 1);
				break;
			case 'V':
				res += 5;
				break;
			case 'X':
				res += 10 * (res >= 50 ? -1 : 1);
				break;
			case 'L':
				res += 50;
				break;
			case 'C':
				res += 100 * (res >= 500 ? -1 : 1);
				break;
			case 'D':
				res += 500;
				break;
			case 'M':
				res += 1000;
				break;
			}
		}
		return res;
	}

	string intToRoman(int num) {
		if (num == 0)
			return "";
		if (num >= 1000)
			return string(num / 1000, 'M') + intToRoman(num % 1000);
		if (num >= 900)
			return "CM" + intToRoman(num - 900);
		if (num >= 500)
			return "D" + string((num - 500) / 100, 'C') + intToRoman(num % 100);
		if (num >= 400)
			return "CD" + intToRoman(num - 400);
		if (num >= 100)
			return string(num / 100, 'C') + intToRoman(num % 100);
		if (num >= 90)
			return "XC" + intToRoman(num - 90);
		if (num >= 50)
			return "L" + string((num - 50) / 10, 'X') + intToRoman(num % 10);
		if (num >= 40)
			return "XL" + intToRoman(num - 40);
		if (num >= 10)
			return string(num / 10, 'X') + intToRoman(num % 10);
		if (num == 9)
			return "IX";
		if (num >= 5)
			return "V" + string(num - 5, 'I');
		if (num == 4)
			return "IV";
		else
			return string(num, 'I');
	}
};

int main() {
	Solution solution;
	cout << solution.romanToInt("I") << endl;
	cout << solution.romanToInt("VIII") << endl;
	cout << solution.romanToInt("MMMCMXCIX") << endl;//3999
	cout << solution.romanToInt("DCCC") << endl;//800
	cout << solution.romanToInt("XCVIII") << endl;//98
	cout << solution.romanToInt("XII") << endl;//12
	cout << solution.romanToInt("MCMLXXVI") << endl;//1976
	cout << solution.intToRoman(1976) << endl;
	cout << solution.intToRoman(12) << endl;
	cout << solution.intToRoman(98) << endl;
	cout << solution.intToRoman(800) << endl;
	cout << solution.intToRoman(3999) << endl;
	cout << solution.intToRoman(8) << endl;

}
