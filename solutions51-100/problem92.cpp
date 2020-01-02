// 92. Reverse Linked List II
#include "../utils.h"

class Solution
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		ListNode* pre_head = new ListNode(0);
		ListNode* pre = pre_head;
		pre->next = head;

		for (int i = 0; i < m - 1; i++)
			pre = pre->next;

		ListNode* front_tail = pre;
		ListNode* rev_tail = pre->next;
		ListNode* cur = rev_tail;

		for (int i = m; i <= n; i++)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		front_tail->next = pre;
		rev_tail->next = cur;
		return pre_head->next;
	}
};
