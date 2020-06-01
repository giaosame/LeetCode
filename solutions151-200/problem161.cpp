// 161. One Edit Distance
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	/**
	 * @param s: a string
	 * @param t: a string
	 * @return: true if they are both one edit distance apart or false
	 */
	bool isOneEditDistance(string& s, string& t)
	{
		// write your code here
		int m = s.size();
		int n = t.size();
		if (abs(m - n) > 1)
			return false;

		for (int i = 0; i < min(m, n); i++)
		{
			if (s[i] != t[i])
			{
				if (m < n)
					return s.substr(i) == t.substr(i + 1);
				else if (m > n)
					return s.substr(i + 1) == t.substr(i);
				return s.substr(i + 1) == t.substr(i + 1);
			}
		}

		return s != t;
	}
};
