// Comparator for pq

#pragma once
#include "Entry.h"
class C
{
public:
	bool operator()(const Entry& a, const Entry& b) const
	{
		return a.key() < b.key();
	}
};
