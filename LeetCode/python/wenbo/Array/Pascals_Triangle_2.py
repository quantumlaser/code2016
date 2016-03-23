class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        preRow = [1]*(rowIndex + 1)
        curRow = [1]*(rowIndex + 1)
        for r in range(1, rowIndex):
            for i in range(1, r + 1):
                curRow[i] = preRow[i] + preRow[i - 1]
                # print r, i, preRow, curRow
            preRow[:r + 1] = curRow[:r + 1]
        return curRow