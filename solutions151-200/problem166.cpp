// 166. Fraction to Recurring Decimal
#include <string>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
	string fractionToDecimal(int numerator, int denominator) 
	{
		if (numerator == 0)
			return "0";

		string res;
		if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
			res += "-";

		long n = labs(numerator);
		long d = labs(denominator);
		res += to_string(n / d);
		n %= d;
		if (n == 0)
			return res;

		res += '.';
		unordered_map<long, int> map = { {n, res.size()} };
		while (n != 0)
		{
			n *= 10;
			res += to_string(n / d);
			n %= d;

			if (map.find(n) != map.end())
			{
				res.insert(map[n], "(");
				res += ")";
				break;
			}
			map[n] = res.size();
		}

		return res;
	}
};
