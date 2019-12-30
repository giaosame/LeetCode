// 83. Remove Duplicates from Sorted List
#include "../utils.h"

class Solution 
{
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		for (ListNode* temp = head; temp; temp = temp->next)
		{
			while (temp->next && temp->val == temp->next->val)
				temp->next = temp->next->next;
		}
		return head;
	}
};