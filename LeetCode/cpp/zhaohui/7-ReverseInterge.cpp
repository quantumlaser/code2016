/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
		long long res = 0;
        while(x!=0){
			res = res*10 + x%10;
			x = x/10;
		}
		return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};

int main(){
	Solution solution;
	cout<<solution.reverse(123)<<endl;
	cout<<solution.reverse(-123)<<endl;
	cout<<solution.reverse(1534236469)<<endl;
}