// 38. Count and Say
#include <string>
using namespace std;

class Solution {
private:
	string nextSay(string say, int n)
	{
		if (n == 1)
			return say;

		string new_say;
		int cnt = 1;
		for (int i = 0; i < say.size() - 1; i++)
		{
			if (say[i] == say[i + 1])
				cnt++;
			else
			{
				new_say += to_string(cnt) + say[i];
				cnt = 1;
			}
		}

		new_say += to_string(cnt) + say.back();
		return nextSay(new_say, n - 1);
	}

public:
	string countAndSay(int n) {
		return nextSay("1", n);
	}
};