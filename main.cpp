#include <iostream>
#include <vector>
#include "elevator.h"

using namespace std;

const int MAX_WEIGHT = 2500;
vector<request> requestList;

int step(vector<Elevator> & eList)
{
    for(int i = 0; i < eList.size(); i++)
    {

    }
}

int main()
{
    // Declaring variables needed
    int userInput, numElevators, numLevels;
    bool runBool = true;
    vector<Elevator> elevatorList;
    Elevator E;

    // Creates elevators
    cout << "How many elevators are there?: ";
    cin >> numElevators;
    for(int i = 0; i < numElevators; i++)
        E.createElevator(elevatorList);

    // Creates amount of levels building has
    cout << "How many levels does the building have?: ";
    cin >> numLevels;

    while(runBool) {
        cout << "Commands: (1) Step, (3) Print stats of elevator to output file, (4) Print stats of elevator to screen, (5) exit program" << endl;
        cout << "Please give a command!: " << endl;
        cin >> userInput;
        switch (userInput) {
            case 1:
                step(elevatorList);
                cout << endl;
                break;
            case 3:
                E.outputStats(elevatorList);
                cout << "Printed elevator statistics to output file stats.txt." << endl;
                cout << endl;
            case 4:
                E.printStats(elevatorList);
                cout << endl;
                break;
            case 5:
                cout << endl;
                cout << "Exiting program." << endl;
                runBool = false;
                break;
        }
    }

    return 0;
}