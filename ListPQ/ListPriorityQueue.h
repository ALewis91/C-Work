#pragma once
#include <list>
#include "C.h"

class ListPriorityQueue
{
public:
	int size() const;
	bool empty() const;
	void insert(const Entry& e);
	const Entry& min() const;
	void removeMin();
private:
	std::list<Entry> L;
	C isLess;
};

int ListPriorityQueue::size() const
{
	return L.size();
}

bool ListPriorityQueue::empty() const
{
	return L.empty();
}

void ListPriorityQueue::insert(const Entry& e)
{
	typename std::list<Entry>::iterator p;
	p = L.begin();
	while (p != L.end() && !isLess(e, *p))
		++p;
	L.insert(p, e);
}

const Entry& ListPriorityQueue::min() const
{
	return L.front();
}

void ListPriorityQueue::removeMin()
{
	L.pop_front();
}
