// 106. Construct Binary Tree from Inorder and Postorder Traversal
#include <vector>
#include <unordered_map>
#include "../utils.h"
using namespace std;

class Solution 
{
private:
	TreeNode* recurBuild(vector<int>& inorder, int in_start, int in_end, 
		                 vector<int>& postorder, int post_start, int post_end, 
		                 unordered_map<int, int>& map)
	{
		if (in_start > in_end || post_start > post_end)
			return nullptr;

		TreeNode* cur_tree = new TreeNode(postorder[post_end]);
		int idx = map[cur_tree->val];
		int left_tree_size = idx - in_start;

		cur_tree->left = recurBuild(inorder, in_start, idx - 1, postorder, post_start, post_start + left_tree_size - 1, map);
		cur_tree->right = recurBuild(inorder, idx + 1, in_end, postorder, post_start + left_tree_size, post_end - 1, map);
		return cur_tree;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
			return nullptr;

		unordered_map<int, int> map;
		int n = inorder.size();
		for (int i = 0; i < n; i++)
			map[inorder[i]] = i;

		return recurBuild(inorder, 0, n - 1, postorder, 0, n - 1, map);
	}
};
