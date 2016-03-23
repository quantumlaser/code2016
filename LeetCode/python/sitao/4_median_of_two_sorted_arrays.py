class Solution:
	# @param {integer[]} nums1
	# @param {integer[]} nums2
	# @return {float}
	def findMedianSortedArrays(self, nums1, nums2):
		num = nums1 + nums2
		num.sort()
		if len(num) % 2 == 1:
			return num[(len(num)-1)/2]
		else:
			return (float(num[len(num)/2]) + float(num[len(num)/2-1]))/2


print Solution().findMedianSortedArrays([1 ,2 ,4], [7, 8, 9])
