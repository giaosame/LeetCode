// 139. Word Break
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool wordBreak(string s, vector<string>& word_dict)
	{
		unordered_set<string> words(word_dict.begin(), word_dict.end());
		int n = s.size();
		vector<bool> dp(n + 1);
		dp[0] = true;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] && words.find(s.substr(j, i - j)) != words.end())
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n];
	}
};
