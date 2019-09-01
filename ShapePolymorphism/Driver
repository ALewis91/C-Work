/* Program: Lab 2 - P-2.5
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 09/10/2017
Description: Create a pure virtual base class Polygon and derive
Rectangle and Triangle classes from it and test it below.
I certify that the code below is my own work.
Exception(s): N/A
*/

#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;
int main()
{
	cout << "Author: Aaron Lewis\n\n";
	Rectangle r1;
	Triangle t1;
	double rbase;
	double rheight;
	double tbase;
	double theight;
	cout << "The base for the default rectangle is: "
		<< r1.get_base() << endl;
	cout << "The height for the default rectangle is: "
		<< r1.get_height() << endl;
	cout << "The area for the default rectangle is: "
		<< r1.area() << endl;
	cout << "The perimeter for the default rectangle is: "
		<< r1.perimeter() << endl << endl;
	cout << "The base for the default triangle is: "
		<< t1.get_base() << endl;
	cout << "The height for the default triangle is: "
		<< t1.get_height() << endl;
	cout << "The area for the default triangle is: "
		<< t1.area() << endl;
	cout << "The perimeter for the default triangle is: "
		<< t1.perimeter() << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the base for a new rectangle: ";
		cin >> rbase;
		cout << "Enter the height for the new rectangle: ";
		cin >> rheight;
		r1.set_base(rbase);
		r1.set_height(rheight);
		cout << "The base for the new rectangle is: "
			<< r1.get_base() << endl;
		cout << "The height for the new rectangle is: "
			<< r1.get_height() << endl;
		cout << "The area for the new rectangle is: "
			<< r1.area() << endl;
		cout << "The perimeter for the new rectangle is: "
			<< r1.perimeter() << endl << endl;
		cout << "Enter the base for a new triangle: ";
		cin >> tbase;
		cout << "Enter the height for the new triangle: ";
		cin >> theight;
		t1.set_base(tbase);
		t1.set_height(theight);
		cout << "The base for the new triangle is: "
			<< t1.get_base() << endl;
		cout << "The height for the new triangle is: "
			<< t1.get_height() << endl;
		cout << "The area for the new triangle is: "
			<< t1.area() << endl;
		cout << "The perimeter for the new triangle is: "
			<< t1.perimeter() << endl << endl;
	}
}
