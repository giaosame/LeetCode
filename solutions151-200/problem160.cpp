// 160. Intersection of Two Linked Lists
#include "../utils.h"

class Solution
{
public:
	ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b)
	{
		ListNode* pa = head_a;
		ListNode* pb = head_b;

		while (pa != pb)
		{
			if (pa)
				pa = pa->next;
			else
				pa = head_b;

			if (pb)
				pb = pb->next;
			else
				pb = head_a;
		}

		return pa;
	}
};
