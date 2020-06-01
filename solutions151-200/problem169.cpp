// 169. Majority Element
#include <vector>
using namespace std;	

// O(n) method according to Moore Voting Algorithm
class Solution1 
{
public:
	int majorityElement(vector<int>& nums)
	{
		int major = nums[0];
		int cnt = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (cnt == 0)
				major = nums[i];

			if (nums[i] == major)
				cnt++;
			else
				cnt--;
		}

		return major;
	}
};

// Divide and Conquer
class Solution2 
{
private:
	int getMajor(vector<int>& nums, int l, int r)
	{
		if (l == r)
			return nums[l];

		int m = l + (r - l) / 2;
		int left_major = getMajor(nums, l, m);
		int right_major = getMajor(nums, m + 1, r);

		if (left_major == right_major)
			return left_major;

		int left_cnt = 0, right_cnt = 0;
		for (int i = l; i <= r; i++)
		{
			if (nums[i] == left_major)
				left_cnt++;
			else if (nums[i] == right_major)
				right_cnt++;
		}

		return left_cnt > right_cnt ? left_major : right_major;
	}

public:
	int majorityElement(vector<int>& nums)
	{
		return getMajor(nums, 0, nums.size() - 1);
	}
};
