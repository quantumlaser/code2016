class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        result = []
        for row in range(numRows):
            if row > 0:
                element = []
                numElement = row + 1
                for index in range(numElement):
                    if index == 0 or index == numElement - 1:
                        element.append(1)
                    else:
                        element.append(result[row - 1][index - 1] + result[row - 1][index])
                result.append(element)
            else: result.append([1])
        return result