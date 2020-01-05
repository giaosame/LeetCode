// 105. Construct Binary Tree from Preorder and Inorder Traversal
#include <vector>
#include <unordered_map>
#include "../utils.h"
using namespace std;

class Solution 
{
private:
	TreeNode* recurBuild(vector<int>& preorder, int pre_start, int pre_end, 
		                 vector<int>& inorder, int in_start, int in_end, 
		                 unordered_map<int, int>& map)
	{
		if (pre_start > pre_end || in_start > in_end)
			return nullptr;

		TreeNode* cur_root = new TreeNode(preorder[pre_start]);
		int idx = map[cur_root->val];
		int left_tree_size = idx - in_start;

		cur_root->left = recurBuild(preorder, pre_start + 1, pre_start + left_tree_size, inorder, in_start, idx - 1, map);
		cur_root->right = recurBuild(preorder, pre_start + left_tree_size + 1, pre_end, inorder, idx + 1, in_end, map);
		return cur_root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
			return nullptr;

		unordered_map<int, int> map;
		int n = inorder.size();
		for (int i = 0; i < n; i++)
			map[inorder[i]] = i;

		return recurBuild(preorder, 0, n - 1, inorder, 0, n - 1, map);
	}
};
