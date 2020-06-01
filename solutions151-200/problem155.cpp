// 155. Min Stack
#include <stack>
using namespace std;

class MinStack
{
	stack<int> stk;
	int min = INT_MAX;

public:
	MinStack() {}

	void push(int x) 
	{
		if (x <= min)
		{
			stk.push(min);
			min = x;
		}
		stk.push(x);
	}

	void pop()
	{
		if (stk.top() == min)
		{
			stk.pop();
			min = stk.top();
		}
		stk.pop();
	}

	int top() 
	{
		return stk.top();
	}

	int getMin()
	{
		return min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */