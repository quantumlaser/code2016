#include<iostream>
#include<cstring>
#include<string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void test(int a[]){
	int *b =new int[3];
	for(int i=0;i<3;i++) b[i]=10-i;
	memcpy(a,b,sizeof(int)*3);
}
int main(){
	int a[] = {1,2,3};
	double dd = 3.5;
	srand (time(NULL));
	int N =1000,n=0;
	while(N--) {
		double temp =rand() / (double)(RAND_MAX);
		if(temp<0.1)
			n++;
	}
	cout<<"N:"<<n<<endl;
	//double ran = rand() / (double)(RAND_MAX);
	cout<<1/dd<<endl;
	test(a);
	for(int i=0;i<3;i++) cout<<a[i]<<" ";
	cout<<endl;
	string str;
	getline(cin,str);
	cout<<str<<endl;
	cout<<str.size();
	string tt;
	while(cin>>tt) cout<<tt<<endl;
	return 0;
}
