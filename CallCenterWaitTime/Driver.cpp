#include "CallCenter.h"
#include "SimResults.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "TestCaseVars.h"

void initSimVars(TestCaseVars& t);
int validInt();
void printFinished(const CallCenter& cc);
void printStarted(const CallCenter& cc);
void printResults(const CallCenter& cc);
void updateSummary(SimResults& sr, const CallCenter& cc);
void writeReports1(std::ofstream& results, std::ofstream& log, const TestCaseVars& t);
void writeReports2(std::ofstream& log, const TestCaseVars& t, const SimResults& sr);
void writeReports3(std::ofstream& log, const int& minute, const int& customer_number, int estimate, int i);
void writeReports4(std::ofstream& log, const CallCenter& cc);
void writeReports5(std::ofstream& log, const CallCenter& cc);
void writeReports6(std::ofstream& results, const CallCenter& cc, const SimResults& sr);
void writeReports7(std::ofstream& results, const SimResults& sr);
void writeReportNSTR(std::ofstream& log, int min);


int main()
{

	std::cout << "Call Center Simulator\nAuthor: Aaron Lewis\n";
	std::cout << "Look for results in project folder...\n";
	bool done = false;
	bool nstr = true;
	TestCaseVars TestCase;
	std::string response;
	srand((unsigned)time(0));

	std::ofstream result_table;
	result_table.open("Summary.csv");
	result_table << "Summary of Results\n";
	std::ofstream event_log;
	event_log.open("Event_log.csv");
	event_log << "Event Log\n";

	while (!done)
	{
		int call_time;
		int time_finished;
		int customer_number;
		SimResults summary;
		initSimVars(TestCase);
		int estimate;
		writeReports1(result_table, event_log, TestCase);

		for (int x = 0; x < TestCase.number_of_sims; x++)
		{
			CallCenter CustomerService(TestCase.number_of_reps);
			CustomerService.set_shift_length(TestCase.length_of_sim);
			call_time = rand() % TestCase.call_rate + 1;
			customer_number = 1;
			summary.simulation_number++;
			writeReports2(event_log, TestCase, summary);

			for (int minute = 1; minute <= TestCase.length_of_sim; minute++)
			{
				nstr = true;
				if (minute <= 15 || minute >= TestCase.length_of_sim - 15)
					event_log  << minute;

				if (minute == call_time)
				{
					int index = CustomerService.enqueue(customer_number, minute);
					int offset = CustomerService.repIsBusy(index) ? 1 : 0;
					estimate = (int)(((TestCase.call_rate + 1) / 2.0)*(CustomerService.size(index)+offset));
					
					if (minute <= 15 || minute >= TestCase.length_of_sim - 15)
					{
						writeReports3(event_log, minute, customer_number, estimate, index);
					}
					call_time = rand() % TestCase.call_rate + 1 + minute;
					customer_number++;		
					nstr = false;
				}
				if (CustomerService.finish_serv(minute))
				{
					if (minute <= 15 || minute >= TestCase.length_of_sim - 15)
					{
						writeReports4(event_log, CustomerService);
					}
					nstr = false;
				}

				if (CustomerService.start_serv())
				{
					for (int x = 0; x < TestCase.number_of_reps; x++)
					{
						if (CustomerService.repStarted(x) == true)
						{
							time_finished = minute + rand() % TestCase.service_rate + 1;
							CustomerService.set_time_finished(x, time_finished);
						}
					}
					if (minute <= 15 || minute >= TestCase.length_of_sim - 15)
					{
						writeReports5(event_log, CustomerService);
					}
					nstr = false;
				}
				if (nstr && (minute <= 15 || minute >= TestCase.length_of_sim - 15))
					writeReportNSTR(event_log, minute);
			}
			writeReports6(result_table, CustomerService, summary);
			updateSummary(summary, CustomerService);
		}
		writeReports7(result_table, summary);
		TestCase.test_case_number++;
		
		std::cout << "Simulation Complete!\n";
		std::cout << "Check Event_log.csv and Summary.csv for results...\n";
		std::cout << "Would you like to add another test case? (Enter y to continue): ";
		std::getline(std::cin,response);
		if (response != "y" && response != "Y")
			done = true;
	}
	return 0;
}

void initSimVars(TestCaseVars& t)
{
	std::cout << "\nEnter the number of representatives: ";
	t.number_of_reps= validInt();
	std::cout << "Enter the length of the sim(minutes): ";
	t.length_of_sim = validInt();
	std::cout << "Enter the call rate: ";
	t.call_rate = validInt();
	std::cout << "Enter the service rate: ";
	t.service_rate = validInt();
	std::cout << "Enter the number of simulations with these parameters: ";
	t.number_of_sims = validInt();

}

void printFinished(const CallCenter& cc)
{
	for (int x = 0; x < cc.get_num_agents(); x++)
	{
		if (cc.repFinished(x) == true)
		{
			std::cout << "\tRepresentative #" << x + 1 << " has finished assisting ";
			std::cout << "customer #" << cc.get_current_assist_ID(x) << std::endl;
		}
	}
}

void printStarted(const CallCenter& cc)
{
	for (int x = 0; x < cc.get_num_agents(); x++)
	{
		if (cc.repStarted(x) == true)
		{
			std::cout << "\tRepresentative #" << x + 1 << " has started assisting ";
			std::cout << "customer #" << cc.get_current_assist_ID(x) << std::endl;
			std::cout << "\tCustomer #" << cc.get_current_assist_ID(x) << " had been";
			std::cout << " waiting " << cc.get_current_wait_time(x) << " minutes\n";
		}
	}
}

void printResults(const CallCenter& cc)
{
	std::cout << "\nNumber of Customers Served: " << cc.get_customers_served();
	std::cout << "\nNumber of Customers left:   " << cc.get_customers_left();
	std::cout << "\nLongest Line:               " << cc.get_longest_line();
	std::cout << "\nThe longest wait time is:   " << cc.get_longest_wait();
	std::cout << "\nThe average wait time is:   " << std::setprecision(2) 
		<< cc.get_average_wait_time() << std::endl;
}

int validInt()
{
	int value = 0;
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::stringstream lstream(line);
		if (!(lstream >> value))
		{
			std::cout << "Error: input not an integer\n";
			std::cout << "Enter a positive integer value greater than 0: ";
			continue;
		}
		if ((value < 1))
		{
			std::cout << "Error: input must be greater than 0\n";
			std::cout << "Enter a positive integer value greater than 0: ";

			continue;
		}
		char extra;
		if (lstream >> extra)
		{
			std::cout << "Error: more than one input\n";
			std::cout << "Enter a positive integer value greater than 0: ";
			continue;
		}

		return value;
	}
}

void writeReports1(std::ofstream& results, std::ofstream& log, const TestCaseVars& t)
{

	results << "\nTest Case #" << t.test_case_number;
	results << ",Number of Reps,Duration(mins),Call Rate,Service Rate\n";
	results << "," << t.number_of_reps;
	results << "," << t.length_of_sim;
	results << "," << t.call_rate;
	results << "," << t.service_rate << std::endl;
	results << ",Simulation #,Customers Served,Customers Left Enqueued,";
	results << "Longest Line,Longest Wait(mins),Average Wait(mins)\n\n";

	log << "\n,Test Case #" << t.test_case_number;
	log << "   # of Reps: " << t.number_of_reps;
	log << "   Length of Sim(minutes): " << t.length_of_sim;
	log << "   Call Rate: " << t.call_rate;
	log << "   Service Rate: " << t.service_rate;
}

void writeReports2(std::ofstream& log, const TestCaseVars& t, const SimResults& sr)
{
	log << "\n\nSimulation #" << sr.simulation_number;
	log << "\nMinute,Events\n";
}

void writeReports3(std::ofstream& log, const int& minute, const int& customer_number, int estimate, int i)
{
	log <<  ",Customer #" << customer_number << " called\n";
	log << "," << "Customer #" << customer_number << " was placed on hold ";
	log << "with Representative # " << i + 1 << std::endl;
	log << ",Customer #" << customer_number << " has an estimated wait time of "
		<< estimate << " minutes\n";
}

void writeReports4(std::ofstream& log, const CallCenter& cc)
{
	for (int x = 0; x < cc.get_num_agents(); x++)
	{
		if (cc.repFinished(x) == true)
		{
			log << ",Representative #" << x + 1 << " has finished assisting ";
			log << "customer #" << cc.get_current_assist_ID(x) << std::endl;
		}
	}
}

void writeReports5(std::ofstream& log, const CallCenter& cc)
{
	for (int x = 0; x < cc.get_num_agents(); x++)
	{
		if (cc.repStarted(x) == true)
		{
			log << ",Representative #" << x + 1 << " has started assisting ";
			log << "customer #" << cc.get_current_assist_ID(x) << std::endl;
			log << ",Customer #" << cc.get_current_assist_ID(x) << " had been";
			log << " waiting " << cc.get_current_wait_time(x) << " minutes\n";
		}
	}
}

void writeReports6(std::ofstream& results, const CallCenter& cc, const SimResults& sr)
{
	results << "," << sr.simulation_number;
	results << "," << cc.get_customers_served();
	results << "," << cc.get_customers_left();
	results << "," << cc.get_longest_line();
	results << "," << cc.get_longest_wait();
	results << "," << std::fixed << std::setprecision(2) << cc.get_average_wait_time();
	results << "\n";
}

void writeReports7(std::ofstream& results, const SimResults& sr)
{
	results << "\n,Sim Average Results";
	results << "," << sr.total_customers_served / sr.simulation_number;
	results << "," << sr.total_customers_left / sr.simulation_number;
	results << ","<< sr.total_longest_line / sr.simulation_number;
	results << ","<< sr.total_longest_wait / sr.simulation_number;
	results << ","<< std::fixed << std::setprecision(2) << (sr.total_wait / sr.simulation_number);
	results << "\n";
}


void updateSummary(SimResults& sr, const CallCenter& cc)
{
	sr.total_customers_served += cc.get_customers_served();
	sr.total_customers_left += cc.get_customers_left();
	sr.total_wait += cc.get_average_wait_time();
	sr.total_longest_line += cc.get_longest_line();
	sr.total_longest_wait += cc.get_longest_wait();
}

void writeReportNSTR(std::ofstream& log, int min)
{
	log << ",NSTR\n";
}
