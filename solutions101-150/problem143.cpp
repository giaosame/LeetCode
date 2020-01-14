// 143. Reorder List
#include <stack>
#include <unordered_map>
#include "../utils.h"
using namespace std;

// Uses a unordered_map, pre_map, to record the previous node of a give node.
class Solution1
{
public:
	void reorderList(ListNode* head)
	{
		if (!head || !head->next)
			return;

		unordered_map<ListNode*, ListNode*> pre_map;
		ListNode* temp = head;
		int n = 1;
		while (temp->next)
		{
			pre_map[temp->next] = temp;
			temp = temp->next;
			n++;
		}
		// After the above loop, temp is the tail node of the linked list.
		
		ListNode* cur = head;
		for (int i = 0; i < n / 2; i++)
		{
			temp->next = cur->next;
			cur->next = temp;
			temp = pre_map[temp];
			cur = cur->next->next;
		}

		cur->next = nullptr;
	}
};


// A solution better than Solution1, replaces the map with a stack 
class Solution2
{
public:
	void reorderList(ListNode* head)
	{
		if (!head || !head->next)
			return;

		stack<ListNode*> stk;
		ListNode* temp = head;
		int n = 1;
		while (temp->next)
		{
			stk.push(temp);
			temp = temp->next;
			n++;
		}
		// After the above loop, temp is the tail node of the linked list.

		ListNode* cur = head;
		for (int i = 0; i < n / 2; i++)
		{
			temp->next = cur->next;
			cur->next = temp;
			cur = cur->next->next;
			temp = stk.top();
			stk.pop();
		}

		cur->next = nullptr;
	}
};


// The best solution:
class Solution3
{
public:
	void reorderList(ListNode* head) 
	{
		if (!head || !head->next)
			return;

		// 1. Searches the mid node of the linked list.
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		// 2. Makes the length of the first half of the linked list longer than the second half.
		//    Unlinks the first half and the second half from the mid node.
		ListNode* mid = slow;
		slow = slow->next;
		mid->next = nullptr;

		// 3. Reverses the second half of the linked list.
		ListNode* pre = nullptr;
		for (ListNode* cur = slow; cur; )
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		// 4. Merges the first half and the second half according to the requirement.
		//    Now, the pointer pre is the head of the second half.
		while (pre)
		{
			ListNode* next1 = head->next;
			ListNode* next2 = pre->next;
			head->next = pre;
			pre->next = next1;
			head = next1;
			pre = next2;
		}
	}
};
