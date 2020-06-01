// 168. Excel Sheet Column Title
#include <string>
using namespace std;

class Solution 
{
public:
	string convertToTitle(int n) 
	{
		if (n <= 0)
			return "";

		string col;
		while (n > 0)
		{
			n--;
			col = char('A' + n % 26) + col;
			n /= 26;
		}

		return col;
	}
};
