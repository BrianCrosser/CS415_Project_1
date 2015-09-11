//
// Created by Brian on 9/8/2015.
//

#include "elevator.h"

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
    if(numElevators == 0) {
        cout << "There are no elevators!" << endl;
        return 0;
    }
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
            if (i == numInstructions - 1) {
                cout << "Moving to level " << E.instruction[i] << endl;
                //E.level = E.instruction[i];
            }
            else {
                cout << "Moving to level " << E.instruction[i] << ", ";
                //E.level = E.instruction[i];
            }
        }
    }
    else
        cout << "No instructions!" << endl;
    cout << endl;

    return 0;
}

int Elevator::addInstruction(vector<Elevator> & elist) {
    // Adds a level the elevator must travel to
    int id, level;
    int numElevators = elist.size();

    if (numElevators == 0) {
        cout << "There are no elevators!";
        return 0;
    }
    else if (numElevators == 1)
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
    elist[id - 1].instruction.push_back(level);
    return 0;
}

void Elevator::ElevatorMovement(vector<Elevator> &elist, int id, int level) {
    if (elist[id - 1].level < level) { // If you are below the specified level, move up
        elist[id - 1].direction = "up";
        while (elist[id - 1].level < level) { // while the level of the current floor is less the desired level, move up.
            elist[id - 1].level = elist[id - 1].level + 1; //increment until desired floor
        }
    }
    if (elist[id - 1].level > level) { // If you are below the specified level, move up
        elist[id - 1].direction = "down";
        while (elist[id - 1].level < level) { // while the level of the current floor is less the desired level, move up.
            elist[id - 1].level = elist[id - 1].level - 1; //increment until desired floor
        }
    }
}

int Elevator::outputStats(vector<Elevator> & elist) {
    // Prints out a elevators information
    Elevator E;
    int elevatorNum = 0;
    int numElevators = elist.size();

    ofstream stats;
    stats.open("/Users/zachswinford/Desktop/stats.txt");

    if (numElevators == 0)
        stats << "There are no elevators!" << endl;
    else if (numElevators > 1) {
        stats << "There are " << numElevators << " elevators!" << endl;
        stats << endl;
    }
    else
        elevatorNum = 1;
    for (int j = 0; j < numElevators; j++) {

        E = elist[j];
        int numInstructions = E.instruction.size();
        stats << "Elevator " << E.id << endl;
        stats << "---------------\n";
        stats << "Elevator Level: " << E.level << endl;
        stats << "Elevator Direction: " << E.direction << endl;

        if (numInstructions) {
            stats << "Elevator Instructions: ";
            for (int i = 0; i < numInstructions; i++) {
/*
                if (E.instruction[i] > E.level)
                    E.direction = "up";
                if (E.instruction[i] < E.level)
                    E.direction = "down";
*/
                if (i == numInstructions - 1) {
                    stats << "Moving to level " << E.instruction[i] << endl;
                    //E.level = E.instruction[i];
                }
                else {
                    stats << "Moving to level " << E.instruction[i] << ", ";
                    //E.level = E.instruction[i];
                }
            }
            stats << endl;
        }
        else {
            stats << "No instructions!" << endl;
            stats << endl;
        }
    }
    stats.close();
    return 0;
}

int Elevator::elevatorBrain(Elevator & E)
{
    // Distributes the request list to elevator
    if(E.weight < MAX_WEIGHT)
    {
        for(int i = 0; i < requestList.size(); i++)
        {
            if(E.direction == "up" && requestList[i].direction == "up" && E.level < requestList[i].level) {
                E.instruction.push_back(requestList[i].level);
                requestList.erase(requestList.begin()+i);
                i--;
            }
            else if(E.direction == "down" && requestList[i].direction == "down" && E.level > requestList[i].level) {
                E.instruction.push_back(requestList[i].level);
                requestList.erase(requestList.begin() + i);
                i--;
            }
        }
    }
    return 0;
}

int Elevator::Descend (vector<Elevator> & E)
{
    vector<Elevator> list;

    int numElevators = E.size();
    for (int i = 0; i < numElevators; i++)
    {
        if (E[i].direction == "down")
            list.push_back(E[i]);
    }
    sort(list.begin(),list.end(), greater<int>());

    for(int i = 0; i < list.size(); i++)
        cout << list[i] << endl;

    return 0;
}


int Elevator::Ascend (vector<Elevator> & E)
{
    vector<Elevator> list;

    int numElevators = E.size();
    for (int i = 0; i < numElevators; i++)
    {
        if (E[i].direction == "up")
            list.push_back(E[i]);
    }
    sort(list.begin(),list.end(), less<int>());

    for(int i = 0; i < list.size(); i++)
        cout << list[i] << endl;

    return 0;
}