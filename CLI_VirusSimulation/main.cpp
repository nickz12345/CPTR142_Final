/*
 * main.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "Person.h"
#include "Ambulance.h"
using namespace std;

// Increase array size
int* doubleCapacity(const int* list, int size)
{
	int arraySize = 2 * size;
	int* temp;
	temp = new int[arraySize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	return temp;
}

int main()
{
	// Check for user OS to see if we need to "pause" at end
	bool windows;
	char userOS;
	cout << "Are you running this program on Windows? (y/n) ";
	cin >> userOS;
	if (userOS == 'y' || userOS == 'Y')
	{
		windows = true;
	}
	if (userOS == 'n' || userOS == 'N')
	{
		windows = false;
	}


	int numPeople;	// Array size
	int count = 0;
	int i;
	int *a; // Will be array a

	cout << "Welcome to VirusSimulation." << endl;
	cout << "How many people do you want in the simulation? ";
	cin >> numPeople;
	// Variable a = new dynamic array of user defined size
	a = new int[numPeople];

	// psuedo code
	// (Maybe we should use vectors to auto - resize instead of arrays)
	int infected;	// When this reaches the same number as the amount of people, simulation ends
	bool run;		// Used for while loop

	while (run == true)
	{
		// Start timer
		clock_t start;
		double duration;

		start = clock();

		// Your algorithm here 
		for (int i = 0; i < arraySize; i++)
		{
			int r1 = rand() % 100;
			if (r1 > 80)	// 20% chance
			{
				// Move person to infected array
				copy[i] to infected array
					infected++;
				break;	// Not sure if I'm using this correctly. Want it to go back to top of while loop.
			}
			else
				continue;

			int r2 = rand() % 100;
			if (rand > 90)	// 10% chance
			{
				// Move infected to ambulance
				copy[i] to ambulance array
					break;
			}
			else
				continue;

			if (infected == numPeople)
			{
				run = false;
			}
		}
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Everyone was infected." << endl;
	cout << "It took " << duration << "s." << endl;




	// Expand array and copy contents of array a into array b
	int *b = doubleCapacity(a, numPeople);
	cout << "\nDebug: The 1st array's values are now in the 2nd expanded array" << endl;

	// User enters data into array b
//    for (i = numPeople; i < 2 * numPeople; i++)
//    {
//        cout << "\nEnter element number " << i + 1 << ": ";
//        cin >> b[i];
//    }

	// Delete data in arrays a and b
	delete[] a;
	delete[] b;


	if (windows == true)
	{
		system("pause");
		return 0;
	}
	else
		return 0;
}
