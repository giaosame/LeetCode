// 136. Single Number
#include <vector>
using namespace std;

// Bitwise method:
class Solution 
{
public:
	int singleNumber(vector<int>& nums)
	{
		int res = 0;
		for (int num : nums)
			res ^= num;
		return res;
	}
};
