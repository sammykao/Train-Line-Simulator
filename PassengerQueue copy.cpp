/*
 *  PassengerQueue.cpp
 *  SAMMY KAO
 *  2/08/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the implementation of the 
 *  PassengerQueue class
 */



#include "PassengerQueue.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/*
 * name:      PassengerQueue constructor
 * purpose:   initialize an empty PassengerQueue
 * arguments: none
 * returns:   none
 * effects:   No work is needed to be done because
 * the Passenger vector will be initialized by itself
 */
PassengerQueue::PassengerQueue() { }

/*
 * name:      PassengerQueue constructor
 * purpose:   initialize a single passenger PassengerQueue
 * arguments: passenger
 * returns:   none
 * effects:   none
 */
PassengerQueue::PassengerQueue(const Passenger &passenger) {
    passengers.push_back(passenger);
}

/*
 * name:      PassengerQueue destructor
 * purpose:   destruct the PassengerQueue when out of scope
 * arguments: none
 * returns:   none
 * effects:   No work is needed to be done because
 * the Passenger vector will be destroyed by itself
 */
PassengerQueue::~PassengerQueue() { }

/*
 * name:      front()
 * purpose:   To retrieve the front of the PassengerQueue
 * arguments: none
 * returns:   The front Passenger
 * effects:   throws error if it is empty
 */
Passenger PassengerQueue::front() {
    if (passengers.empty()) {
        throw std::runtime_error("cannot get front of empty queue");
    }
    return (passengers.front());
}


/*
 * name:      Dequeue
 * purpose:   Dequeue the front of the PassengerQueue
 * arguments: none
 * returns:   none
 * effects:   Call upon vector implementation and 
 * throws error if empty.
 */
void PassengerQueue::dequeue() {
    if (passengers.empty()) {
        throw std::runtime_error("cannot dequeue an empty queue");
    }
    //catching any errors
    passengers.erase(passengers.begin());
}

/*
 * name:      Dequeue
 * purpose:   Dequeue the front of the PassengerQueue
 * arguments: none
 * returns:   none
 * effects:   Call upon vector implementation and 
 * throws error if empty.
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengers.push_back(passenger);
}

/*
 * name:      size()
 * purpose:   Retrieve the size of our PassengerQueue
 * arguments: none
 * returns:   Size integer
 * effects:   Call upon vector implementation
 */
int PassengerQueue::size() {
    return passengers.size();
}

/*
 * name:      print()
 * purpose:   Print out our PassengerQueue
 * arguments: output stream
 * returns:   none
 * effects:   each passenger has their own 
 * print function so calls upon that
 */
void PassengerQueue::print(std::ostream &output) {
    for (int i=0; i<passengers.size(); i++) {
        passengers[i].print(output);
    }
}

