'''
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
'''
class Solution:
    # @param {string} s
    # @return {integer}
    
    def lengthOfLongestSubstring(self, s):
        if len(s) == 0:
            return 0
        p = []
        for i in range(len(s)): p.append(0)
        maxs_begin = 0
        k = {}
        for i in range(len(s)):
            if k.has_key(s[i]):
                p[i] = p[i-1]
                repeat_idx = k[s[i]]
                for j in range(maxs_begin, repeat_idx):
                    k.pop(s[j], None)
                k[s[i]] = i
                maxs_begin = repeat_idx + 1
            else:
                k[s[i]] = i
                if i == 0:
                    p[i] = 1
                elif i - maxs_begin + 1 > p[i-1]:
                    p[i] = i - maxs_begin + 1
                else:
                    p[i] = p[i-1]
            # print p, k
        return p[-1]
            
    # Divide and conquer: too slow      
    # import copy
    # def findBetween(self, s1, s2):
    #     if s1[-1] == s2[0]:
    #         return 1
    #     else:
    #         p = {}
    #         # maxs = ""
    #         maxn = 2
    #         for i in reversed(range(len(s1))):
    #             if p.has_key(s1[i]):
    #                 break
    #             else:
    #                 p[s1[i]] = 1
    #                 if len(s1) - i > maxn:
    #                     maxn = len(s1) - i
    #                     # maxs = s1[i:]
    #                 p1 = copy.copy(p)
    #                 for j in range(len(s2)):
    #                     if p1.has_key(s2[j]):
    #                         break
    #                     else:
    #                         p1[s2[j]] = 1
    #                         if len(s1) - i + j + 1 > maxn:
    #                             maxn = len(s1) - i + j + 1
    #                             # maxs = s1[i:] + s2[:j]
    #         return maxn
                        
    # def lengthOfLongestSubstring(self, s):
    #     if len(s) == 0:
    #         return 0
    #     if len(s) == 1:
    #         return 1
    #     elif len(s) == 2:
    #         if s[0] == s[1]:
    #             return 1
    #         else:
    #             return 0
    #     else:
    #         left = self.lengthOfLongestSubstring(s[:len(s)/2])
    #         right = self.lengthOfLongestSubstring(s[len(s)/2:])
    #         between = self.findBetween(s[:len(s)/2], s[len(s)/2:])
    #         return max([left, right, between])