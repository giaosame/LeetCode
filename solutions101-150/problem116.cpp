// 116. Populating Next Right Pointers in Each Node
#include "../utils.h"

// A recursive method:
class Solution1
{
private:
	void recurConnect(Node* node)
	{
		if (node->left)
		{
			node->left->next = node->right;
			if (node->next)
			{
				node->right->next = node->next->left;
			}

			recurConnect(node->left);
			recurConnect(node->right);
		}
	}

public:
	Node* connect(Node* root) {
		if (root)
			recurConnect(root);
		return root;
	}
};


// An iterative method:
class Solution2
{
public:
	Node* connect(Node* root) 
	{
		if (!root)
			return root;

		Node* cur = root;
		while (cur->left)
		{
			Node* temp = cur;
			while (temp)
			{
				temp->left->next = temp->right;
				if (temp->next)
					temp->right->next = temp->next->left;

				temp = temp->next;
			}

			cur = cur->left;
		}

		return root;
	}
};
