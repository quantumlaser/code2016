class Solution:
	# @param {string} s
	# @return {string}
	def longestPalindrome(self, s):
		length = len(s)
		res = [[None]*length]*length
		for i in range(2, length-1):
			j = 0
			while (j+i) < length:
				if i == 2:
					res[j][i] = 2
				elif i%2 == 1:
					
				j += 1
