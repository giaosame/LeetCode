// 110. Balanced Binary Tree
#include <algorithm>
#include <cmath>
#include "../utils.h"
using namespace std;

class Solution1
{
private:
	int recurBalance(TreeNode* node, int depth)
	{
		if (!node)
			return depth;

		int left_depth = recurBalance(node->left, depth + 1);
		int right_depth = recurBalance(node->right, depth + 1);

		if (left_depth == -1 || right_depth == -1)
			return -1;

		if (abs(left_depth - right_depth) > 1)
			return -1;
		else
			return max(left_depth, right_depth);

	}

public:
	bool isBalanced(TreeNode* root)
	{
		if (!root)
			return true;

		return recurBalance(root, 0) != -1;
	}
};


// A more consise recursive solution:
class Solution2
{
private:
	int getDepth(TreeNode* node)
	{
		if (!node)
			return 0;
		return 1 + max(getDepth(node->left), getDepth(node->right));
	}

public:
	bool isBalanced(TreeNode* root) 
	{
		if (!root)
			return true;

		int left_depth = getDepth(root->left);
		int right_depth = getDepth(root->right);
		return abs(left_depth - right_depth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};
