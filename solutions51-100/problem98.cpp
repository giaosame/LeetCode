// 98. Validate Binary Search Tree
#include "../utils.h"
using namespace std;

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
