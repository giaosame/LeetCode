// 123. Best Time to Buy and Sell Stock III
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
	{
		int first_buy = INT_MAX;
		int second_buy = INT_MAX;
		int first_sell = 0;
		int second_sell = 0;

		for (int i = 0; i < prices.size(); i++)
		{
			first_buy = min(first_buy, prices[i]);
			first_sell = max(first_sell, prices[i] - first_buy);
			second_buy = min(second_buy, prices[i] - first_sell);
			second_sell = max(second_sell, prices[i] - second_buy);
		}

		return second_sell;
	}
};
