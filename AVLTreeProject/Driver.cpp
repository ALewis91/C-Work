#include "Entry.h"
#include "AVLTree.h"
#include <string>
#include <fstream>
#include <iostream>

void uploadFile(AVLTree& tree, SearchTree& bst, std::string& code, std::string& population, std::string& location);
std::string menu(AVLTree& tree, SearchTree& bst, std::string& code, std::string& population, std::string& location, fstream& out);
void printTree(const AVLTree& a, fstream& file);

int main()
{
	fstream treeoutput;
	treeoutput.open("Tree.csv");
	std::cout << "Welcome to our Records Manager program " << endl;
	std::cout << "Creating a binary search tree..." << std::endl;
	std::cout << "Creating a AVL tree..." << std::endl;

	SearchTree BSTree;
	AVLTree aTree;

	std::string code;
	std::string population;
	std::string location;
	std::string userChoice = "";

	uploadFile(aTree, BSTree, code, population, location);
	//std::cout << "Tree Size: " << aTree.size() << std::endl;
	//std::cout << "Tree Root: " << (*aTree.root()).areaCode() << std::endl;

	while (userChoice != "5")
	{
		userChoice = menu(aTree, BSTree, code, population, location, treeoutput);
	}


}

void uploadFile(AVLTree& tree, SearchTree& bst, std::string& code, std::string& population, std::string& location)
{
	ifstream input;
	input.open("p4Large.txt");
	while (!input.eof())
	{
		std::getline(input, code, ',');
		std::getline(input, population, ',');
		std::getline(input, location);
		int pop = std::stoi(population);
		tree.insert(code, pop, location);
		bst.insert(code, pop, location);
	}
}

std::string menu(AVLTree& tree, SearchTree& bst, std::string& code, std::string& population, std::string& location, fstream& out)
{
	std::string userChoice;
	std::cout << "1 - Search for a record" << std::endl;
	std::cout << "2 - Insert a record" << std::endl;
	std::cout << "3 - Delete a record" << std::endl;
	std::cout << "4 - List all records" << std::endl;
	std::cout << "5 - Exit" << std::endl;
	std::cin >> userChoice;
	while (!isdigit(userChoice[0]) || userChoice.length() > 1)
	{
		std::cout << "Error! Input integer value between 1 and 5: ";
		std::cin >> userChoice;
	}

	switch (stoi(userChoice)) 
	{

	case 1: {
		std::cout << "Please enter the area code" << std::endl;
		std::cin >> code;
		AVLTree::Iterator it = tree.find(code);
		SearchTree::Iterator it2 = bst.find(code);
		if ((*it).areaCode() == "" && (*it).areaName() == "" && (*it).population() == 0)
			std::cout << "Record not found.\n";
		else
		{
			std::cout << "\nRecord\n--------------\n";
			std::cout << "County/State Code: " << (*it).areaCode() << std::endl;
			std::cout << "County/State Name: " << (*it).areaName() << std::endl;
			std::cout << "Population:        " << (*it).population() << std::endl;
		}
		std::cout << "\nUnits of Work\n--------------\n";
		std::cout << "BST:  " << bst.getUnits() << std::endl;
		std::cout << "AVLT: " << tree.getUnits() << std::endl << std::endl;
		break;
	}

	case 2: {
		std::cout << "Enter Code, Population, County/State Name" << std::endl;
		cin >> code;
		cin >> population;
		std::getchar();
		std::getline(cin, location);
		int pop = stoi(population);
		tree.insert(code, pop, location);
		break;
	}

	case 3: {
		std::cout << "Please enter the area code" << std::endl;
		std::cin >> code;
		try
		{
			tree.erase(code);
			std::cout << "Record deleted.\n";
		}
		catch (NonexistentElement e)
		{
			std::cout << "Record could not be deleted as it does not exist.\n";
		}
		break;
	}

	case 4: {
		BinaryTree::PositionList pl;
		tree.inorder(pl);
		//tree.levelorder(pl);
		for (BinaryTree::Position p : pl)
		{
			std::cout << "\nState/County Code: " << (*p).areaCode();
			std::cout << "\nCounty/State Name: " << (*p).areaName();
			std::cout << "\nPopulation:        " << (*p).population();
			std::cout << std::endl;
		}
		break;
	}
	case 5: 
		break;
	default: std::cout << "Invalid selection. Please choose from the menu" << std::endl;
	}
	return userChoice;
}

void printTree(const AVLTree& a, fstream& file)
{
	BinaryTree::PositionList pl;
	BinaryTree::PositionList inUse;
	BinaryTree::PositionList::iterator it;
	a.levelorder(pl);
}
