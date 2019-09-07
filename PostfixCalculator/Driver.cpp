/*
	Program:	Project 2
	Author:		Aaron Lewis
	Class:		CSCI 220 MW
	Date:	
	Description: Driver which tests the Calculator class
		objects and the contained Stack class.

	I certify that the code below is my own work.

	Exception(s) : N / A
*/

#pragma once
#include <iostream>
#include <string>
#include "Calculator.h"

int main()
{
	std::cout << "Author: Aaron Lewis\n\n";
	Calculator calc;
	std::string error;
	std::string expression;
	std::cout << "~!Aaron's Calculator!~\n\n";
	std::cout << "Input an expression: ";
	std::getline(std::cin, expression);
	while (expression != "0")
	{
		if (calc.validFormat(expression, error))
		{
			std::cout << "Postfix form: " << calc.toPostfix(expression) << std::endl;
			std::cout << "Solution: " << calc.calculate() << std::endl;
		}
		else
			std::cout << error;

		std::cout << "\nEnter a new expression or \"0\" to quit : ";
		std::getline(std::cin, expression);
	}


	return 0;
}
