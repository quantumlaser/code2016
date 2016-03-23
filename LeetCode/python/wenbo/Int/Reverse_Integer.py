'''
Reverse Integer 
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
'''
class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        if abs(x) < 10:
            return x
        if x < 0:
            x = -x
            neg = True
        else:
            neg = False
        res = 0
        while x/10 > 0:
            res = res*10 + x%10
            x = x/10
            # print res, x
        res = res*10 + x
        if neg:
            res = -res
        return res