// 163. Missing Ranges
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	/*
	 * @param nums: a sorted integer array
	 * @param lower: An integer
	 * @param upper: An integer
	 * @return: a list of its missing ranges
	 */
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
	{
		vector<string> missing_ranges;
		long cur = lower;
		for (int num : nums)
		{
			if (num < cur)
				continue;
			if (num == cur)
			{
				cur++;
				continue;
			}

			string range = num - cur == 1 ? to_string(cur) : to_string(cur) + "->" + to_string(num - 1);
			missing_ranges.push_back(range);
			cur = long(num) + 1;
		}

		if (cur <= upper)
		{
			string range = upper == cur ? to_string(cur) : to_string(cur) + "->" + to_string(upper);
			missing_ranges.push_back(range);
		}

		return missing_ranges;
	}
};
