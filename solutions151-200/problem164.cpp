// 164. Maximum Gap
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int maximumGap(vector<int>& nums) 
	{
		int n = nums.size();
		if (n < 2)
			return 0;

		int maximum = INT_MIN;
		int minimum = INT_MAX;
		for (int num : nums)
		{
			maximum = max(maximum, num);
			minimum = min(minimum, num);
		}

		int gap = ceil(double(maximum - minimum) / (n - 1));
		vector<int> max_buckets(n - 1, INT_MIN);
		vector<int> min_buckets(n - 1, INT_MAX);
		for (int num : nums)
		{
			if (num == maximum || num == minimum)
				continue;

			int idx = (num - minimum) / gap;
			max_buckets[idx] = max(max_buckets[idx], num);
			min_buckets[idx] = min(min_buckets[idx], num);
		}

		int max_gap = 0;
		int pre = minimum;
		for (int i = 0; i < n - 1; i++)
		{
			if (max_buckets[i] == INT_MIN && min_buckets[i] == INT_MAX)
				continue;

			max_gap = max(max_gap, min_buckets[i] - pre);
			pre = max_buckets[i];
		}

		max_gap = max(max_gap, maximum - pre);
		return max_gap;
	}
};
