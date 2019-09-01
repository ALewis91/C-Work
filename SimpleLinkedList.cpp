/* Program: Lab 3 - Linked List
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 09/18/2017
Description: This program allows the user to add names
to a linked list of names to either the front or
the back of the list and also remove a name based
on its position in the list.
I certify that the code below is my own work.
Exception(s): N/A
*/

#include <iostream>
#include <string>
#include "string"
using namespace std;

// Linked-list node
struct Node
{
	string name;
	Node *next;
	Node *prev;
};

// Simple Linked-list
struct linked_list
{
	Node head;
	Node tail;
	int size;
};

// Function prototypes
void insert_front(linked_list *l, string n);
void insert_rear(linked_list *l, string n);
bool remove_name(linked_list *l, int e);
const void print_list(linked_list *l, int size);
void print_menu();


int main()
{
	cout << "Author: Aaron Lewis\n";

	// Create a new linked list for names
	linked_list names;
	
	// Assign head and tail to point to each other 
	names.head.next = &names.tail;
	names.head.prev = nullptr;
	names.tail.next = nullptr;
	names.tail.prev = &names.head;

	// Assign 0 to names linked list size 
	names.size = 0;

	// Initialize sentinal variable
	bool end = false;

	// Initialize input variables
	string choice = "";
	string new_name;
	int name_loc;

	// Loop until user chooses to end
	while (!end)
	{

		// Display menu options
		print_menu();

		// Get user input
		cin >> choice;

		// If insert new name at front
		if (choice == "1")
		{
			cout << endl << "Enter the new name: ";
			cin >> new_name;
			insert_front(&names, new_name);
			cout << endl;
		}

		// If insert new name at rear
		else if (choice == "2")
		{
			cout << endl << "Enter the new name: ";
			cin >> new_name;
			insert_rear(&names, new_name);
			cout << endl;
		}

		// If remove a name
		else if (choice == "3")
		{
			cout << endl << "Enter the number of the name to remove: ";
			cin >> name_loc;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter a valid integer between 1 and " << names.size
					<< ": ";
				cin >> name_loc;
			}
			remove_name(&names, name_loc);
			cout << endl;
		}

		// If print list
		else if (choice == "4")
		{
			cout << endl;
			print_list(&names, names.size);
			cout << endl;
		}

		// If invalid menu choice
		else
			cout << "Please enter 1, 2, 3 or 4!!" << endl;
	}
	return 0;
}

// Creates a new node with string n and adjusts pointers to insert at front
// then increments the size
void insert_front(linked_list *l, string n)
{
	Node *temp = new Node;
	temp->name = n;
	temp->prev = &l->head;
	temp->next = l->head.next;
	l->head.next->prev = temp;
	l->head.next = temp;
	l->size++;
}

// Creates a new node with string n and adjusts pointers to insert at rear
// then increments the size
void insert_rear(linked_list *l, string n)
{
	Node *temp = new Node;
	temp->name = n;
	temp->prev = l->tail.prev;
	temp->next = &l->tail;
	temp->prev->next = temp;
	l->tail.prev = temp;
	l->size++;
}

// Goes to index e in the linked list and removes that node if possible
// then decrements the size. Also, adjusts pointers to skip over the to-be-deleted node.
bool remove_name(linked_list *l, int e)
{
	if (e < l->size + 1)
	{
		Node *cur = &l->head;
		for (int x = 0; x < e; x++)
		{
			cur = cur->next;
		}
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		l->size--;
		delete cur;
		return true;
	}
	else
		return false;
}

// Iterates through the list and prints out the name in each node
const void print_list(linked_list *l, int size)
{
	Node *cur = &l->head;
	for (int x = 0; x < l->size; x++)
	{
		cur = cur->next;
		cout << x + 1 << ": " << cur->name << endl;
	}
}

// Prints the menu
void print_menu()
{
	cout << "Menu Options" << endl << endl;
	cout << "1 - Insert New Name @ Front" << endl;
	cout << "2 - Insert New Name @ Rear" << endl;
	cout << "3 - Remove a Name" << endl;
	cout << "4 - Print List of Names" << endl;
	cout << "5 - End" << endl << endl;
}
