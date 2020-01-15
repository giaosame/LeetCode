// 149. Max Points on a Line
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
private:
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

public:
	int maxPoints(vector<vector<int>>& points) 
	{
		int max_points = 0;
		for (int i = 0; i < points.size(); i++)
		{
			unordered_map<string, int> slope_map;
			int same_points = 0;
			int line_points = 0;
			for (int j = i + 1; j < points.size(); j++)
			{
				int dx = points[i][0] - points[j][0];
				int dy = points[i][1] - points[j][1];

				if (dx == 0 && dy == 0)
				{
					same_points++;
					continue;
				}

				int divisor = gcd(dx, dy);
				dx /= divisor;
				dy /= divisor;

				string slope = to_string(dx) + '/' + to_string(dy);
				int cnt = ++slope_map[slope];
				line_points = max(line_points, cnt);
			}

			max_points = max(max_points, 1 + same_points + line_points);
		}

		return max_points;
	}
};
