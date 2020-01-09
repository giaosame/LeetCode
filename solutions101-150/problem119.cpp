// 119. Pascal's Triangle II
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> getRow(int rowIndex) 
	{
		vector<int> level;
		for (int i = 0; i <= rowIndex; i++)
		{
			level.push_back(1);
			for (int j = level.size() - 2; j > 0; j--)
			{
				level[j] = level[j] + level[j - 1];
			}
		}

		return level;
	}
};
