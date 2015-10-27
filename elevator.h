//
// Created by Brian on 9/8/2015.
//

#ifndef CS415_PROJECT_1_ELEVATOR_H
#define CS415_PROJECT_1_ELEVATOR_H
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include<algorithm>

using namespace std;

struct request{
    int levelPickUp, levelDesired, time;
    string direction;
};

extern const int MAX_WEIGHT;
extern int numLevels;
extern vector<request> requestList;

bool isValidLevel(int beginLevel, int endLevel);

class Elevator {
public:
    int id, currentLevel, destinationLevel, weight;
    string direction;
    vector<int> instruction;

    Elevator(vector<Elevator> &L);

    int printStats(vector<Elevator> &elist);

   int addInstruction();

    int outputStats(vector<Elevator> & elist);

    int elevatorBrain();

    void checkElevatorStats();

};
    #endif //CS415_PROJECT_1_ELEVATOR_H
