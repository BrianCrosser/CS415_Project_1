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
        cout << "Commands: (1) Add a level, (2) Add an elevator, (3) Print stats of elevator, (4) exit program" << endl;
        cout << "Please give a command!: " << endl;
        cin >> userInput;
        switch (userInput) {
            case 1:
                E.addInstruction(elevatorList);
                break;
            case 2:
                E.createElevator(elevatorList);
                break;
            case 3:
                E.printStats(elevatorList);
                break;
            case 4:
                runBool = false;
                break;
        }
    }

    return 0;
}