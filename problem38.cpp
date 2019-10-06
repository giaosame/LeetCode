// 38. Count and Say
// The count-and-say sequence is the sequence of integers with the first five terms as following:
//		1.     1
//		2.     11
//		3.     21
//		4.     1211
//		5.     111221
// Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.
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