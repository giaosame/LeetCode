// 153. Find Minimum in Rotated Sorted Array
#include <vector>
using namespace std;

class Solution 
{
public:
	int findMin(vector<int>& nums) 
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			if (nums[left] < nums[right])
				break;

			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else right = mid;
		}

		return nums[left];
	}
};
