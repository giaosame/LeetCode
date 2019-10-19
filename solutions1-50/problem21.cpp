// 21. Merge Two Sorted Lists
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode pre_head(0);
		ListNode * pre = &pre_head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				pre->next = l1;
				l1 = l1->next;
			}
			else
			{
				pre->next = l2;
				l2 = l2->next;
			}

			pre = pre->next;
		}

		if (l1)
			pre->next = l1;
		if (l2)
			pre->next = l2;

		return pre_head.next;
	}
};