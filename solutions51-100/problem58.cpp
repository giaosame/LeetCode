// 58. Length of Last Word
#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i = s.size() - 1;
		int len = 0;
		for (; i >= 0 && s[i] == ' '; i--);
		for (; i >= 0 && s[i] != ' '; i--) len++;
		return len;
	}
};