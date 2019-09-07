#include "LinkedList.h"

LinkedList::LinkedList()
{
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	n = 0;
}
LinkedList::LinkedList(const LinkedList& LL)
{
	n = LL.n;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	if (n > 0)
	{
		Node* temp = LL.header->next;
		for (int x = 0; x < n; x++)
		{
			insertBack(temp->customerID, temp->callTime);
		}
	}

}
LinkedList& LinkedList::operator=(const LinkedList& LL)
{
	while (n > 0)
		removeFront();

	n = LL.n;
	Node* temp = LL.header->next;
	for (int x = 0; x < n; x++)
	{
		insertBack(temp->customerID, temp->callTime);
	}

	return *this;
}
LinkedList::~LinkedList()
{
	while (n > 0)
		removeFront();

	delete header;
	delete trailer;
}
int LinkedList::size() const
{
	return n;
}
bool LinkedList::empty() const
{
	return n == 0;
}
void LinkedList::insertFront(const int ID, const int callT)
{
	Node* toAdd = new Node;
	toAdd->customerID = ID;
	toAdd->callTime = callT;

	Node* x = header;
	Node* z = header->next;

	toAdd->prev = x;
	toAdd->next = z;
	z->prev = toAdd;
	x->next = toAdd;

	n++;
}

void LinkedList::insertBack(const int ID, const int callT)
{
	Node* toAdd = new Node;
	toAdd->customerID = ID;
	toAdd->callTime = callT;

	Node* x = trailer->prev;
	Node* z = trailer;

	toAdd->prev = x;
	toAdd->next = z;
	z->prev = toAdd;
	x->next = toAdd;

	n++;
}
void LinkedList::removeFront()
{
	if (n > 0)
	{
		Node* old = header->next;
		Node* x = header;
		Node *z = old->next;

		x->next = z;
		z->prev = x;

		delete old;

		n--;
	}
}
void LinkedList::removeBack()
{
	if (n > 0)
	{
		Node* old = trailer->prev;
		Node* x = old->prev;
		Node *z = trailer;

		x->next = z;
		z->prev = x;

		delete old;
		n--;
	}
}
void LinkedList::insert(int i, const int ID, const int callT)
{
	if (i <= n && i >= 0)
	{
		Node* cur = header->next;
		for (int x = 0; x < i; x++)
		{
			cur = cur->next;
		}

		Node* x = cur->prev;
		Node* z = cur;
		Node* y = new Node;
		y->customerID = ID;
		y->callTime = callT;

		y->next = z;
		y->prev = x;
		z->prev = y;
		x->next = y;
		n++;
	}
}
void LinkedList::remove(int i)
{
	if (i < n && i >= 0)
	{
		Node* cur = header->next;
		for (int x = 0; x < i; x++)
		{
			cur = cur->next;
		}

		Node* x = cur->prev;
		Node* z = cur->next;

		z->prev = x;
		x->next = z;

		delete cur;
		n--;
	}
}


int LinkedList::get_callTime(int index) const
{
	if (index >= 0 && index < n && n > 0)
	{
		Node* temp = header->next;
		for (int x = 0; x < index; x++)
			temp = temp->next;
		return temp->callTime;
	}
	else
		return -1;
}

int LinkedList::get_ID(int index) const
{
	if (index >= 0 && index < n && n > 0)
	{
		Node* temp = header->next;
		for (int x = 0; x < index; x++)
			temp = temp->next;
		return temp->customerID;
	}
	else
		return -1;
}
