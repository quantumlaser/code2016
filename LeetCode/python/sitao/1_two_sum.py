class Solution:
	# @param {integer[]} nums
	# @param {integer} target
	# @return {integer[]}
	def twoSum(self, nums, target):
		index = sorted(range(len(nums)), key=lambda k:nums[k])
		nums.sort()
		for i in range(0, len(nums)):
			for j in range(i+1, len(nums)):
				if (nums[i] + nums[j]) == target:
					return sorted([index[i]+1, index[j]+1])
				elif (nums[i] + nums[j]) > target:
					break

# numbers = [2, 7, 11, 15]
# target = 9

# numbers = range(0, 32046, 2)
# numbers = eval(open('data.txt').read())
# target = 16021

# numbers = [3,2,4]
# target = 6

numbers = [0, 4, 3, 0]
target = 0

print Solution().twoSum(numbers, target)
