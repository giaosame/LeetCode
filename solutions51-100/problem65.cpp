// 65. Valid Number
#include <string>
using namespace std;

const static string WHITESPACE = " \n\r\t\f\v";

class Solution {
private:
	void trim(string& s)
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		if (start != string::npos)
			s = s.substr(start);

		size_t end = s.find_last_not_of(WHITESPACE);
		if (end != string::npos)
			s = s.substr(0, end + 1);
	}

public:
	bool isNumber(string s) {
		trim(s);

		bool point_seen = false;
		bool e_seen = false;
		bool num_seen = false;
		bool num_after_e = true;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num_seen = true;
				num_after_e = true;
			}
			else if (s[i] == '.')
			{
				if (e_seen || point_seen)
					return false;
				point_seen = true;
			}
			else if (s[i] == 'e')
			{
				if (e_seen || !num_seen)
					return false;
				num_after_e = false;
				e_seen = true;
			}
			else if (s[i] == '-' || s[i] == '+')
			{
				if (i != 0 && s[i - 1] != 'e')
					return false;
			}
			else
			{
				return false;
			}
		}

		return num_seen && num_after_e;
	}
};