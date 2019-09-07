/*	Program:	Project 1
	Author:		Aaron Lewis
	Class:		CSCI 220 MW
	Date:		09/18/2017
	Description: GameEntry class header file

	I certify that the code below is my own work.
		
		Exception(s): N/A
*/

#pragma once
#include <string>

using namespace std;

class GameEntry
{
private:
	string name;
	int score;
	string date;

public:
	GameEntry(string n = "", int s = 0, string d = "01/01/2017");
	void set_name(string n);
	void set_date(string d);
	void set_score(int s);
	string get_name();
	string get_date();
	int get_score();
};

