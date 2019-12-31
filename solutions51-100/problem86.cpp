// 86. Partition List
#include "../utils.h"

class Solution 
{
public:
	ListNode* partition(ListNode* head, int x) 
	{
		ListNode* small_head = new ListNode(0);
		ListNode* small = small_head;
		ListNode* large_head = new ListNode(0);
		ListNode* large = large_head;

		for (ListNode* temp = head; temp; temp = temp->next)
		{
			if (temp->val < x)
			{
				small->next = temp;
				small = small->next;
			}
			else
			{
				large->next = temp;
				large = large->next;
			}
		}

		small->next = large_head->next;
		large->next = nullptr;
		return small_head->next;
	}
};
