#include <iostream>
#include <string>
#include <vector>
#include<fstream>
int main() {

// #define Str1039
#ifndef Str1039
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int N = 12;
    int T,n;
    std::cin>>T;
    while(T--){
        std::cin>>n;
        if(n==2)
            std::cout<<"YES"<<std::endl;
        if(n<2 || n%2 ==0)
            std::cout<<"NO"<<std::endl;
        for(int i = 0; i < N; i++){
            
        }
    }
}