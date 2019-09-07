/*	Program:	Project 1
	Author:		Aaron Lewis
	Class:		CSCI 220 MW
	Date:		09/18/2017
	Description: GameScore class implementation file

	I certify that the code below is my own work.

		Exception(s): N/A
*/

#include "GameScore.h"

GameScore::GameScore(string gn)
{
	for (int x = 0; x < MAX_ENTRIES; x++)
	{
		hiscores[x].set_score(-1);
	}

	game_name = gn;
}

bool GameScore::add(GameEntry new_score)
{
	for (int x = 0; x < MAX_ENTRIES; x++)
	{
		if (new_score.get_score() > hiscores[x].get_score())
		{
			for (int i = 9; i > x; i--)
			{
				hiscores[i].set_name(hiscores[i - 1].get_name());
				hiscores[i].set_date(hiscores[i - 1].get_date());
				hiscores[i].set_score(hiscores[i - 1].get_score());
			}
			hiscores[x].set_name(new_score.get_name());
			hiscores[x].set_date(new_score.get_date());
			hiscores[x].set_score(new_score.get_score());

			return true;
		}
	}

	return false;
}

bool GameScore::remove(int r)
{
	int index = r - 1;

	if (index < 0 || index >= MAX_ENTRIES)
	{
		return false;
	}
	else
	{
		for (int x = index; x < 9; x++)
		{
			hiscores[x].set_date(hiscores[x + 1].get_date());
			hiscores[x].set_name(hiscores[x + 1].get_name());
			hiscores[x].set_score(hiscores[x + 1].get_score());
		}
		hiscores[9].set_date("01/01/2017");
		hiscores[9].set_name("");
		hiscores[9].set_score(-1);
	}
	return true;
}

void GameScore::print()
{
	cout << "Name: " << game_name << endl;
	for (int x = 0; x < 10; x++)
	{
		if (hiscores[x].get_score() >= 0)
		{
			cout << x + 1  << " " << left << setw(11) 
				<< hiscores[x].get_name() << setw(7) 
				<< hiscores[x].get_score() << setw(13) 
				<< hiscores[x].get_date() << endl;
		}
	}
}

string GameScore::get_gname()
{
	return game_name;
}

string GameScore::get_name(int r)
{
	if (r > 0 && r < 10)
		return hiscores[r - 1].get_name();
	else
		return "";
}

string GameScore::get_date(int r)
{
	if (r > 0 && r < 10)
		return hiscores[r - 1].get_date();
	else
		return "";
}

int GameScore::get_score(int r)
{
	if (r > 0 && r < 10)
		return hiscores[r - 1].get_score();
	else
		return -1;
}

void GameScore::save_hiscores(string file_name)
{
	ofstream out;
	out.open(file_name.c_str());

	out << game_name << endl;

	for (int x = 0; x < 10; x++)
	{
		if (hiscores[x].get_score() > 0)
		{
			out << left << setw(16) << hiscores[x].get_name()
				<< setw(10) << hiscores[x].get_score()
				<< setw(14) << hiscores[x].get_date() << endl;
		}
	}
	out.close();
}

bool GameScore::remove(string d)
{
	int cut_off_year;
	int cut_off_month;
	int cut_off_day;


	int score_year;
	int score_month;
	int score_day;
	if (valid_date(d))
	{

		cut_off_year = stoi(d.substr(6, 4));
		cut_off_day = stoi(d.substr(3, 2));
		cut_off_month = stoi(d.substr(0, 2));

		for (int x = 0; x < MAX_ENTRIES; x++)
		{
			score_year = stoi(hiscores[x].get_date().substr(6, 4));
			score_day = stoi(hiscores[x].get_date().substr(3, 2));
			score_month = stoi(hiscores[x].get_date().substr(0, 2));
			
			if (score_year < cut_off_year)
			{
				remove(x + 1);
				x--;
			}
			else if (score_year == cut_off_year)
			{
				if (score_month < cut_off_month)
				{
					remove(x + 1);
					x--;
				}
				else if (score_month == cut_off_month)
				{
					if (score_day < cut_off_day)
					{
						remove(x + 1);
						x--;
					}
				}
			}
		}
		return true;
	}
	else
		return false;
}

void GameScore::set_name(string name)
{
	game_name = name;
}

bool GameScore::valid_date(string d)
{
	if (d.length() != 10)
	{
		return false;
	}

	int month = stoi(d.substr(0, 2));
	int day = stoi(d.substr(3, 2));
	int year = stoi(d.substr(6, 4));

	if (month < 1 || month > 12)
	{
		return false;
	}
	else if (day < 1 || day > 31)
	{
		return false;
	}
	else if (month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10
		|| month == 12)
	{
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (month == 2 && day > 28)
	{
		return false;
	}
	else if (month == 4 || month == 6 || month == 9
		|| month == 11)
	{

		if (day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (year > 2017 || year < 2000)
	{
		return false;
	}
	else if (d.substr(2, 1) != "/" ||
		d.substr(5, 1) != "/")
	{
		return false;
	}
	else
		
		return true;
}
