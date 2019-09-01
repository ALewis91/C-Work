/* Program: Lab 4 P-4.1
Author: Aaron Lewis
Class: CSCI 220
Date: 09/21/2017
Description: This program compares run-time
of two algorithms which calcute and store
prefix average in a new array.
I certify that the code below is my own work.
Exception(s): N/A
*/

#include <iostream>
#include <ctime>
#include <cstdio>
#include "stdafx.h"

using namespace std;
void prefixAverages1(int X[], int size, int A[]);
void prefixAverages2(int X[], int size, int A[]);

int main()
{
	cout << "Author: Aaron Lewis\n\n";

	// Create both arrays of size 100k
	const int MAX_SIZE = 100000;
	int X[MAX_SIZE];
	int A[MAX_SIZE];

	// Initialize array X to random values between 1 and 100
	srand(time(NULL));
	for (int x = 0; x < MAX_SIZE; x++)
	{
		X[x] = rand() % 100 + 1;
	}

	// Grab system time
	clock_t start;
	double duration;
	start = clock();

	// Calculate prefix averages with algorithm 1
	prefixAverages1(X, MAX_SIZE, A);

	// Calculate execution duration of the algorithm
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	// Display results for alg 1
	cout << "Time needed to process 100k elements:\n";
	cout << "Prefix algorithm 1 took: " << duration << " seconds.\n";
	cout << "Average: " << A[MAX_SIZE - 1] << endl;

	// Grab system time
	start = clock();

	// Calculate prefix averages with algorithm 2
	prefixAverages2(X, MAX_SIZE, A);

	// Calculate execution duration of the algorithm
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	// Display results for alg 2
	cout << "Prefix algorithm 2 took: " << duration << " seconds.\n";
	cout << "Average: " << A[MAX_SIZE - 1] << endl;
	return 0;
}
void prefixAverages1(int X[], int size, int A[])
{
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += X[j];
		}
		A[i] = sum / (i + 1);
	}
}
void prefixAverages2(int X[], int size, int A[])
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += X[i];
		A[i] = sum / (i + 1);
	}
}
