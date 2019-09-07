/*	Program:	Project 1
	Author:		Aaron Lewis
	Class:		CSCI 220 MW
	Date:		09/18/2017
	Description: GameEntry class header file

	I certify that the code below is my own work.

		Exception(s): N/A
*/

#include "GameEntry.h"

GameEntry::GameEntry(string n, int s, string d)
{
	name = n;
	score = s;
	date = d;

}

void GameEntry::set_name(string n)
{
	name = n;
}

void GameEntry::set_date(string d)
{
	date = d;
}

void GameEntry::set_score(int s)
{
	score = s;
}

string GameEntry::get_name()
{
	return name;
}

string GameEntry::get_date()
{
	return date;
}

int GameEntry::get_score()
{
	return score;
}
