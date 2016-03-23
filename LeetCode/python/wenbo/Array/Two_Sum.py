'''
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
'''

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    
    def twoSum(self, nums, target):
        '''
        # naive approach:  Time Limit Exceeded
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if i != j and nums[i] + nums[j] == target:
                    if nums[i] < nums[j]:
                        return i, j
                    else:
                        return j, i
        '''
        pool = {}
        for i in range(len(nums)):
            if pool.has_key(nums[i]):
                pool[nums[i]].append(i)
            else:
                pool[nums[i]] = [i]
        
        for i in range(len(nums)):
            if pool.has_key(target - nums[i]):
                for j in pool[target - nums[i]]:
                    if i < j:
                        return i+1, j+1
                    elif j < i:
                        return j+1, i+1
        return -1