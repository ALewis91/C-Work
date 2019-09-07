#pragma once
#include "Entry.h"
#include "C.h"
#include "VectorCompleteTree.h"
class HeapPriorityQueue
{
public:
	typename typedef VectorCompleteTree::Position Position;
	int size() const { return T.size(); }
	bool empty() const { return T.size() == 0; }
	void insert(const Entry& e);
	const Entry& min() { return *(T.root()); }
	void removeMin();
private:
	VectorCompleteTree T;
	C isLess;
};

void HeapPriorityQueue::insert(const Entry& e)
{
	T.addLast(e);
	Position v = T.last();
	while (!T.isRoot(v))
	{
		Position u = T.parent(v);
		if (!isLess(*v, *u))
			break;
		T.swap(v, u);
		v = u;
	}
}

void HeapPriorityQueue::removeMin()
{
	if (size() == 1)
		T.removeLast();
	else
	{
		Position u = T.root();
		T.swap(u,T.last());
		T.removeLast();
		while (T.hasLeft(u))
		{
			Position v = T.left(u);
			if (T.hasRight(u) && isLess(*(T.right(u)), *v))
				v = T.right(u);
			if (isLess(*v, *u))
			{
				T.swap(u, v);
				u = v;
			}
			else
				break;
		}
	}
}
VectorCompleteTree.h
#pragma once
#include "Entry.h"
#include <vector>
class VectorCompleteTree
{
private:
	std::vector<Entry> V;
public:
	typedef typename std::vector<Entry>::iterator Position;
protected:
	Position pos(int i)
	{
		return V.begin() + i;
	}
	int idx(const Position& p) const
	{
		return p - V.begin();
	}
public:
	VectorCompleteTree() : V(1) {}
	int size() const { return V.size() - 1; }
	Position left(const Position& p) { return pos(2 * idx(p)); }
	Position right(const Position& p) { return pos(2 * idx(p) + 1); }
	Position parent(const Position& p) { return pos(idx(p) / 2); }
	bool hasLeft(const Position& p) const { return 2 * idx(p) <= size(); }
	bool hasRight(const Position& p) const { return 2 * idx(p) + 1 <= size(); }
	bool isRoot(const Position& p) const { return idx(p) == 1; }
	Position root() { return pos(1); }
	Position last() { return pos(size()); }
	void addLast(const Entry& e) { V.push_back(e); }
	void removeLast() { V.pop_back(); }
	void swap(const Position& p, const Position& q)
	{
		Entry temp(q->key(), q->value());
		q->setKey(p->key());
		q->setValue(p->value());
		p->setKey(temp.key());
		p->setValue(temp.value());
	}

	friend class HeapPriorityQueue;
};
