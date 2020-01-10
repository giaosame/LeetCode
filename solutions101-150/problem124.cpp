// 124. Binary Tree Maximum Path Sum
#include <algorithm>
#include "../utils.h"
using namespace std;

class Solution
{
private:
	int recurMaxPathSum(TreeNode* node, int& sum)
	{
		if (!node)
			return 0;

		int left_sum = max(0, recurMaxPathSum(node->left, sum));
		int right_sum = max(0, recurMaxPathSum(node->right, sum));

		sum = max(sum, node->val + left_sum + right_sum);
		return node->val + max(left_sum, right_sum);
	}

public:
	int maxPathSum(TreeNode* root) {
		int max_sum = INT_MIN;
		recurMaxPathSum(root, max_sum);
		return max_sum;
	}
};
