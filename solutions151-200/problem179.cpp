// 179. Largest Number
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	string largestNumber(vector<int>& nums) 
	{
		vector<string> strs;
		for (int num : nums)
		{
			strs.push_back(to_string(num));
		}

		sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
			return s1 + s2 > s2 + s1;
		});

		string largest;
		for (string& str : strs)
		{
			largest += str;
		}

		return largest[0] != '0' ? largest : "0";
	}
};
