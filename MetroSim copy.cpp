/*
 *  MetroSim.cpp
 *  SAMMY KAO
 *  2/11/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the implementation of the MetroSim class
 *
 */

#include "MetroSim.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;


/*
 * name:      MetroSim()
 * purpose:   MetroSim constructor
 * arguments: a string filename to open stations file
 * returns:   none
 * effects:   initializes a stations vector and 
 *            an empty train vector
 */
MetroSim::MetroSim(std::string filename) {
    ifstream infile;
    test_open(infile, filename);
    std::string curr_line;
    while(getline(infile, curr_line)) {
        Station s(curr_line);
        stations.push_back(s);
        PassengerQueue p;
        train.push_back(p);
    }
    traincount = 0;
    idcount = 1;
    infile.close();
}

/*
 * name:      ~MetroSim()
 * purpose:   MetroSim destructor
 * arguments: none
 * returns:   none
 * effects:   vectors do all the deleting for us
 */
MetroSim::~MetroSim() { }


/*
 * name:      runSim()
 * purpose:   User Query function to run the simulation
 * arguments: a string filename to open output file
              and an input stream
 * returns:   none
 * effects:   runs until user inputs mf
 */
void MetroSim::runSim(std::istream &input, std::string filename) {
    ofstream outfile;
    test_open(outfile, filename);
    char input1 = ' ';
    char input2 = ' ';
    int arrival, destination;
    while (!(input1 == 'm' and input2 == 'f')) {
        printSim(std::cout);
        input >> input1;
        if (input1 == 'm') {
            input >> input2;
            if (input1 == 'm' and input2 == 'm') {
                moveMetro(outfile);
            }
        } else if (input1 == 'p') {
            input >> arrival >> destination;
            if (arrival >= stations.size() or
                destination >= stations.size()) {
                    cerr << "Not valid arrival or destination" << endl;
                    exit(EXIT_FAILURE);
                }
            insertPassenger(arrival, destination);
        }
    }
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    outfile.close();
}




/*
 * name:      moveMetro()
 * purpose:   move the train and dequeue and enqueue
              onboarding and deboarding passengers
 * arguments: output file to write to if passengers
              arrive at destination
 * returns:   none
 * effects:   none
 */
void MetroSim::moveMetro(std::ostream &output) {
    int tempsize = stations[traincount].line.size();
    for (int i=0; i<tempsize; i++) {
        Passenger p = stations[traincount].line.front();
        stations[traincount].line.dequeue();
        train[p.to].enqueue(p);
    }
    traincount++;
    if (traincount == stations.size()) {
        traincount = 0;
    }  
    tempsize = train[traincount].size();
    for (int i=0; i<tempsize; i++) {
        Passenger p = train[traincount].front();
        output << "Passenger " << p.id << " left train at station ";
        output << stations[traincount].name << endl;
        train[traincount].dequeue();
    }

}


/*
 * name:      insertPassenger()
 * purpose:   inserts passengers waiting for train
 * arguments: departure integer and arrival integer
 * returns:   none
 * effects:   none
 */
void MetroSim::insertPassenger(int from, int to) {
    Passenger p(idcount, from, to);
    stations[from].line.enqueue(p);
    idcount++;
}


/*
 * name:      printSim()
 * purpose:   Prints the simulation for front end
              interface
 * arguments: output stream to write out to
 * returns:   none
 * effects:   none
 */
void MetroSim::printSim(std::ostream &output) {
    output << "Passengers on the train: {";
    for (int i=0; i<train.size(); i++) {
        train[i].print(output);
    }
    output << "}" << endl;
    for (int i=0; i<stations.size(); i++) {
        if (traincount == i) {
            output << "TRAIN: ";
        } else {
            output << "       ";
        }
        output << "[" << i << "] " << stations[i].name;
        output << " {";
        stations[i].line.print(output);
        output << "}" << endl;
    }
    output << "Command? ";
}


/*
 * name:      test_open()
 * purpose:   open a file and see if it fails opening
 * arguments: stream type to open and its name
 * returns:   none
 * effects:   none
 */
template<typename streamtype>
void MetroSim::test_open(streamtype &stream, std::string file_name) {
    stream.open(file_name);
    if (not stream.is_open()) {
        std::cerr << "Error: could not open file " << file_name << endl;
        exit(EXIT_FAILURE);
    }
}