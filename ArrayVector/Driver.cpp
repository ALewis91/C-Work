/* Program: VectorArray
Author: Aaron Lewis
Class: CSCI 220
Date: 10/10/2017
Description: This program tests various functions
of the ArrayVector class objects.
I certify that the code below is my own work.
Exception(s): N/A
*/
#include "ArrayVector.h"
#include <iostream>

// Function which prints the contents of the vector
void printVector(ArrayVector<char> a)
{
	std::cout << " contains: { ";
	for (int x = 0; x < a.size(); x++)
		std::cout << a.at(x) << " ";
	std::cout << "}\n";
}


int main()
{
	std::cout << "Author: Aaron Lewis\n\n";
	std::cout << "Creating ArrayVector AV...\n";
	ArrayVector<char> AV;
	std::cout << "Inserting 'A' at index 0...\n";
	AV.insert(0, 'A');
	std::cout << "AV should contain: { A }\nAV";
	printVector(AV);
	std::cout << "\nInserting 'B' at index 1...\n";
	AV.insert(1, 'B');
	std::cout << "AV should contain: { A B }\nAV";
	printVector(AV);
	std::cout << "\nInserting 'C' at index 2...\n";
	AV.insert(2, 'C');
	std::cout << "AV should contain: { A B C }\nAV";
	printVector(AV);
	std::cout << "\nInserting '1' at index 1...\n";
	AV.insert(1, '1');
	std::cout << "AV should contain: { A 1 B C }\nAV";
	printVector(AV);
	std::cout << "\nInserting '2' at index 3...\n";
	AV.insert(3, '2');
	std::cout << "AV should contain: { A 1 B 2 C }\nAV";
	printVector(AV);
	std::cout << "\nInserting '3' at index 5...\n";
	AV.insert(5, '3');
	std::cout << "AV should contain: { A 1 B 2 C 3 }\nAV";
	printVector(AV);
	std::cout << "\nCreating copy of AV named copyAV using copy constructor...\n";
	ArrayVector<char> copyAV = AV;
	std::cout << "copyAV should contain: { A 1 B 2 C 3 }\ncopyAV";
	printVector(copyAV);
	std::cout << "\nRemoving digits from AV using erase function...\n";
	AV.erase(5);
	AV.erase(3);
	AV.erase(1);
	std::cout << "AV should contain: { A B C }\nAV";
	printVector(AV);
	std::cout << "\nAssigning AV to copyAV using overloaded = operator...\n";
	copyAV = AV;
	std::cout << "copyAV should contain: { A B C }\ncopyAV";
	printVector(copyAV);
	std::cout << "\nRemoving B and C from copyAV...\n";
	copyAV.erase(1);
	copyAV.erase(1);
	std::cout << "copyAV should contain: { A }\ncopyAV";
	printVector(copyAV);
	std::cout << "\ncopyAV should have size of 1 and a capacity of 8\n";
	std::cout << "copyAV size: " << copyAV.size();
	std::cout << "\ncopyAV capacity: " << copyAV.capacity();
	std::cout << "\nResizing copyAV...\n";
	copyAV.resize();
	std::cout << "\ncopyAV should have size of 1 and a capacity of 2\n";
	std::cout << "copyAV size: " << copyAV.size();
	std::cout << "\ncopyAV capacity: " << copyAV.capacity();
	std::cout << "\ncopyAV should contain: { A }\ncopyAV";
	printVector(copyAV);
	std::cout << std::endl;
	return 0;
}
