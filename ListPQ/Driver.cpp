#include "ListPriorityQueue.h"
#include <iostream>

int main()
{
	std::cout << "Author:Aaron Lewis\n\n";
	std::cout << "Creating ListPriorityQueue PQ...\n";

	ListPriorityQueue PQ;

	std::cout << "Creating Entry e with Key 5, Value Bob...\n";
	Entry e(5, "Bob");

	std::cout << "Adding entry to PQ...\n";
	PQ.insert(e);
	std::cout << "Changing key of e to 1...\n";
	e.setKey(1);
	std::cout << "Changing value of e to \"Jim\"...\n";
	e.setValue("Jim");
	std::cout << "Adding entry to PQ...\n";
	PQ.insert(e);
	std::cout << "Changing key of e to 3...\n";
	e.setKey(3);
	std::cout << "Changing value of e to \"Joe\"...\n";
	e.setValue("Joe");
	std::cout << "Adding entry to PQ...\n";
	PQ.insert(e);
	std::cout << "Changing key of e to 1...\n";
	e.setKey(1);
	std::cout << "Changing value of e to \"Aaron\"...\n";
	e.setValue("Aaron");
	std::cout << "Adding entry to PQ...\n";
	PQ.insert(e);

	while (!PQ.empty())
	{
		std::cout << "\nPQ has a size of " << PQ.size() << std::endl;
		std::cout << PQ.min().value() << " has the highest priority.\n";
		std::cout << "Removing min...";
		PQ.removeMin();
	}

	std::cout << "\nThe priority queue is now empty...\n";

	return 0;
}
