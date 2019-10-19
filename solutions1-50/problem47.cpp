// 47. Permutations II
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	void recurPermute(vector<int>& nums, vector<vector<int>>& res, vector<int>& permutation, vector<bool>& visited)
	{
		if (permutation.size() == nums.size())
		{
			res.push_back(permutation);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i])
				continue;
			if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
				continue;

			visited[i] = true;
			permutation.push_back(nums[i]);
			recurPermute(nums, res, permutation, visited);
			permutation.pop_back();
			visited[i] = false;
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> permutation;
		vector<bool> visited(nums.size(), false);
		recurPermute(nums, res, permutation, visited);
		return res;
	}
};