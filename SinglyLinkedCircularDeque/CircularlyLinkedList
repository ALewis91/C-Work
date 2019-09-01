
#pragma once
#include "Node.h"

// Template class for circularly linked list
template <class T>
class Circlink
{
private:
	// Nodes to keep track of front and rear
	Node<T> *fCursor;
	Node<T> *rCursor;

	// Size
	int n;
public:
	Circlink();
	~Circlink()
	{
		while (!empty())
			removeFront();
	}
	bool empty() const;
	const T& front() const;
	const T& rear() const;
	void addFront(const T& elem);
	void removeFront();
	void addRear(const T& elem);
	void removeRear();
	int size() const;
};

// Constructor - init vars
template <class T>
Circlink<T>::Circlink()
{
	fCursor = nullptr;
	rCursor = nullptr;
	n = 0;
}

// Returns true if list is empty
template <class T>
bool Circlink<T>::empty() const
{
	return n == 0;
}

// Returns the front node if the list is not empty
template <class T>
const T& Circlink<T>::front() const
{
	if (!empty())
		return fCursor->elem;
}

// Returns the rear node if the list is not empty
template <class T>
const T& Circlink<T>::rear() const
{
	if (!empty())
		return rCursor->elem;
}

// Adds a new node to the front and adjusts pointers and increments size
template <class T>
void Circlink<T>::addFront(const T& e)
{
	Node<T> *temp = new Node<T>;
	temp->elem = e;
	if (empty())
	{
		temp->next = temp;
		fCursor = temp;
		rCursor = temp;
	}
	else
	{
		temp->next = fCursor;
		fCursor = temp;
		rCursor->next = fCursor;
	}
	n++;
}

//Removes element from rear and decrements size
template <class T>
void Circlink<T>::removeFront()
{
	if (!empty())
	{
		Node<T> *old = fCursor;
		if (old->next == fCursor)
		{
			delete old;
			fCursor = nullptr;
			rCursor = nullptr;
		}
		else
		{
			fCursor = old->next;
			delete old;
			rCursor->next = fCursor;
		}
		n--;
	}
}

// Returns size of the list
template <class T>
int Circlink<T>::size() const
{
	return n;
}

// Adds element to the rear and increments size
template <class T>
void Circlink<T>::addRear(const T& e)
{
	Node<T> *temp = new Node<T>;
	temp->elem = e;
	if (empty())
	{
		temp->next = temp;
		fCursor = temp;
		rCursor = temp;
	}
	else
	{
		rCursor->next = temp;
		rCursor = temp;
		rCursor->next = fCursor;
	}
	n++;
}

// Removes element from rear and decrements size
template <class T>
void Circlink<T>::removeRear()
{
	if (!empty())
	{
		Node<T> *old = fCursor;
		if (fCursor == rCursor)
		{
			delete old;
			n--;
			fCursor = nullptr;
			rCursor = nullptr;
		}
		else
		{
			Node<T> *newRear = fCursor;
			while (newRear->next != rCursor)
				newRear = newRear->next;
			old = newRear->next;
			delete old;
			rCursor = newRear;
			rCursor->next = fCursor;
			n--;
		}
	}
}
