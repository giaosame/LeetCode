#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> merged_interval;
		if (intervals.size() == 0)
			return merged_interval;

		sort(intervals.begin(), intervals.end());
		merged_interval.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (merged_interval.back()[1] >= intervals[i][0])
				merged_interval.back()[1] = max(merged_interval.back()[1], intervals[i][1]);
			else
				merged_interval.push_back(intervals[i]);
		}

		return merged_interval;
	}
};