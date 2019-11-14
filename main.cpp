#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <stack>
#include <array>
#include <unordered_map>
using namespace std;

void test(int x = 0, int y = 1, string s = "123", char b = 'b');

class Base
{
	int val;
};

class Derive : public Base
{
public:
	void test()
	{
		cout << "Derived member function" << endl;
	}
};

int missingNumber(vector<int>& arr) {
	if (arr.size() == 2)
		return ((arr[0] + arr[1]) / 2);

	int gap;
	if (arr[0] > arr[1])
	{
		gap = min(arr[0] - arr[1], arr[arr.size() - 2] - arr[arr.size() - 1]);
		for (int i = 0; i < arr.size() - 1; i++)
		{
			if (arr[i] - arr[i + 1] != gap)
				return arr[i] - gap;
		}
	}
	else
	{
		gap = min(arr[1] - arr[0], arr[arr.size() - 1] - arr[arr.size() - 2]);
		for (int i = 0; i < arr.size - 1; i++)
		{
			if (arr[i + 1] - arr[i] != gap)
				return arr[i] + gap;
		}
	}
	
	return 0;
}

void get4MaxWeightsAndIds(unordered_map<int, float> influence_map)
{
	float max1 = 0.f;
	float max2 = 0.f;
	float max3 = 0.f;
	float max4 = 0.f;

	int id1 = -1;
	int id2 = -1;
	int id3 = -1;
	int id4 = -1;

	for (std::unordered_map<int, float>::iterator it = influence_map.begin(); it != influence_map.end(); it++)
	{
		float weight = it->second;
		int id = it->first;
		if (weight > max1)
		{
			max4 = max3;
			max3 = max2;
			max2 = max1;
			max1 = weight;

			id4 = id3;
			id3 = id2;
			id2 = id1;
			id1 = id;
		}
		else if (weight > max2)
		{
			max4 = max3;
			max3 = max2;
			max2 = weight;

			id4 = id3;
			id3 = id2;
			id2 = id;
		}
		else if (weight > max3)
		{
			max4 = max3;
			max3 = weight;

			id4 = id3;
			id3 = id;
		}
		else if (weight > max4)
		{
			max4 = weight;
			id4 = id;
		}
	}

	cout << "max1: id = " << id1 << ", val = " << max1;
	cout << "max2: id = " << id2 << ", val = " << max2;
	cout << "max3: id = " << id3 << ", val = " << max3;
	cout << "max4: id = " << id4 << ", val = " << max4;
}

int main()
{
	vector<int> v = { 5,7,11,13 };
	cout << missingNumber(v);

	unordered_map<int, float> map;
	map[1] = 100.f;
	map[0] = 50.f;
	map[3] = 1000.f;
	map[4] = 2.f;
	map[5] = 7.f;

	get4MaxWeightsAndIds(map);

	system("pause");
	return 0;
}
