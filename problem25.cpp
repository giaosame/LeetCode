// 25. Reverse Nodes in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
// 
// Definition for singly-linked list.
// struct ListNode {
//	 int val;
//	 ListNode *next;
//	 ListNode(int x) : val(x), next(NULL) {}
// };
#include "utils.h"

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