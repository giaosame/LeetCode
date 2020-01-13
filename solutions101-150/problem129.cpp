// 129. Sum Root to Leaf Numbers
#include "../utils.h"

class Solution
{
private:
	int recurSum(TreeNode* node, int sum)
	{
		if (!node)
			return 0;

		sum = 10 * sum + node->val;
		if (!node->left && !node->right)
			return sum;

		int left_sum = recurSum(node->left, sum);
		int right_sum = recurSum(node->right, sum);
		return left_sum + right_sum;
	}

public:
	int sumNumbers(TreeNode* root)
	{
		return recurSum(root, 0);
	}
};
