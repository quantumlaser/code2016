# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	# @param {ListNode} l1
	# @param {ListNode} l2
	# @return {ListNode}
	def addTwoNumbers(self, l1, l2):
		head = ListNode(0)
		answer = ListNode(0)
		head.next = answer
		answer_p = head
		p1 = l1
		p2 = l2
		carry = 0
		while ((p1 != None) or (p2 != None) or (carry != 0)):
			if answer_p.next == None:
				answer_p.next = ListNode(0)
			answer_p = answer_p.next
			if ((p1 != None) and (p2 != None)):
				digit_sum = p1.val + p2.val + carry
				p1 = p1.next
				p2 = p2.next
			elif ((p1 != None) and (p2 == None)):
				digit_sum = p1.val + carry
				p1 = p1.next
			elif ((p1 == None) and (p2 != None)):
				digit_sum = p2.val + carry
				p2 = p2.next
			else:
				digit_sum = carry
			[carry, answer_p.val] = [0, digit_sum] if digit_sum < 10 else [1, digit_sum-10]
		return answer


def print_list(lst):
	pt = lst
	print_str = str(pt.val)
	while pt.next != None:
		pt = pt.next
		print_str += '->'+ str(pt.val)
	print print_str

a = ListNode(4)
# a.next = ListNode(4)
# a.next.next = ListNode(3)

b = ListNode(5)
# b.next = ListNode(6)
# b.next.next = ListNode(4)

print_list(a)
print_list(b)

print_list(Solution().addTwoNumbers(a, b))

