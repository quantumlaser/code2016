class Solution:
	# @param {integer} numRows
	# @return {integer[][]}
	def generate(self, numRows):
		if numRows == 0:
			return []
		elif numRows == 1:
			return [[1]]
		elif numRows == 2:
			return [[1], [1, 1]]
		else:
			ans = [[1], [1, 1]]
			for i in range(2, numRows):
				row = [1]
				for j in range(i-1):
					row.append(ans[i-1][j]+ans[i-1][j+1])
				row.append(1)
				ans.append(row)
		return ans


print Solution().generate(5)
