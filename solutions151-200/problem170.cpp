// 170. Two Sum III - Data structure design
#include <unordered_map>
using namespace std;

class TwoSum {
	unordered_map<int, int> map;
public:
	/**
	 * @param number: An integer
	 * @return: nothing
	 */
	void add(int number) {
		// write your code here
		map[number]++;
	}

	/**
	 * @param value: An integer
	 * @return: Find if there exists any pair of numbers which sum is equal to the value.
	 */
	bool find(int value) {
		// write your code here
		for (auto e : map)
		{
			int complement = value - e.first;
			if (complement == e.first)
			{
				if (e.second > 1)
					return true;
			}
			else if (map.find(complement) != map.end())
				return true;
		}

		return false;
	}
};
