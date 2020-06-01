// 156. Binary Tree Upside Down
#include "../utils.h"

class Solution 
{
public:
	/**
	 * @param root: the root of binary tree
	 * @return: new root
	 */
	TreeNode* upsideDownBinaryTree(TreeNode* root) 
	{
		if (!root || !root->left)
			return root;

		TreeNode* new_root = upsideDownBinaryTree(root->left);
		root->left->left = root->right;
		root->left->right = root;
		root->left = nullptr;
		root->right = nullptr;
		return new_root;
	}
};
