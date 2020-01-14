// 138. Copy List with Random Pointer

// Definition for a Node.
class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val)
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution 
{
public:
	Node* copyRandomList(Node* head) 
	{
		if (!head)
			return nullptr;

		// 1. Copies the original node to the new node named copy, 
		//    and links the nodes like this: node1 -> copy_node1 -> node2 -> copy_node2 -> ...
		for (Node* temp = head; temp; temp = temp->next->next)
		{
			Node* copy = new Node(temp->val);
			copy->next = temp->next;
			temp->next = copy;
		}

		// 2. Sets the random pointer of the copied node
		for (Node* temp = head; temp; temp = temp->next->next)
		{
			if (temp->random)
			{
				temp->next->random = temp->random->next;
			}
		}

		// 3. Detaches the linked list to the original list and copy list 
		Node* copy_head = new Node(0);
		Node* copy = copy_head;
		for (Node* temp = head; temp; temp = temp->next)
		{
			copy->next = temp->next;
			copy = copy->next;
			temp->next = temp->next->next;
		}

		return copy_head->next;
	}
};
