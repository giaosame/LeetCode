// 165. Compare Version Numbers
#include <string>
using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int m = version1.size();
		int n = version2.size();

		for (int i = 0, j = 0; i < m || j < n; i++, j++)
		{
			int num1 = 0;
			int num2 = 0;
			while (i < m && version1[i] != '.')
			{
				num1 = 10 * num1 + (version1[i] - '0');
				i++;
			}
			while (j < n && version2[j] != '.')
			{
				num2 = 10 * num2 + (version2[j] - '0');
				j++;
			}

			if (num1 < num2)
				return -1;
			if (num1 > num2)
				return 1;
		}

		return 0;
	}
};
