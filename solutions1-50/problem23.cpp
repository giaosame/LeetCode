// 23. Merge k Sorted Lists
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Definition for singly-linked list.
// struct ListNode {
//	   int val;
//	   ListNode *next;
//	   ListNode(int x) : val(x), next(nullptr) {}
// };
#include <queue>
#include <vector>
#include "utils.h"
using namespace std;

struct Compare
{
	bool operator()(const ListNode* l1, const ListNode* l2)
	{
		return l1->val > l2->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
		for (ListNode* list : lists)
		{
			if (list)
				pq.push(list);
		}

		ListNode* pre_head = new ListNode(0);
		ListNode* pre = pre_head;
		while (!pq.empty())
		{
			ListNode* temp = pq.top();
			pq.pop();

			pre->next = temp;
			pre = pre->next;
			if (temp->next)
				pq.push(temp->next);
		}

		return pre_head->next;
	}
};
