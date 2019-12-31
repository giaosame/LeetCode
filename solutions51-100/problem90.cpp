// 90. Subsets II
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
private:
	void recurSet(vector<vector<int>>& sets, vector<int>& cur_set, vector<int>& nums, int start)
	{
		sets.push_back(cur_set);
		for (int i = start; i < nums.size(); i++)
		{
			if (i > start && nums[i] == nums[i - 1])
				continue;

			cur_set.push_back(nums[i]);
			recurSet(sets, cur_set, nums, i + 1);
			cur_set.pop_back();
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> sets;
		vector<int> cur_set;
		recurSet(sets, cur_set, nums, 0);
		return sets;
	}
};
