// 98. Validate Binary Search Tree
#include <stack>
#include "../utils.h"
using namespace std;

// Recursion
class Solution1
{
private:
	bool recurValidate(TreeNode* node, TreeNode* min_node, TreeNode* max_node)
	{
		if (node == nullptr)
			return true;
		if (min_node && min_node->val >= node->val)
			return false;
		if (max_node && max_node->val <= node->val)
			return false;

		return recurValidate(node->left, min_node, node) && recurValidate(node->right, node, max_node);
	}

public:
	bool isValidBST(TreeNode* root)
	{
		return recurValidate(root, nullptr, nullptr);
	}
};


// Uses stack to do the inorder traversal
// To find whether there exists an adjacent pair which the previous val larger than the latter one
// If no then it is a valid BST
class Solution2
{
public:
	bool isValidBST(TreeNode* root)
	{
		if (!root)
			return true;

		TreeNode* pre = nullptr;
		TreeNode* cur = root;
		stack<TreeNode*> stk;
		while (!stk.empty() || cur)
		{
			while (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}

			cur = stk.top();
			stk.pop();
			if (pre && pre->val >= cur->val)
				return false;

			pre = cur;
			cur = cur->right;
		}

		return true;
	}
};
