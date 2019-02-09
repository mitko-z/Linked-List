#pragma once

class linkedList
{
private:
	struct node
	{
		node(int data, node * nextNode) : data(data), next(nextNode) {}
		int data;
		node * next;
	};
	node* startNode;
	node* endNode;
	node* currentPos;
	int m_size;

	void deleteList(node* atNode);

public:
	linkedList() : startNode(nullptr), currentPos(startNode), endNode(startNode), m_size(0) {}

	int begin();

	int size() { return m_size; }

	void add(int data);
	
	int at(int pos);

	void removeAt(int pos);

	~linkedList();
};