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

// Triangle class derived from virtual Polygon class
class Triangle : public Polygon
{
private:
	double base;
	double height;
public:
	Triangle(double b = 1, double h = 1);
	double area();
	double perimeter();
	void set_base(double b);
	void set_height(double s);
	double get_base();
	double get_height();
};

// Constructor for triangle sets base to b and height to h
Triangle::Triangle(double b, double h)
{
	base = b;
	height = h;
}

// Returns area of triangle
double Triangle::area()
{
	return height * base / 2;
}

// Returns perimeter of triangle
double Triangle::perimeter()
{
	return 2 * sqrt(base*base + height*height) + base;
}

// Setters for base and height attributes
void Triangle::set_base(double b)
{
	base = b;
}

void Triangle::set_height(double h)
{
	height = h;
}

// Getters for base and height attributes
double Triangle::get_base()
{
	return base;
}

double Triangle::get_height()
{
	return height;
}
