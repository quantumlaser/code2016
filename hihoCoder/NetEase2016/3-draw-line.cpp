#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int swap(int &a, int &b){
	int temp=a;
	a = b;
	b = temp;
}
int main(){
	// #define Str3
#ifndef Str3
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	int S;
	int N;
	int x0,y0,x1,y1;
	int temp;
	vector<vector<int> > vec;
	vector<int> xy;
	xy.push_back(3);
	vec.push_back(xy);
	xy.clear();
	xy.push_back(4);
	xy.push_back(5);
	vec.push_back(xy);
	xy.clear();
	cout<<vec[0][0]<<" "<<vec[1][1]<<endl;
	while(S--){
		cin>>N;
		while(N--){
			cin>>x0>>y0>>x1>>y1;
			xy.clear();
			if(x0>x1){
				swap(x0,x1);
				swap(y0,y1);
			}
			if(x0 == x1 && y0 > y1){
				swap(y0,y1);
			}
			xy.push_back(x0);
			xy.push_back(y0);
			xy.push_back(x1);
			xy.push_back(y1);	
			if(x0 == x1){
				xy.push_back(0);
				xy.push_back(x0);
			}
			if(y0 == y1){
				xy.push_back(1);
				xy.push_back(y0);
			}
			if(x0 + y0 == x1 + y1){
				xy.push_back(2);
				xy.push_back(x0 + y0);
			} else{
				xy.push_back(3);
				xy.push_back(x0 - y0);
			}
			vec.push_back(xy);			
		}
		for(int i=0;i<vec.size();i++){
			for(int j=0;j<6;j++){
				cout<<vec[i][j]<<" ";
			}
			cout<<endl;
		}
	}

}