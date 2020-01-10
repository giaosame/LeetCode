// 122. Best Time to Buy and Sell Stock II
#include <vector>
using namespace std;

// Peak Valley approach: 
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
			return 0;

		int max_profit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				max_profit += prices[i] - prices[i - 1];
		}

		return max_profit;
	}
};
