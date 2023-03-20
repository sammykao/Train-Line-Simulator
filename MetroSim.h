/*
 *  MetroSim.h
 *  SAMMY KAO
 *  2/11/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the interface of the MetroSim class
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include "PassengerQueue.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;
// Put any other structs you need here
// Stations struct 
struct Station{
    Station(string newName) {
        name = newName;
    }
    std::string name;
    PassengerQueue line;
};

class MetroSim {
public:
    MetroSim(std::string filename);
    ~MetroSim();
    void runSim(std::istream &input, std::string filename);
    void moveMetro(std::ostream &output);
    void insertPassenger(int from, int to);
    void printSim(std::ostream &output);
    template<typename streamtype>
    void test_open(streamtype &stream, std::string file_name);
private:
    std::vector<PassengerQueue> train;
    std::vector<Station> stations;
    int traincount;
    //tracker of train to work with
    //station s vector


    //Id count for passenger id
    int idcount;
};

#endif
