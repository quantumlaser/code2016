/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<time.h>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

class Solution {
public:

	int maxArea(vector<int> & height) {
		int left = 0, right = height.size() - 1, maxA = 0;
		//while (left < right) maxA = max(maxA,(right - left) * (height[left] < height[right] ? height[left++] : height[right--]));
		while (left < right) {
			if (height[left] < height[right]) {
				maxA = max((right - left)*height[left], maxA);
				left++;
			}
			else {
				maxA = max((right - left)*height[right],maxA);
				right--;
			}
		}
		return maxA;
	}


	
};

int main() {
	clock_t timeStart = clock();
	int hArray[] = { 2,3,10,5,7,8,9 };
	vector<int> test;
	vector<int> height(hArray, hArray + 7);
	vector<int> height1;
	for (int i = 0; i < 100000; i++) {
		height1.push_back(i + 1);
	}
	Solution solution;
	cout << solution.maxArea(height)<<endl;
	cout << solution.maxArea(height1)<<endl;
	cout << "Time: " << (double)(clock() - timeStart)/CLOCKS_PER_SEC << endl;
	return 0;
}