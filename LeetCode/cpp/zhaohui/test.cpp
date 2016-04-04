#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  vector<int> a(5,1);
  vector<int> b = a;
  set<int> c,d;
  c.insert(3);
  c.insert(4);
  d = c;
  d.erase(4);
  for(set<int>::iterator it = c.begin(); it!= c.end(); it++){
      cout<<*it<<" ";
  }
  b[2]=2;
  cout<<a[2]<<" "<<b[2]<<endl;
  return 0;
}
