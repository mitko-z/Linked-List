#include "LinkedList.h"

int linkedList::begin()
{
	if (startNode == nullptr) throw;

	return startNode->data;
}

void linkedList::add(int data)
{
	node *newMember = new node(data, nullptr);
	if (currentPos == nullptr)
	{
		startNode = newMember;
		currentPos = newMember;
	}
	else
	{
		currentPos->next = newMember;
		currentPos = currentPos->next;
	}
	m_size++;
}


int linkedList::at(int pos)
{
	if (pos < 0) throw;
	int i = 0;
	node* it = startNode;
	while (i < pos)
	{
		it = it->next;
		i++;
	}

	return it->data;
}

void linkedList::removeAt(int pos)
{
	if (pos < 0 || pos >= m_size) throw;
	if (m_size == 1)
	{
		delete startNode;
		currentPos = nullptr;
		startNode = nullptr;
		m_size = 0;
	}
	else
	{
		if (pos == 0)
		{
			startNode = startNode->next;
			m_size--;
		}
		else
		{
			int i = 0;
			node* it = startNode;
			while (i < pos - 1)
			{
				it = it->next;
				i++;
			}
			node* temp = it->next->next;
			delete it->next;
			it->next = temp;
			m_size--;
		}
	}
}

void linkedList::deleteList(node* atNode)
{
	if (atNode != nullptr)
	{
		if (atNode->next == nullptr)
		{
			delete atNode;
			m_size--;
		}
		else
		{
			deleteList(atNode->next);
			atNode->next = nullptr;
			deleteList(atNode);
		}
	}
}

linkedList::~linkedList()
{
	deleteList(startNode);
	startNode = nullptr;
	m_size = 0;
}