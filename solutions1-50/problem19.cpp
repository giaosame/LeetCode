// 19. Remove Nth Node From End of List
// Given a linked list, remove the n-th node from the end of list and return its head.
// 
// Definition for singly-linked list:
// Define in the utils.h
// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
// };
#include "utils.h"

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * fast = head;
		ListNode * slow = head;

		for (int i = 0; i < n; i++)
			fast = fast->next;

		if (fast == nullptr)
			return head->next;

		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;
		return head;
	}
};