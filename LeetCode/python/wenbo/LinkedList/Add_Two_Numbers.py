'''
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def updateNext(self, head):
        if head.next == None:
            head.next = ListNode(1)
        else:
            head.next.val = head.next.val + 1
            if head.next.val > 9:
                head.next.val = head.next.val - 10
                self.updateNext(head.next)
        
    def addTwoNumbers(self, l1, l2):
        init = True
        carry = 0
        tmp = 0
        pre = None
        head = None
        while True:
            if init:
                pass
            else:
                l1 = l1.next
                l2 = l2.next

            tmp = l1.val + l2.val + carry

            if tmp > 9: 
                carry = 1
                tmp = tmp - 10
            else:
                carry = 0

            if init:
                head = ListNode(tmp)
                pre = head
                init = False
            else:
                newNode = ListNode(tmp)
                pre.next = newNode
                pre = newNode
            
            if l1.next == None or l2.next == None:
                break
        if l1.next != None:
            pre.next = l1.next
        if l2.next != None:
            pre.next = l2.next
        if carry == 1:
            self.updateNext(pre)
        return head