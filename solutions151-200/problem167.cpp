// 167. Two Sum II - Input array is sorted
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> two;
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int sum = nums[left] + nums[right];
			if (sum == target)
			{
				two.push_back(left + 1);
				two.push_back(right + 1);
				break;
			}
			else if (sum < target)
				left++;
			else
				right--;
		}

		return two;
	}
};
