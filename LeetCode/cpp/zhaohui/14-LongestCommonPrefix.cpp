/*Write a function to find the longest common prefix string amongst an array of strings.
*/


#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
			return "";
		int num = strs.size();
		if(num == 1)
			return strs[0];
		string commonStr = "";
		int minLen = INT_MAX;
		for(int i=0;i<num;i++){
			if(minLen > strs[i].length())
				minLen = strs[i].length();
		}
		char c;
		int endPos = -1;
		bool findEnd = false;
		for(int i=0;i<minLen;i++){
			c = strs[0][i];
			for(int j=1;j<num;j++){
				if(strs[j][i] != c){
					endPos = i;
					findEnd = true;
					break;
				}
			}
			if(findEnd)
				break;
		}
		if(!findEnd)
			endPos = minLen;
		return strs[0].substr(0,endPos);
    }
};

int main(){
	vector<string> strs;
	strs.push_back("abcdefg");
	strs.push_back("abclmn");
	strs.push_back("abdefg");
	Solution solution;
	vector<string> strs1;
	strs1.push_back("abdefg");
	cout<<solution.longestCommonPrefix(strs)<<endl;
	cout<<solution.longestCommonPrefix(strs1)<<endl;
}