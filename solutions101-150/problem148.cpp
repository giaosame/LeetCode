// 148. Sort List
#include "../utils.h"

class Solution
{
private:
	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode* pre_head = new ListNode(0);
		ListNode* pre = pre_head;

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

		return pre_head->next;
	}

public:
	ListNode* sortList(ListNode* head) 
	{
		if (!head || !head->next)
			return head;

		ListNode* pre = nullptr;
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr;

		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(slow);

		return merge(l1, l2);
	}
};
