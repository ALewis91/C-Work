#pragma once
#include "Slink.h"

template <class T>
class Stack
{
private:
	Slink<T> S;
public:
	Stack() {};
	bool empty() const;
	const T& top() const;
	void push(const T& e);
	T pop();
	int size() const;
};

template <class T>
int Stack<T>::size() const
{
	return S.size();
}

template <class T>
bool Stack<T>::empty() const
{
	return S.empty();
}

template <class T>
const T& Stack<T>::top() const
{
	if (!empty())
		return S.front();
}

template <class T>
void Stack<T>::push(const T& e)
{
	S.addFront(e);
}

template <class T>
T Stack<T>::pop()
{
	if (!empty())
	{
		T temp = S.front();
		S.removeFront();
		return temp;
	}
}
