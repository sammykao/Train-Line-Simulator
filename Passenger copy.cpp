/*
 *  Passenger.cpp
 *  SAMMY KAO
 *  2/08/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the implementation of the Passenger class
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;
/*
 * name:      print()
 * purpose:   print a passenger's info
 * arguments: an output stream
 * returns:   none
 * effects:   prints message through inputted ostream
 */
void Passenger::print(std::ostream &output)
{
    output << "[" << id << ", " << from << "->" << to << "]";
}
