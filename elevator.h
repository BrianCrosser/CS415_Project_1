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

struct request{
    int level;
    string direction;
    int time;
};

extern const int MAX_WEIGHT;
extern vector<request> requestList;

class Elevator {
public:
    int id, level, weight;
    string direction;
    vector<int> instruction;

    int createElevator(vector<Elevator> &L);

    int printStats(vector<Elevator> &elist);

    int addInstruction(vector<Elevator> &elist);

    int outputStats(vector<Elevator> & elist);

    void ElevatorMovement(vector<Elevator> &elist, int id, int level);

    int elevatorBrain(Elevator & E);

    int Descend (vector<Elevator> & E);

    int Ascend (vector<Elevator> & E);

};
    #endif //CS415_PROJECT_1_ELEVATOR_H
