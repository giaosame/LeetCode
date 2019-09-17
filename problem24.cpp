// 24. Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
// You may not modify the values in the list's nodes, only nodes itself may be changed.
// 
// Definition for singly-linked list.
// struct ListNode {
//	 int val;
//	 ListNode *next;
//	 ListNode(int x) : val(x), next(NULL) {}
// };
#include "utils.h"
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* pre_head = new ListNode(0);
		ListNode* pre = pre_head;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while (cur && next)
		{
			ListNode* temp = next->next;
			pre->next = next;
			next->next = cur;
			cur->next = temp;
			pre = cur;
			cur = temp;
			if (cur)
				next = cur->next;
		}

		return pre_head->next;
	}
};