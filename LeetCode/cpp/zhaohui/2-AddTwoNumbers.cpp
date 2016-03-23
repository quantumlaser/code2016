#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pNode1 = l1,*pNode2 = l2;
		int temp,carry=0;
		ListNode* tNode = l1;
		while(pNode1!=NULL && pNode2 != NULL){
			temp = (pNode1->val + pNode2->val + carry);
			carry = temp / 10;
			pNode1->val = temp%10;
			tNode = pNode1;
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		if(pNode1 == NULL){
			tNode->next = pNode2;
			pNode1 = pNode2;
		}
		while(pNode1!=NULL){
			temp = (pNode1->val + carry);
			carry = temp / 10;
			pNode1->val = temp%10;
			tNode = pNode1;
			pNode1 = pNode1->next;
			//pNode2 = pNode2->next;
		}
		if(carry>0){
			tNode->next = new ListNode(carry); 
		}
		return l1;
	}
	//这个方法内存不够用了
	ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
		int temp = l1->val + l2->val;
		int carry = temp/10;
		ListNode* resHead = new ListNode(temp % 10);
		ListNode* pNode = resHead ;
		ListNode*pNode1 = l1->next, *pNode2 = l2->next;
		while (pNode1 != NULL && pNode2 != NULL) {
			temp = (pNode1->val + pNode2->val + carry);
			carry = temp / 10;
			pNode->next = new ListNode(temp % 10);
			pNode = pNode->next;
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		while (pNode1 != NULL) {
			temp = (pNode1->val + carry);
			carry = temp / 10;
			pNode->next = new ListNode(temp % 10);
			pNode = pNode->next;
			pNode1 = pNode1->next;
		}
		while (pNode2 != NULL) {
			temp = (pNode2->val + carry);
			carry = temp / 10;
			pNode->next = new ListNode(temp % 10);
			pNode = pNode->next;
			pNode1 = pNode2->next;
		}
		if (carry>0) {
			pNode = new ListNode(carry);
		}
		return resHead;
	}
};

int main() {
	ListNode* headNode1 = new ListNode(2);
	headNode1->next = new ListNode(4);
	headNode1->next->next = new ListNode(3);
	ListNode* headNode2 = new ListNode(5);
	headNode2->next = new ListNode(6);
	headNode2->next->next = new ListNode(4);
	Solution solution;
	ListNode* resHead = solution.addTwoNumbers(headNode1, headNode2);
	ListNode* pNode = resHead;
	while (pNode != NULL) {
		cout << pNode->val << endl;
		pNode = pNode->next;
	}
	return 0;
}