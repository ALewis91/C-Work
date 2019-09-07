#pragma once

struct TestCaseVars
{
	int test_case_number;
	int number_of_reps;
	int length_of_sim;
	int call_rate;
	int service_rate;
	int number_of_sims;

	TestCaseVars()
	{
		test_case_number = 1;
	}
};
