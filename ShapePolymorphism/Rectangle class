/* Program: Lab 2 - P-2.5
Author: Aaron Lewis
Class: CSCI 220 MW
Date: 09/10/2017
Description: Create a pure virtual base class Polygon and derive
Rectangle and Triangle classes from it and test it.
I certify that the code below is my own work.
Exception(s): N/A
*/

#pragma once
#include <math.h>
#include "Polygon.h"

// Rectangle class derived from virtual Polygon class
class Rectangle : public Polygon
{

private:
	double base;
	double height;
public:
	Rectangle(double b = 1, double h = 1);
	double area();
	double perimeter();
	void set_base(double b);
	void set_height(double h);
	double get_base();
	double get_height();
};

// Constructor which creates a rectangle object with base b and height h
Rectangle::Rectangle(double b, double h)
{
	base = b;
	height = h;
}

// Returns the area of the rectangle
double Rectangle::area()
{
	return base * height;
}

// Returns the perimeter of the rectangle
double Rectangle::perimeter()
{
	return 2 * base + 2 * height;
}

// Setter for the base attribute
void Rectangle::set_base(double b)
{
	base = b;
}

// Setter for the height attribute
void Rectangle::set_height(double h)
{
	height = h;
}

// Getter for the base
double Rectangle::get_base()
{
	return base;
}

// Getter for the height
double Rectangle::get_height()
{
	return height;
}
