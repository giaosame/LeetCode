// 80. Remove Duplicates from Sorted Array II
#include <vector>
using namespace std;

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int idx = 0;
		for (int num : nums)
		{
			if (idx < 2 || num > nums[idx - 2])
				nums[idx++] = num;
		}

		return idx;
	}
};