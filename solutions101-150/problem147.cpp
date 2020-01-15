// 147. Insertion Sort List
#include <climits>
#include "../utils.h"

class Solution
{
public:
	ListNode* insertionSortList(ListNode* head)
	{
		if (!head || !head->next)
			return head;

		ListNode* pre_head = new ListNode(INT_MIN);
		ListNode* pre = pre_head;
		ListNode* cur = head;

		while (cur)
		{
			ListNode* next = cur->next;
			while (pre->next && pre->next->val < cur->val)
				pre = pre->next;

			cur->next = pre->next;
			pre->next = cur;
			pre = pre_head;
			cur = next;
		}

		return pre_head->next;
	}
};
