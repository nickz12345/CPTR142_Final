/*
 * main.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Person.h"
#include "Ambulance.h"
using namespace std;
using namespace this_thread;
using namespace chrono;


int main()
{
	// Check for user OS to see if we need to "pause" at end
//	bool windows;
//	char userOS;
//	cout << "Are you running this program on Windows? (y/n) ";
//	cin >> userOS;
//	if (userOS == 'y' || userOS == 'Y')
//	{
//		windows = true;
//	}
//	if (userOS == 'n' || userOS == 'N')
//	{
//		windows = false;
//	}


	int userNumPeople;	// Array size
	//int *a; // Will be array a

	cout << "Welcome to VirusSimulation." << endl;
	cout << "How many people do you want in the simulation? ";
	cin >> userNumPeople;
	// Variable a = new dynamic array of user defined size
	//a = new int[numPeople];
    vector<int> numPeople(userNumPeople);
    cout << "vector numPeople holds: " << numPeople.size() << " elements" << endl;
    
	// (Maybe we should use vectors to auto - resize instead of arrays)
	int infected = 0;	// When this reaches the same number as the amount of people, simulation ends
	bool run = true;		// Used for while loop
    
    // Start timer
    clock_t start;
    double duration;
    
    vector<int> infectedVec;
    vector<int> ambulanceVec;
    
    start = clock();
    
	while (run == true)
	{
		// Your algorithm here 
		for (int i = 0; i < userNumPeople; i++)
		{
			int r1 = rand() % 100;
			if (r1 > 80)	// 20% chance
			{
				// Move person to infected array
				// copy[i] to infected array
                // (Do we even need to do this step? Why do we need arrays in
                // addition to the infected variable?)
                infectedVec.push_back(1);
                infected++;
                cout << "1 person was infected" << endl;
                //sleep_for(10ns);
				continue;	// Move to top of while loop
			}

			int r2 = rand() % 100;
			if (r2 > 90)	// 10% chance
			{
				// Move infected to ambulance
                ambulanceVec.push_back(1);
                int r3 = rand() % 100;
                if (r3 > 50)
                {
                    ambulanceVec.clear();
                    numPeople.push_back(1);    // Add 1
                    cout << "Someone was saved by the abulance." << endl;
                }
                continue;
			}


			if (infected == userNumPeople)
			{
				run = false;
			}
		}
	}
    
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Everyone was infected." << endl;
	cout << "It took " << duration << " seconds." << endl;


//	if (windows == true)
//	{
//		system("pause");
//		return 0;
//	}
//	else
//		return 0;
}
