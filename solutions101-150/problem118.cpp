// 118. Pascal's Triangle
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> pascal;
		vector<int> level;

		for (int i = 0; i < numRows; i++)
		{
			level.push_back(1);
			for (int j = level.size() - 2; j > 0; j--)
			{
				level[j] = level[j] + level[j - 1];
			}

			pascal.push_back(level);
		}

		return pascal;
	}
};
