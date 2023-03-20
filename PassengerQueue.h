/*
 *  PassengerQueue.h
 *  SAMMY KAO
 *  2/08/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the interface of the PassengerQueue class
 *
 */

#ifndef __PASSENGERQEUE_H__
#define __PASSENGERQEUE_H__
#include <vector>
#include <string>
#include <iostream>
#include "Passenger.h"
using namespace std;


class PassengerQueue {
public:

    PassengerQueue();
    PassengerQueue(const Passenger &passenger);
    ~PassengerQueue();  
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
    //Using a Passenger vector
    std::vector<Passenger> passengers;
    //integer for station stop (for stations) 
    //or destination stop (for train list)
};

#endif
