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
class Polygon
{
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
};
