// 113. Path Sum II
#include <vector>
#include "../utils.h"
using namespace std;

class Solution 
{
	void recurPathSum(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int>& cur_path)
	{
		if (!root)
			return;

		cur_path.push_back(root->val);
		sum -= root->val;
		if (!root->left && !root->right && sum == 0)
		{
			paths.push_back(cur_path);
		}
		else
		{
			recurPathSum(root->left, sum, paths, cur_path);
			recurPathSum(root->right, sum, paths, cur_path);
		}

		cur_path.pop_back();
	}

public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) 
	{
		vector<vector<int>> paths;
		vector<int> cur_path;
		recurPathSum(root, sum, paths, cur_path);
		return paths;
	}
};
