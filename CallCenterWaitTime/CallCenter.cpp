#pragma once
#include "CallCenter.h";


CallCenter::CallCenter(int num_agents = 1)
{
	number_of_agents = num_agents;
	longest_line = 0;
	longest_wait_time = 0;
	shift_length = 0;
	total_wait_time = 0;
	average_wait_time = 0;
	current_time = 1;
	customers_served = 0;

	for (int x = 0; x < number_of_agents; x++)
		office.push_back(serviceDesk());
}

CallCenter::~CallCenter()
{
	office.empty();
}

int CallCenter::size(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].onhold.size();
	else
		return 0;
}

int CallCenter::enqueue(int ID, int callT)
{
	int shortest_index = 0;

	for (int x = 0; x < number_of_agents; x++)
	{
		if (office[x].repIsBusy == false)
		{
			shortest_index = x;
			x = number_of_agents;
		}
		else if (office[x].onhold.size() < office[shortest_index].onhold.size())
			shortest_index = x;
	}
	office[shortest_index].onhold.enqueue(ID, callT);

	if (office[shortest_index].onhold.size() > longest_line)
		longest_line = office[shortest_index].onhold.size();

	return shortest_index;
}

bool CallCenter::finish_serv(int min)
{
	bool some_finished = false;
	current_time = min;
	for (int x = 0; x < number_of_agents; x++)
	{
		office[x].finished = false;

		if (office[x].repIsBusy == true)
		{
			if (office[x].time_finished == current_time)
			{
				office[x].finished = true;
				customers_served++;
				office[x].repIsBusy = false;
				some_finished = true;
			}
		}
	}
	return some_finished;
}

bool CallCenter::start_serv()
{
	bool some_started = false;
	if (current_time < shift_length)
	{
		for (int x = 0; x < number_of_agents; x++)
		{
			office[x].started = false;
			if (office[x].repIsBusy == false)
			{
				if (office[x].onhold.size() > 0)
				{
					office[x].current_assist_ID = office[x].onhold.frontID();

					if (current_time - office[x].onhold.frontCallTime() > longest_wait_time)
						longest_wait_time = current_time - office[x].onhold.frontCallTime();

					office[x].current_wait_time = current_time - office[x].onhold.frontCallTime();
					total_wait_time += current_time - office[x].onhold.frontCallTime();
					office[x].started = true;
					office[x].onhold.dequeue();
					office[x].repIsBusy = true;
					some_started = true;
				}
			}
		}
	}
	return some_started;
}

int CallCenter::get_num_agents() const
{
	return number_of_agents;
}
int CallCenter::get_current_assist_ID(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].current_assist_ID;
	else
		return -1;
}
int CallCenter::get_current_wait_time(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].current_wait_time;
	else
		return -1;
}

void CallCenter::set_time_finished(int i, int time)
{
	if (i >= 0 && i < number_of_agents)
	{
		office[i].time_finished = time;
	}
}

void CallCenter::set_shift_length(int s)
{
	if (s > 0)
		shift_length = s;
}

bool CallCenter::repFinished(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].finished;
	else
		return false;
}

bool CallCenter::repStarted(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].started;
	else
		return false;
}

int CallCenter::get_longest_line() const
{
	return longest_line;
}
int CallCenter::get_longest_wait() const
{
	return longest_wait_time;
}
double CallCenter::get_average_wait_time() const
{
	return total_wait_time / (get_customers_served() * 1.0);
}

int CallCenter::get_customers_left() const
{
	int sum = 0;

	for (int x = 0; x < number_of_agents; x++)
	{
		sum += office[x].onhold.size();
	}

	return sum;
}

int CallCenter::get_customers_served() const
{

	int sum = 0;

	for (int x = 0; x < number_of_agents; x++)
	{
		if (office[x].repIsBusy)
			sum++;
	}

	return sum + customers_served;
}

bool CallCenter::repIsBusy(int i) const
{
	if (i >= 0 && i < number_of_agents)
		return office[i].repIsBusy;
	else
		return false;
}
