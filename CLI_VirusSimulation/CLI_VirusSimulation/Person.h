/*
 * Person.h
 *
 *  Created on: Feb 24, 2017
 *      Author: nicholas.zimmerman
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Person
{
public:
int natImmunity;
int health;
int strain;

//Default constructor
Person() {
	natImmunity = rand() % 10;
	
	if(rand() % 100 <= 10)
	{
		health = 0;
		strain = ((rand() % 4)+1);	//levels 1-4 are stain strengths; 0 means no strain multiplier
	}
	else { 
		health = 1;
		strain = 0;
	     }
}

//Constructor given health probablility
Person(double prob) {		//prob entered as 0-100; likelihood of disease at startup
	
	if(rand() % 101 <= prob)	//rand produces 0-100
	{
		health = 0;
		strain = ((rand() % 4)+1);	//levels 1-4 are stain strengths; 0 means no strain multiplier
	}
	else { 
		health = 1;
		strain = 0;
	     }
}
	
//Full-control constructor
Person(int nat,int h, int s) {
	natImmunity = nat;		//0-9
	health = h;			//0-3
	strain = s;			//0-4
}


};



#endif /* PERSON_H_ */
