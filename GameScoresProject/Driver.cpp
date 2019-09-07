/*	Program:	Project 1
	Author:		Aaron Lewis
	Class:		CSCI 220 MW	
	Date:		09/10/2017
	Description: Driver to create a GameScore obj through
		file streaming as well as user input and tests
		various GameScore functions and validation.

	I certify that the code below is my own work.

		Exception(s): N/A
*/

#include <iostream>
#include <fstream>
#include "GameEntry.h"
#include "GameScore.h"
#include <fstream>
#include <string>

bool valid_score(int s);
void init_game_score(string file_name, GameScore &obj);
void add_new_score(GameScore &obj);

using namespace std;

int main()
{
	string name;
	string date;
	bool end = false;
	string choice;
	string hiscores_record = "Scores.txt";
	int valid_format = 6;
	GameScore arcade("");
	init_game_score(hiscores_record, arcade);
	
	cout << "Hiscores for " << arcade.get_gname() << endl << endl;
	arcade.print();
	cout << endl << endl;

	while (!end)
	{
		cout << "Options Menu" << endl;
		cout << "   1 - Add new entry" << endl <<
			"   2 - Remove an entry by rank" << endl <<
			"   3 - Remove an entries by date" << endl <<
			"   4 - Print Hiscores" << endl <<
			"   5 - Save Hiscores to file" << endl <<
			"   6 - End" << endl << endl <<
			endl << "Enter choice: ";
		cin >> choice;

		if (choice == "1")
		{
			add_new_score(arcade);
		}
		else if (choice == "2")
		{
			cout << "Enter the rank of the player you wish to remove: ";

			int rank;
			cin >> rank;

			if (!arcade.remove(rank))
				cout << "Please enter a rank 1 - 10!\n";

			cout << endl;

		}
		else if (choice == "3")
		{
			cout << "Enter the cut-off date: ";
			string cut_off_date;
			cin >> cut_off_date;

			if (!arcade.remove(cut_off_date))
				cout << "Please enter the date in the proper format: mm/dd/yyy!\n\n";
			else
				cout << endl;
		}
		else if (choice == "4")
		{
			cout << endl;
			arcade.print();
			cout << endl << endl;
		}
		else if (choice == "5")
		{
			arcade.save_hiscores(hiscores_record);
			cout << endl;
		}
		else if (choice == "6")
		{
			end = true;
		}
		else
		{
			cout << "Invalid Option - Please enter an int 1 - 6!\n";
			cin.ignore(1000, '\n');
			cin.clear();
		}
	}
	return 0;
}


bool valid_score(int score)
{
	if (score > 1000 || score < 0)
		return false;
	else
		return true;
}

void init_game_score(string file_name, GameScore &obj)
{
	string name;
	string date;
	int score;
	int valid_format = 6;
	GameEntry temp;

	fstream record;
	record.open(file_name.c_str());

	if (record.fail())
		cout << "File could not open!\n\n";

	string gameName;
	getline(record, gameName);

	obj.set_name(gameName);

	while (!record.eof())
	{
		name = "!";
		score = -1;
		date = "99999999";
		record >> name >> score >> date;

		if (valid_score(score) && GameScore::valid_date(date))
		{
			temp.set_name(name);
			temp.set_score(score);
			temp.set_date(date);
			obj.add(temp);
		}
	}

	record.close();
}

void add_new_score(GameScore &obj)
{
	string name;
	string date;
	int score;
	int valid_format = 6;
	GameEntry temp;

	cout << setw(25) << "Enter name: ";

	cin >> name;
	cout << setw(25) << "Enter score (1 - 1000): "; 
	cin >> score;


	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "ENTER INTEGER VALUES ONLY!!\n";
		cout << setw(25) << "Enter score: ";
		cin >> score;
	}

	cout << setw(25) << "Enter date (mm/dd/yyyy): ";
	cin >> date;

	temp.set_name(name);
	temp.set_score(score);
	temp.set_date(date);

	if (valid_score(score) == true && GameScore::valid_date(date))
	{
		obj.add(temp);
		cout << endl;
	}
	else if (!valid_score(score))
		cout << "\nInvalid score!\n\n";
	else if (!GameScore::valid_date(date))
		cout << "\nInvalid date format! Please use mm/dd/yyyy format!\n\n";
}
