/* Program: Lab 6 Deques
Author: Aaron Lewis
Class: CSCI 220
Date: 8/28/2017
Description: Implement a deque using a singly linked list
I certify that the code below is my own work.
Exception(s): N/A
*/

#include "sCircDeque.h"
#include <string>
#include <iostream>

int main()
{
	std::cout << "Author: Aaron Lewis\n\n";

	// Create a deque of type string
	sCircDeque<std::string> deque;

	std::cout << "Inserting 3 to front...\n";
	deque.insertFront("3");
	std::cout << "Inserting 2 to front...\n";
	deque.insertFront("2");
	std::cout << "Inserting 1 to front...\n";
	deque.insertFront("1");
	std::cout << "Inserting 4 to rear...\n";
	deque.insertRear("4");
	std::cout << "Inserting 5 to rear...\n";
	deque.insertRear("5");
	std::cout << "Inserting 6 to rear...n";
	deque.insertRear("6");
	std::cout << "\nDeque should contain: { 1 2 3 4 5 6 }\n";
	std::cout << "Front is: " << deque.front();
	std::cout << "\nRemoving Front...\n";
	deque.removeFront();
	std::cout << "Deque should contain: { 2 3 4 5 6 }\n";
	std::cout << "Front is: " << deque.front();
	std::cout << "\nRear is: " << deque.rear();
	std::cout << "\nRemoving Rear...\n";
	deque.removeRear();
	std::cout << "Deque should contain: { 2 3 4 5 }\n";
	std::cout << "Rear is: " << deque.rear();
	std::cout << "\nRemoving Front x 2...\n";
	deque.removeFront();
	deque.removeFront();
	std::cout << "Deque should contain: { 4 5 }\n";
	std::cout << "Front is: " << deque.front();
	std::cout << "\nRear is: " << deque.rear();
	std::cout << "\nRemoving Rear x 2...\n";
	deque.removeRear();
	deque.removeRear();

	std::cout << "Deque should be empty\n";
	if (deque.empty())
		std::cout << "The deque is empty!\n";
	else
		std::cout << "The deque is not empty\n";
	return 0;
}
