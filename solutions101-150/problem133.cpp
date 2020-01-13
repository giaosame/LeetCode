// 133. Clone Graph
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution 
{
private:
	Node* recurClone(Node* node, unordered_map<int, Node*>& map)
	{
		if (map.find(node->val) != map.end())
			return map[node->val];

		Node* clone = new Node(node->val, vector<Node*>());
		map[clone->val] = clone;
		for (Node* neighbor : node->neighbors)
		{
			clone->neighbors.push_back(recurClone(neighbor, map));
		}

		return clone;
	}

public:
	Node* cloneGraph(Node* node) 
	{
		if (!node)
			return nullptr;

		unordered_map<int, Node*> map;
		return recurClone(node, map);
	}
};

