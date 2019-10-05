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

struct Triangle
{
	// The indices of the Vertices that make up this triangle.
	// The indices correspond to the std::vector of Vertices stored in the Polygon
	// which stores this Triangle
	Triangle(unsigned int idx1, unsigned int idx2, unsigned int idx3)
		: m_indices{ idx1, idx2, idx3 }
	{}
	unsigned int m_indices[3];
};

int main()
{
	Triangle t(0, 2, 3);
	cout << t.m_indices[2] << " and " << t.m_indices[1];
	

	system("pause");
	return 0;
}


void test(int x, int y, string s, char b)
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "s = " << s << endl;
	cout << "b = " << b << endl;
}
