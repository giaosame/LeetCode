#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <stack>
#include <array>
using namespace std;

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int first_day = 5;
		int total_days = 0;
		for (int i = 1971; i < year; i++)
		{
			if ((i % 100 == 0 && i % 400 == 0) || (i % 100 != 0 && i % 4 == 0))
				total_days++;
			total_days += 365;
		}

		for (int i = 1; i < month; i++)
		{
			total_days += months[i - 1];
		}

		if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		{
			if (month > 2)
				total_days++;
			cout << "add Feb" << endl;
		}

		total_days += day;

		return days[(total_days + first_day - 1) % 7];
	}
};


int main()
{
	int numRows = 2;
	const string s = "123";
	vector<vector<char>> zigzag(numRows, vector<char>(s.size()));
	
 	Solution solution = Solution();
	cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
	
	system("pause");
	return 0;
}