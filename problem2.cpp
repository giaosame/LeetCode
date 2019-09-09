// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode pre_head = ListNode(0);
        ListNode * temp = &pre_head;
        int plus = 0;
        while (l1 || l2)
        {
            if (l1)
            {
                plus += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                plus += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(plus % 10);
            temp = temp->next;
            plus /= 10;
        }
        
        if (plus != 0)
            temp->next = new ListNode(plus);
        return pre_head.next;
	}
};