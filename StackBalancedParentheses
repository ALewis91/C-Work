/* Program: Balancing Symbols
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 10/01/2017
Description: This program notifies a user if an
equation has balanced, appropriately placed
parentheses, braces and brackets.
I certify that the code below is my own work.
Exception(s): N/A
*/
#include <iostream>
#include <stack>
int main()
{
	std::cout << "Author: Aaron Lewis\n\n";

	// Create char var to hold next char in a string expression
	char next;

	// Assume expression starts as true
	bool balanced = true;

	// Create a stack to hold the parentheses, braces, and brackets
	std::stack<char> symbols;


	// Get user input expression until Q is entered
	std::cout << "Input an expression, Q to stop input: ";

	// Scan all characters until sentinel char Q is encountered or the expression is
	// found to be unbalanced
	while (std::cin >> next && balanced == true && next != 'Q')
	{
		if (next == ')')
		{
			if (symbols.empty() || symbols.top() != '(')
				balanced = false;
			else
				symbols.pop();
		}
		else if (next == '}')
		{
			if (symbols.empty() || symbols.top() != '{')
				balanced = false;
			else
				symbols.pop();
		}
		else if (next == ']')
		{
			if (symbols.empty() || symbols.top() != '[')
				balanced = false;
			else
				symbols.pop();
		}
		else if (next == '(')
			symbols.push(next);
		else if (next == '{')
			symbols.push(next);
		else if (next == '[')
			symbols.push(next);
	}

	// Print the results
	if (balanced == true && symbols.empty())
		std::cout << "The expression is balanced!\n";
	else
		std::cout << "The expression is not balanced!\n";

	return 0;
}
