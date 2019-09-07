/*	Program:	Project 1
	Author:		Aaron Lewis
	Class:		CSCI 220 MW
	Date:		09/18/2017
	Description: GameScore class header file

	I certify that the code below is my own work.

		Exception(s): N/A
*/

#pragma once
#include "GameEntry.h"
#include <iomanip>
#include <iostream>
#include <fstream>

class GameScore
{
private:
	string game_name;
	static const int MAX_ENTRIES = 10;
	const int SCORE_MAX = 1000;
	const int SCORE_MIN = 0;
	GameEntry hiscores[MAX_ENTRIES];
public:
	GameScore(string gn = "");
	bool add(GameEntry new_score);
	bool remove(int r);
	void print();
	bool remove(string d);
	void set_name(string name);
	string get_gname();
	string get_name(int r);
	int get_score(int r);
	string get_date(int r);
	void save_hiscores(string file_name);
	static bool valid_date(string d);
};
