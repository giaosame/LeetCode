// 82. Remove Duplicates from Sorted List II
#include "../utils.h"

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pre_head = new ListNode(0);
		ListNode* pre = pre_head;
		pre->next = head;

		for (ListNode* temp = head; temp; temp = temp->next)
		{
			while (temp->next && temp->val == temp->next->val)
				temp = temp->next;

			if (pre->next == temp)
				pre = temp;
			else
				pre->next = temp->next;
		}

		return pre_head->next;
	}
};