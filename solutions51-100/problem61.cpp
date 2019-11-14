// 61. Rotate List
#include "../utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr)
			return head;

		int n = 0;
		for (ListNode* temp = head; temp; temp = temp->next)
			n++;

		k %= n;
		if (k == 0 || n == 1)
			return head;

		ListNode* pre = head;
		for (int i = 0; i < n - k - 1; i++)
			pre = pre->next;

		ListNode* new_head = pre->next;
		pre->next = nullptr;
		for (ListNode* temp = new_head; temp; temp = temp->next)
		{
			if (temp->next == nullptr)
			{
				temp->next = head;
				break;
			}
		}

		return new_head;
	}
};