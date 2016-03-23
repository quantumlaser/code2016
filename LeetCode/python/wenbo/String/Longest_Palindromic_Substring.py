'''
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
'''
class Solution:
    # @param {string} s
    # @return {string}
    def expendAroundCenter(self, s, l, r):
        n = len(s)
        while s[l] == s[r]:
            l = l - 1
            r = r + 1
            if l < 0 or r >= n:
                break
        return s[l + 1:r]
        
    
    def longestPalindrome(self, s):
        ms = ''
        length = 0
        for i in range(len(s)):
            tmp = self.expendAroundCenter(s, i, i)
            if len(tmp) > length:
                ms = tmp
                length = len(ms)
            if i < len(s) - 1:
                tmp = self.expendAroundCenter(s, i, i+1)
                if len(tmp) > length:
                    ms = tmp
                    length = len(ms)
        return ms
        
    '''
    # Too slow
    def longestPalindrome(self, s):
        import copy
        if len(s) == 0:
            return ''
        elif len(s) == 1:
            return s
        elif len(s) == 2:
            if s[0] == s[1]:
                return s
            else:
                return ''
        else:
            ms = []
            p = 1
            while p < len(s):
                h = p
                t = p - 1
                buf = []
                while h < len(s) and t >= 0:
                    if s[h] == s[t]:
                        buf.append(s[h])
                        if len(buf)*2 > len(ms):
                            tmp = copy.copy(buf)
                            tmp.reverse()
                            ms = tmp + copy.copy(buf)
                        t = t - 1
                        h = h + 1
                    else:
                        break
                p = p + 1
            p = 1
            while p < len(s):
                h = p + 1
                t = p - 1
                buf = []
                while h < len(s) and t >= 0:
                    if s[t] == s[h]:
                        buf.append(s[h])
                        if len(buf)*2 + 1> len(ms):
                            tmp = copy.copy(buf)
                            tmp.reverse()
                            ms = tmp + [s[p]] + copy.copy(buf)
                        t = t - 1
                        h = h + 1
                    else:
                        break
                p = p + 1
            result = ''
            for i in ms: result = result + i
            return result
    '''