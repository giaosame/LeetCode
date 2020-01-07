#ifndef UTILS_H_
#define UTILS_H_

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() 
		: val(0), left(nullptr), right(nullptr), next(nullptr) 
	{}

	Node(int _val) 
		: val(_val), left(nullptr), right(nullptr), next(nullptr)
	{}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) 
	{}
};

#endif // !UTILS_H_
