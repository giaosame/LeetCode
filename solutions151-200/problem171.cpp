// 171. Excel Sheet Column Number
#include <string>
using namespace std;

class Solution 
{
public:
	int titleToNumber(string s) 
	{
		int num = 0;
		for (char c : s)
		{
			num = 26 * num + (c - 'A' + 1);
		}

		return num;
	}
};
