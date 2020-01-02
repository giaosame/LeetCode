// 93. Restore IP Addresses
#include <string>
#include <vector>
using namespace std;

class Solution 
{
private:
	bool isValid(string s)
	{
		if (s.empty() || s.size() > 3 || stoi(s) > 255 || (s[0] == '0' && s.size() > 1))
			return false;
		return true;
	}

public:
	vector<string> restoreIpAddresses(string s) 
	{
		vector<string> ips;
		if (s.size() < 4 || s.size() > 12)
			return ips;

		int n = s.size();
		for (int i = 1; i <= 3 && i < n; i++)
		{
			for (int j = 1; j <= 3 && i + j < n; j++)
			{
				for (int k = 1; k <= 3 && i + j + k < n; k++)
				{
					string part1 = s.substr(0, i);
					string part2 = s.substr(i, j);
					string part3 = s.substr(i + j, k);
					string part4 = s.substr(i + j + k);

					if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4))
					{
						ips.push_back(part1 + '.' + part2 + '.' + part3 + '.' + part4);
					}
				}
			}
		}

		return ips;
	}
};
