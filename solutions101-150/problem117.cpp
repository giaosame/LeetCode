// 117. Populating Next Right Pointers in Each Node II
#include "../utils.h"

class Solution
{
public:
	Node* connect(Node* root) 
	{
		Node* cur = root;      // the currently visited node
		Node* head = nullptr;  // the leftmost node of the next level
		Node* pre = nullptr;   // the previous node of cur's children

		while (cur)
		{
			while (cur)  // iterates in the current level
			{
				if (cur->left)
				{
					if (pre)
						pre->next = cur->left;
					else
						head = cur->left;
					pre = cur->left;
				}
				if (cur->right)
				{
					if (pre)
						pre->next = cur->right;
					else
						head = cur->right;
					pre = cur->right;
				}

				cur = cur->next; 
			}

			cur = head;  // jumps to the next level's leftmost node
			head = nullptr;
			pre = nullptr;
		}

		return root;
	}
};
