#pragma once
#include "LinkedQueue.h"
#include <vector>
#include <iostream>

class CallCenter
{
private:
	struct serviceDesk
	{
		LinkedQueue onhold;
		bool repIsBusy;
		bool started;
		bool finished;
		int current_assist_ID;
		int time_finished;
		int current_wait_time;

		serviceDesk()
		{
			repIsBusy = false;
			started = false;
			finished = false;
			current_assist_ID = 0;
			time_finished = 0;
			current_wait_time = 0;
		}
	};

	std::vector<serviceDesk> office;
	int number_of_agents;
	int longest_line;
	int longest_wait_time;
	int customers_served;
	int shift_length;
	int total_wait_time;
	int average_wait_time;
	int current_time;
public:
	CallCenter(int num_agents);
	~CallCenter(); 
	int size(int i) const;
	int enqueue(int ID, int callT);
	bool finish_serv(int min);
	bool start_serv();
	void set_time_finished(int i, int time);
	void set_shift_length(int s);
	int get_num_agents() const;
	int get_current_assist_ID(int i) const;
	int get_current_wait_time(int i) const;
	bool repFinished(int i) const;
	bool repStarted(int i) const;
	bool repIsBusy(int i) const;
	int get_longest_line() const;
	int get_longest_wait() const;
	int get_customers_left() const;
	int get_customers_served() const;
	double get_average_wait_time() const;
};
