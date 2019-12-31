// 87. Scramble String
#include <string>
using namespace std;

class Solution 
{
public:
	bool isScramble(string s1, string s2) 
	{
		if (s1 == s2)
			return true;
		if (s1.size() != s2.size())
			return false;

		int letters[26] = { 0 };
		int n = s1.size();
		for (int i = 0; i < n; i++)
		{
			letters[s1[i] - 'a']++;
			letters[s2[i] - 'a']--;
		}
		for (int letter : letters)
		{
			if (letter != 0)
				return false;
		}

		for (int i = 1; i < n; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
				return true;
		}

		return false;
	}
};
