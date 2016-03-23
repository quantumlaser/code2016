/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
			return 0;
		int len = str.size();
		if(len<1)
			return 0;
		bool pos = true;
		int i=0;
		while(str[i]==' ') i++;
		if((str[i]=='-'||str[i]=='+')){
			pos = str[i] == '-' ? !pos : pos;
			i++;
		}
		long long res=0;
		for(;i<len;i++){
			if(str[i]<'0'||str[i]>'9')
				break;
			else
				res = res*10 + (str[i]-'0');
			if(pos &&res > INT_MAX ) return INT_MAX;
			if(!pos && -res < INT_MIN) return INT_MIN;
		}
		return pos ? res : -res;		
    }
};

int main(){
	Solution solution;
	cout<<solution.myAtoi("")<<endl;
	cout<<solution.myAtoi("-")<<endl;
	cout<<solution.myAtoi("-10")<<endl;
	cout<<solution.myAtoi("-123")<<endl;
	cout<<solution.myAtoi("100")<<endl;
	cout<<solution.myAtoi("+1")<<endl;
	cout<<solution.myAtoi("2147483648")<<endl;
	cout<<solution.myAtoi("-1000000000000000")<<endl;
	cout<<solution.myAtoi("10000000000000")<<endl;
	return 0;
}


