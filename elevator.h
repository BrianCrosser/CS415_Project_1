//
// Created by Brian on 9/8/2015.
//

#ifndef CS415_PROJECT_1_ELEVATOR_H
#define CS415_PROJECT_1_ELEVATOR_H
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

class Elevator {
public:
    int id;
    int level;
    string direction;
    vector<int> instruction;

    int createElevator(vector<Elevator> &L);

    int printStats(vector<Elevator> &elist);

    int addInstruction(vector<Elevator> &elist);

    int outputStats(vector<Elevator> & elist);

    void ElevatorMovement(vector<Elevator> &elist, int id, int level);
};
    #endif //CS415_PROJECT_1_ELEVATOR_H
