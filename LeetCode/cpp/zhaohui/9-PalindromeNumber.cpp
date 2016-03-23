//Determine whether an integer is a palindrome. Do this without extra space.

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    long long reverse(int x) {
		long long res = 0;
        while(x!=0){
			res = res*10 + x%10;
			x = x/10;
		}
		return res ;
    }
	
	bool isPalindrome1(int x){
	    if(x<0)
	        return false;
		if(x<10)
			return true;
		if(reverse(x)==x)
			return true;
		else
			return false;
		
	}
	
	bool isPalindrome(int x){
		if(x<0 ||(x>0&&(x%10==0)))
			return false;
		if(x<10)
			return true;
		int y = 0;
		while(x>y){
			y = y*10 + x%10;
			x = x/10;
		}
		return (x == y) || (x == y/10);
	}
};

int main(){
	Solution solution;
	cout<<solution.isPalindrome(121)<<endl;
	cout<<solution.isPalindrome(-12321)<<endl;
	cout<<solution.isPalindrome(1234)<<endl;
	cout<<solution.isPalindrome(1534236469)<<endl;
}