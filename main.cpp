#include <iostream>
#include <vector>
#include "elevator.h"

using namespace std;

int main()
{
    int userInput;
    bool runBool = true;
    vector<Elevator> elevatorList;
    Elevator E;
    while(runBool) {
        cout << "Commands: (1) Add a level, (2) Add an elevator, (3) Print stats to output file, (4) Print stats of elevator to screen, (5) exit program" << endl;
        cout << "Please give a command!: " << endl;
        cin >> userInput;
        switch (userInput) {
            case 1:
                E.addInstruction(elevatorList);
                cout << endl;
                break;
            case 2:
                E.createElevator(elevatorList);
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