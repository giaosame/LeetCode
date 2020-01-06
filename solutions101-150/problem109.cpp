// 109. Convert Sorted List to Binary Search Tree
#include "../utils.h"

// Uses iteration to locate the middle node in the list.
class Solution1
{
private:
	TreeNode* recurConvert(ListNode* node)
	{
		if (node == nullptr)
			return nullptr;
		if (node->next == nullptr)
			return new TreeNode(node->val);

		int n = 0;
		for (ListNode* temp = node; temp; temp = temp->next)
			n++;

		ListNode* pre = node;
		for (int i = 1; i < n / 2; i++)
			pre = pre->next;

		ListNode* center = pre->next;
		pre->next = nullptr;

		TreeNode* root = new TreeNode(center->val);
		root->left = recurConvert(node);
		root->right = recurConvert(center->next);
		return root;
	}

public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		return recurConvert(head);
	}
};


// A better solution:
// Uses 2 pointers, fast and slow, to locate the middle node in the list.
// Avoids half an iteration of the nodes in the list.
class Solution2
{
private:
	TreeNode* recurConvert(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return new TreeNode(head->val);

		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = nullptr;
		while (fast && fast->next)  // the key step
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		pre->next = nullptr;
		TreeNode* cur_tree = new TreeNode(slow->val);
		cur_tree->left = recurConvert(head);
		cur_tree->right = recurConvert(slow->next);

		return cur_tree;
	}

public:
	TreeNode* sortedListToBST(ListNode* head) 
	{
		return recurConvert(head);
	}
};
