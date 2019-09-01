#pragma once
#include "CircLink.h"

// Template class sCircDeque for singly linked circular double ended queue
template <class T>
class sCircDeque
{
private:
	Circlink<T> C;
public:
	int size() const;
	bool empty() const;
	const T& front() const;
	const T& rear() const;
	void insertFront(const T& e);
	void removeFront();
	void insertRear(const T& e);
	void removeRear();
};

template <class T>
int sCircDeque<T>::size() const
{
	return C.size();
}

template <class T>
bool sCircDeque<T>::empty() const
{
	return C.empty();
}

template <class T>
const T& sCircDeque<T>::front() const
{
	if (!empty())
		return C.front();
}

template <class T>
const T& sCircDeque<T>::rear() const
{
	if (!empty())
		return C.rear();
}

template <class T>
void sCircDeque<T>::insertFront(const T& e)
{
	C.addFront(e);
}

template <class T>
void sCircDeque<T>::removeFront()
{
	if (!empty())
		C.removeFront();
}

template <class T>
void sCircDeque<T>::insertRear(const T& e)
{
	C.addRear(e);
}

template <class T>
void sCircDeque<T>::removeRear()
{
	if (!empty())
		C.removeRear();
}
