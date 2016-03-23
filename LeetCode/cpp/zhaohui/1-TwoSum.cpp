#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class DataNode {
	int num;
	int ind;
public:
	DataNode(int number,int index) {
		num = number;
		ind = index;
	}
	int getNum() { return num; }
	int getInd() { return ind; }
	
};
bool comp(DataNode data1, DataNode data2) {
	return data1.getNum() < data2.getNum();
}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;
		vector<DataNode> data;
		for (unsigned int i = 0; i < nums.size(); i++) {
			data.push_back(DataNode(nums[i], i));
		}
		sort(data.begin(), data.end(), comp);
		int left = 0, right = nums.size() - 1;
		int tempSum = 0;
		while (left < right) {
			tempSum = data[left].getNum() + data[right].getNum();
			if (tempSum == target) {
				if (data[left].getInd() < data[right].getInd()) {
					index.push_back(data[left].getInd());
					index.push_back(data[right].getInd());
				}
				else {
					index.push_back(data[right].getInd());
					index.push_back(data[left].getInd());
				}
			}
			if (tempSum < target) {
				left++;
			}
			else {
				right--;
			}
		}
		return index;
	}

};


int main() {
	Solution solution;
	//int nums[] = { 1,2,3 };
	vector<int> nums = { 1,2,3 };
	//nums.push_back(1);
	int target = 3;
	vector<int> res = solution.twoSum(nums, target);
	for (unsigned int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}