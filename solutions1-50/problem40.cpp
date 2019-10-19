// 40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	void recurCombinate(vector<int>& candidates, vector<vector<int>>& combinations,
		                vector<int>& cur_combination, int target, int start)
	{
		if (target < 0)
			return;
		if (target == 0)
		{
			combinations.push_back(cur_combination);
			return;
		}

		for (int i = start; i < candidates.size(); i++)
		{
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			cur_combination.push_back(candidates[i]);
			recurCombinate(candidates, combinations, cur_combination, target - candidates[i], i + 1);
			cur_combination.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> combinations;
		vector<int> cur_combination;
		recurCombinate(candidates, combinations, cur_combination, target, 0);
		return combinations;
	}
};
