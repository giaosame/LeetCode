// 104. Maximum Depth of Binary Tree
#include <algorithm>
#include "../utils.h"
using namespace std;

class Solution1
{
private:
	void dfs(TreeNode* node, int& max_depth, int depth)
	{
		if (!node)
		{
			max_depth = max(max_depth, depth);
			return;
		}

		dfs(node->left, max_depth, depth + 1);
		dfs(node->right, max_depth, depth + 1);
	}

public:
	int maxDepth(TreeNode* root) 
	{
		int max_depth = 0;
		dfs(root, max_depth, 0);
		return max_depth;
	}
};
