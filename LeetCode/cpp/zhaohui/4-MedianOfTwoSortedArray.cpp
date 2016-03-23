/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::min;
using std::max;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1<len2)
			return findMedianSortedArrays(nums2, nums1);
		if (len2 == 0)
			return ((double)nums1[(len1 - 1) / 2] + (double)nums1[len1 / 2]) / 2;
		int left = 0, right = 2 * len2;
		int mid1, mid2;
		double L1, R1, L2, R2;
		while (left<=right) {
			mid2 = (left + right) / 2;
			mid1 = len1 + len2 - mid2;

			L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
			L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
			R1 = (mid1 == 2 * len1) ? INT_MAX : nums1[mid1 / 2];
			R2 = (mid2 == 2 * len2) ? INT_MAX : nums2[mid2 / 2];

			if (L1 > R2)
				left = mid2 + 1;
			else if (L2 > R1)
				right = mid2 - 1;
			else
				return (max(L1, L2) + min(R1, R2)) / 2;

		}
		return -1;
	}
};
void test(vector<int> vec){
	vec[0] =100;
}
int main(){
	Solution solution;
	int int_nums1[] = {1,2,4,6,8};
	int int_nums2[] = {3,5,7,9};
	vector<int> nums1(int_nums1,int_nums1+5);
	vector<int> nums2(int_nums2,int_nums2+4);
	cout<<solution.findMedianSortedArrays(nums1,nums2);
	return 0;
}


