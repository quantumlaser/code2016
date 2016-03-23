'''
ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
'''

class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    '''
    -->x 1,2,3...
    |
    y
    
    A    |G
    B   F|H
    C E  |I
    D    |J
    '''
    
    def convert(self, s, numRows):
        n = len(s)
        r = numRows
        if r == 1:
            return s
        c = []
        for i in range(r):
            c.append('')
        
        for i in range(n):
            idx = i%((r-2)*2+2)
            if idx < r:
                c[idx] = c[idx] + s[i]
            else:
                c[(r-2)-(idx-r)] = c[(r-2)-(idx-r)] + s[i]
        
        res = ''
        for i in range(r):
            res = res + c[i]
        
        return res
    
    '''
    #  Time Limit Exceeded
    def convert(self, s, numRows):
        n = len(s)
        r = numRows
        if r == 1:
            return s
        c = []
        for i in range(r):
            tmp = []
            for j in range(n):
                tmp.append(-1)
            c.append(tmp)
        
        for i in range(n):
            if i == 0:
                c[0][0] = i
                prex = 0
                prey = 0
            else:
                if prex%(r-1) == 0:
                    if prey < r-1:
                        x = prex
                        y = prey + 1
                    else:
                        x = prex + 1
                        y = prey - 1
                else:
                    if prey > 0:
                        x = prex + 1
                        y = prey - 1
                    else:
                        x = prex
                        y = prey + 1
                c[y][x] = i
                prex = x
                prey = y
        
        res = ''
        for i in range(r):
            for j in range(n):
                if c[i][j] > -1:
                    res = res + s[c[i][j]]
        
        return res
    '''