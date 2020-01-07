// 114. Flatten Binary Tree to Linked List
#include "../utils.h"

class Solution1
{
	TreeNode* recurFlatten(TreeNode* node)
	{
		if (!node)
			return nullptr;
		if (!node->left && !node->right)
			return node;

		TreeNode* left = recurFlatten(node->left);
		TreeNode* right = recurFlatten(node->right);
		node->left = nullptr;
		node->right = left;

		if (!left)
			node->right = right;
		else
		{
			while (left)
			{
				if (left->right)
					left = left->right;
				else
				{
					left->right = right;
					break;
				}
			}
		}

		return node;
	}

public:
	void flatten(TreeNode* root)
	{
		recurFlatten(root);
	}
};


// A better and more consise solution:
class Solution 
{
private:
	TreeNode* pre = nullptr;

public:
	void flatten(TreeNode* root)
	{
		if (!root)
			return;

		flatten(root->right);
		flatten(root->left);
		root->right = pre;
		root->left = nullptr;
		pre = root;
	}
};
