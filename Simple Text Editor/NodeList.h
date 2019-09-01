/* Program: A "Simple" Text Editor
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 10/17/2017
Description: NodeList Class
I certify that the code below is my own work.
Exception(s): N/A
*/
#pragma once
#include <string>


typedef char Elem;
class NodeList
{
private:

	// Doubly linked node
	struct Node
	{
		Elem e;
		Node *prev;
		Node *next;
	};

	// Iterator class to traverse the text
public:
	class Iterator
	{
	private:
		Node *v;
		Iterator(Node *u) { v = u; };
		Iterator() { v = nullptr; };
		void setCursor(Node *ptr) { v = ptr; };
	public:
		Elem& operator*() { return v->e; };
		bool operator==(const Iterator& p) const { return v == p.v; };
		bool operator!=(const Iterator& p) const { return v != p.v; };
		Iterator& operator++() { v = v->next; return *this; };
		Iterator& operator--() { v = v->prev; return *this; };
		friend class NodeList;
	};

	// Private variables
private:
	int n;
	Node* header;
	Node* trailer;
	Iterator cursor;

	// Functions
public:
	NodeList();
	// NodeList(const NodeList& nl);
	// ~NodeList();
	// NodeList& operator=(const NodeList& nl);
	int size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void insert(const Iterator& p, const Elem& e);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);
	std::string printList();
	void left();
	void right();
	void dlete();
	void insert(Elem& e);
};

// Constructor 
NodeList::NodeList()
{
	n = 0;
	header = new Node;
	header->e = NULL;
	trailer = new Node;
	trailer->e = NULL;
	header->next = trailer;
	trailer->prev = header;
	cursor.setCursor(trailer);
}
/*NodeList::NodeList(const NodeList& nl)
{
n = nl.n;
for (Iterator p = nl.begin(); p < nl.end(); p++)
{
insertBack(*p);
}
}
NodeList::~NodeList()
{
while (!empty())
eraseFront();
}
int NodeList::size() const
{
return n;
}
NodeList& NodeList::operator=(const NodeList& nl)
{
if (header->next != trailer || trailer->prev != header)
{
NodeList::~NodeList();
}
n = nl.n;
typedef NodeList::Iterator iterator;
iterator p = nl.begin();
while (p < --end())
for (; p < nl.end(); p++)
{
insertBack(*p);
}
}
*/

int NodeList::size() const
{
	return n;
}

bool NodeList::empty() const
{
	return (n == 0);
}

NodeList::Iterator NodeList::end() const
{
	return Iterator(trailer);
}

NodeList::Iterator NodeList::begin() const
{
	return Iterator(header->next);
}

void NodeList::insert(const NodeList::Iterator& p, const Elem& e)
{
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w;
	w->prev = v;
	v->prev = u;
	u->next = v;
	n++;
}

void NodeList::insertFront(const Elem& e)
{
	insert(begin(), e);
}

void NodeList::insertBack(const Elem& e)
{
	insert(end(), e);
}

void NodeList::erase(const NodeList::Iterator& p)
{
	Node* v = p.v;
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w;
	w->prev = u;
	delete v;
	n--;
}

void NodeList::eraseFront()
{
	erase(begin());
}

void NodeList::eraseBack()
{
	erase(--end());
}

std::string NodeList::printList()
{
	std::string list = "";
	NodeList::Iterator p = begin();
	while (p != end())
	{
		if (p.v == cursor.v)
			list += '>';
		list += *p;
		++p;
	}
	if (cursor.v == trailer)
		list += '>';
	return list;
}

void NodeList::left()
{
	if (cursor.v != begin().v)
		--cursor;
}

void NodeList::right()
{
	if (cursor.v != end().v)
		++cursor;
}

void NodeList::insert(Elem& e)
{
	NodeList::insert(cursor, e);
}

void NodeList::dlete()
{
	if (cursor.v != trailer)
	{
		NodeList::Iterator temp;
		temp.v = cursor.v;
		right();
		NodeList::erase(temp);
	}
}
