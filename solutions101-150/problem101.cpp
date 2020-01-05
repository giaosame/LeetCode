// 101. Symmetric Tree
#include "../utils.h"

class Solution 
{
private:
	bool recurSymmetry(TreeNode* left, TreeNode* right)
	{
		if (!left && !right)
			return true;
		if (!left || !right)
			return false;
		return left->val == right->val && recurSymmetry(left->left, right->right) && recurSymmetry(left->right, right->left);
	}

public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;

		return recurSymmetry(root->left, root->right);
	}
};