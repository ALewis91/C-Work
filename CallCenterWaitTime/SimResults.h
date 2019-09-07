#pragma once

struct SimResults
{
	int total_customers_served;
	double total_wait;
	int total_longest_wait;
	int total_customers_left;
	int total_longest_line;
	int simulation_number;
	SimResults()
	{
		total_customers_served = 0;
		total_longest_wait = 0;
		total_wait = 0;
		total_customers_left = 0;
		total_longest_line = 0;
		simulation_number = 0;

	}
};
