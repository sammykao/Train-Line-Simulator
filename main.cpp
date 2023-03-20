/*
 *  Main.cpp
 *  SAMMY KAO
 *  2/11/2023
 *
 *  CS 15 PROJ1 MetroSim
 *
 *  This file is the main file running
 *  of the Metro SImulation. It acts as
 *  the finalized program
 *  
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" << endl;
    } else if (argc == 3) {
        //No input command file
        MetroSim simulator(argv[1]);
        simulator.runSim(std::cin, argv[2]);
    } else if (argc == 4) {
        MetroSim simulator(argv[1]);
        ifstream infile;
        simulator.test_open(infile, argv[3]);
        simulator.runSim(infile, argv[2]);
        infile.close();
    }
    
    
    return 0;
}
