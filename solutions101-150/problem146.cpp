// 146. LRU Cache
#include <unordered_map>
using namespace std;	

struct DoublyLinkedListNode
{
	int key;
	int val;
	DoublyLinkedListNode* pre;
	DoublyLinkedListNode* post;

	DoublyLinkedListNode(int k = 0, int v = 0)
		: key(k), val(v), pre(nullptr), post(nullptr)
	{}
};

class LRUCache
{
private:
	int m_capacity;
	int cnt;
	unordered_map<int, DoublyLinkedListNode*> cache;
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;

	void add(DoublyLinkedListNode* node)
	{
		node->post = head->post;
		node->pre = head;
		head->post->pre = node;
		head->post = node;
	}

	void remove(DoublyLinkedListNode* node)
	{
		DoublyLinkedListNode* pre = node->pre;
		DoublyLinkedListNode* post = node->post;
		pre->post = post;
		post->pre = pre;
	}

	void moveToFirst(DoublyLinkedListNode* node)
	{
		remove(node);
		add(node);
	}

	DoublyLinkedListNode* pop()
	{
		DoublyLinkedListNode* last = tail->pre;
		remove(last);
		return last;
	}

public:
	LRUCache(int capacity)
		: m_capacity(capacity), cnt(0), head(new DoublyLinkedListNode()), tail(new DoublyLinkedListNode())
	{
		head->post = tail;
		tail->pre = head;
	}

	int get(int key)
	{
		if (cache.find(key) == cache.end())
			return -1;

		DoublyLinkedListNode* node = cache[key];
		moveToFirst(node);
		return node->val;
	}

	void put(int key, int value) 
	{
		if (cache.find(key) == cache.end())
		{
			DoublyLinkedListNode* node = new DoublyLinkedListNode(key, value);
			add(node);
			cache[key] = node;
			cnt++;

			if (cnt > m_capacity)
			{
				DoublyLinkedListNode* last = pop();
				cache.erase(last->key);
				cnt--;
			}
		}
		else
		{
			DoublyLinkedListNode* node = cache[key];
			node->val = value;
			moveToFirst(node);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
