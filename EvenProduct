/* Program: Lab 1 - C-1.2
Author: Aaron Lewis
Class: CSCI 220
Date: 8/28/2017
Description: C-1.2; write a short C++ function that takes an array of int values
determines if there is a pair of numbers in the array whose product is
even.
I certify that the code below is my own work.
Exception(s): N/A
*/

#include <iostream>
using namespace std;
bool evenProduct(int size, int numarray[])
{
	int pos = 0;
	while (pos < size - 1)
	{
		int next = pos + 1;
		if ((numarray[pos] * numarray[next]) % 2 == 0)
		{
			return true;
		}
		else
		{
			while (next < size - 1)
			{
				next++;
				if ((numarray[pos] * numarray[next]) % 2 == 0)
				{
					return true;
				}
			}
		}
		pos++;
	}
	return false;
}

int main()
{
	cout << "Author: Aaron Lewis\n\n";
	int values[10];
	cout << "Please input 10 integer values: ";
	int newValue;
	for (int i = 0; i < 10; i++)
	{
		cin >> newValue;
		values[i] = newValue;
	}
	cout << endl;
	bool evenProd = evenProduct(10, values);
	if (evenProd == true)
		cout << "\nThere is a pair of integer values which have an "
		<< "even product!\n";
	else
		cout << "\nThere are no pairs of integer values which have an "
		<< "even product!\n";
	return 0;
}
