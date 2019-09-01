/* Program: A "Simple" Text Editor
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 10/17/2017
Description: Tests various functions of the list
and iterator classes.
I certify that the code below is my own work.
Exception(s): N/A
*/
#include "NodeList.h"
#include <iostream>
void printMenu()
{
	std::cout << "Menu:\n1 - Left\n2 - Right\n3 -"
		<< " Delete\n4 - Insert Char\n5 - Quit\n";
}
bool validChoice(std::string c)
{
	return (c == "1" || c == "2"
		|| c == "3" || c == "4"
		|| c == "5");
}
int main()
{
	std::cout << "Author: Aaron Lewis\n\n";

	// Create a node list for the text
	NodeList Text;

	// Init user choice
	std::string choice = "a";

	// Loop until user ends program
	while (choice != "5")
	{
		// Print menu and get user input
		printMenu();
		std::cin >> choice;

		// If input is invalid, clear buffer and reprent menu
		while (!validChoice(choice))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid Choice!!\n\n";
			printMenu();
			std::cin >> choice;
		}

		// Execute user choice
		if (choice == "1")
		{
			Text.left();
		}
		else if (choice == "2")
		{
			Text.right();
		}
		else if (choice == "3")
		{
			Text.dlete();
		}
		else if (choice == "4")
		{
			std::string character;
			std::cout << "Char to Insert: ";
			std::cin >> character;
			Text.insert(character[0]);
		}

		// Print the new text
		std::cout << Text.printList()
			<< std::endl << std::endl;
	}
	return 0;
}
