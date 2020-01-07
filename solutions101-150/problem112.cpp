// 112. Path Sum
#include "../utils.h"

class Solution 
{
public:
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (!root)
			return false;

		sum -= root->val;
		if (!root->left && !root->right && sum == 0)
			return true;

		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}
};
