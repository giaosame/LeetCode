// 25. Reverse Nodes in k-Group
#include "../utils.h"

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)
			return head;

		int cnt = 0;
		ListNode* cur = head;
		while (cur && cnt < k)
		{
			cur = cur->next;
			cnt++;
		}

		if (cnt == k)
		{
			cur = reverseKGroup(cur, k);
			while (cnt > 0)
			{
				ListNode* next = head->next;
				head->next = cur;
				cur = head;
				head = next;
				cnt--;
			}
			head = cur;
		}

		return head;
	}
};