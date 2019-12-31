// 89. Gray Code
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> code = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = code.size() - 1; j >= 0; j--)
				code.push_back(code[j] + (1 << i));
		}

		return code;
	}
};
