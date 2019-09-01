#pragma once
#include <iostream>

// Template class for node
template <class N>
class Node
{
public:
	N elem;
	Node<N> *next;
	template<class T> friend class Slink;
};
