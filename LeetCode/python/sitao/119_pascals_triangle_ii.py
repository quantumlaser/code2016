class Solution:
	# @param {integer} rowIndex
	# @return {integer[]}
	def getRow(self, rowIndex):
		if rowIndex == 0:
			return [1]
		elif rowIndex == 1:
			return [1, 1]
		else:
			row = [1, 1]
			for i in range(2, rowIndex+1):
				prev = row[0]
				for j in range(1, i):
					curr = row[j]
					row[j] = prev + curr
					prev = curr
				row.append(1)
		return row

print Solution().getRow(0)
print Solution().getRow(1)
print Solution().getRow(3)
print Solution().getRow(5)
