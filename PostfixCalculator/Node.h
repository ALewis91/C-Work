#pragma once


template <class N>

class Node
{
public:
	N elem;
	Node<N> *next;

	template<class T>  friend class Slink;
};
