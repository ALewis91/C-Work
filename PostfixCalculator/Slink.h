#pragma once
#include "Node.h"
#include <iostream>
template <class T>

class Slink
{
private:
	Node<T> *head;
	int n;
public:
	Slink();
	~Slink() 
	{ while (!empty())
				removeFront(); }
	bool empty() const;
	const T& front() const;
	void addFront(const T& elem);
	void removeFront();
	int size() const;
};

template <class T>
Slink<T>::Slink()
{
	head = NULL;
	n = 0;
}

template <class T>
bool Slink<T>::empty() const
{
	return head == NULL;
}

template <class T>
const T& Slink<T>::front() const
{
	return head->elem;
}

template <class T>
void Slink<T>::addFront(const T& e)
{
	Node<T> *temp = new Node<T>;
	temp->elem = e;
	temp->next = head;
	head = temp;
	n++;
}

template <class T>
void Slink<T>::removeFront()
{
	if (!empty())
	{
		Node<T> *old = head;
		head = old->next;
		n--;
		delete old;
	}
}

template <class T>
int Slink<T>::size() const
{
	return n;
}
