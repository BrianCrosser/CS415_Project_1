//
// Created by Brian on 9/8/2015.
//

#include "elevator.h"

#include <iostream>
#include <vector>

using namespace std;


int Elevator::createElevator(vector<Elevator> & L)
{
    //Create an elevator and its starting stats
    Elevator elevator;
    elevator.id = L.size() +1;
    cout << "What is the elevator's initial level?: ";
    cin >> elevator.level;
    elevator.direction = "up";
    L.push_back(elevator);
    cout << "An Elevator was built successfully!" << endl;

    return 0;
}

int Elevator::printStats(vector<Elevator> & elist)
{
    // Prints out a elevators information
    Elevator E;
    int elevatorNum;
    int numElevators = elist.size();
    if(numElevators == 0)
        cout << "There are no elevators!" << endl;
    else if(numElevators > 1) {
        cout << "There are " << numElevators << " elevators!" << endl;
        cout << "What elevator do you want to know about?: ";
        cin >> elevatorNum;
    }
    else
        elevatorNum = 1;

    E = elist[elevatorNum-1];
    int numInstructions = E.instruction.size();
    cout << "Elevator ID: " << E.id << endl;
    cout << "Elevator Level: " << E.level << endl;
    cout << "Elevator Direction: " << E.direction << endl;
    if(numInstructions) {
        cout << "Elevator Instructions: ";
        for (int i = 0; i < numInstructions; i++) {
            if (i == numInstructions - 1)
                cout << E.instruction[i] << endl;
            else
                cout << E.instruction[i] << ", ";
        }
    }
    else
        cout << "No instructions!" << endl;
    cout << endl;

    return 0;
}

int Elevator::addInstruction(vector<Elevator> & elist)
{
    // Adds a level the elevator must travel to
    int id, level;
    int numElevators = elist.size();

    if(numElevators == 0)
        cout << "There are no elevators!";
    else if(numElevators == 1)
        id = 1;
    else {
        cout << "What elevator are you adding instruction to?: ";
        for (int i = 0; i < numElevators; i++) {
            if (i == numElevators - 1)
                cout << elist[i].id << endl;
            else
                cout << elist[i].id << ", ";
        }
        cin >> id;
    }
    cout << "What level are you traveling to?: ";
    cin >> level;
    elist[id-1].instruction.push_back(level);

    return 0;
}