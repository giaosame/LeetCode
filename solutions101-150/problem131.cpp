// 131. Palindrome Partitioning
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
	bool isPalindrome(string& s, int left, int right)
	{
		while (left < right)
		{
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}

	void recurPartition(vector<vector<string>>& parts, vector<string>& cur_part, string& s, int start)
	{
		if (start == s.size())
		{
			parts.push_back(cur_part);
			return;
		}

		for (int i = start; i < s.size(); i++)
		{
			if (isPalindrome(s, start, i))
			{
				cur_part.push_back(s.substr(start, i - start + 1));
				recurPartition(parts, cur_part, s, i + 1);
				cur_part.pop_back();
			}
		}
	}

public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> parts;
		vector<string> cur_part;
		recurPartition(parts, cur_part, s, 0);
		return parts;
	}
};
