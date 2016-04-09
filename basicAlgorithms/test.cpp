#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void test(int a[]){
	int *b =new int[3];
	for(int i=0;i<3;i++) b[i]=10-i;
	memcpy(a,b,sizeof(int)*3);
}
int main(){
	int a[] = {1,2,3};
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
