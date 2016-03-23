class Solution:
	# @param {string} s
	# @return {integer}
	def lengthOfLongestSubstring(self, s):
		rec = [None] * 512
		answer = 0
		length = 0
		hit_idx = 0
		for i in range(len(s)):
			if rec[ord(s[i])] == None:
				length += 1
			else:
				length = i - max(rec[ord(s[i])], hit_idx)
				if hit_idx < rec[ord(s[i])]:
					hit_idx = rec[ord(s[i])]
			rec[ord(s[i])] = i
			if length > answer:
				answer = length
		return answer

print Solution().lengthOfLongestSubstring('abba')
print Solution().lengthOfLongestSubstring('asdfghjksqswesr')
print Solution().lengthOfLongestSubstring('abcabcbb')
print Solution().lengthOfLongestSubstring('bbbbb')
