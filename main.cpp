#include <iostream>
#include <vector>
#include <cstdlib>
#include "elevator.h"

using namespace std;

const int MAX_WEIGHT = 2500;
vector<request> requestList;

int step(vector<Elevator> & eList) {
    // moves the elevator one floor and checks to see if level is a requested level it must stop at.
    // If so, it removes level from instructions list
    for (int i = 0; i < eList.size(); i++) {
        bool sameDirection = false;
        if (eList[i].direction == "up") {
            eList[i].currentLevel++;
            for (int j = 0; j < eList[i].instruction.size(); j++) {
                // If desired level is reached, delete that level from instructions
                if (eList[i].currentLevel == eList[i].instruction[j]) {
                    eList[i].instruction.erase(eList[i].instruction.begin() + j);
                    for(int m = 0; m < eList[i].instruction.size(); m++)
                        if(eList[i].instruction[m] > eList[i].currentLevel)
                            sameDirection = true;
                    if (eList[i].instruction.size() == 0 || !sameDirection)
                        eList[i].direction = "None";
                    eList[i].addInstruction();
                }
            }
        }
        else if (eList[i].direction == "down") {
            eList[i].currentLevel--;
            for (int j = 0; j < eList[i].instruction.size(); j++) {
                if (eList[i].currentLevel == eList[i].instruction[j]) {
                    eList[i].instruction.erase(eList[i].instruction.begin() + j);
                    for(int m = 0; m < eList[i].instruction.size(); m++)
                        if(eList[i].instruction[m] < eList[i].currentLevel)
                            sameDirection = true;
                    if (eList[i].instruction.size() == 0 || !sameDirection)
                        eList[i].direction = "None";
                    eList[i].addInstruction();
                }
            }
        }
    }
    // adds new request to elevator's instructions
    for(int i = 0; i < eList.size(); i++)
        eList[i].elevatorBrain();

    return 0;
}

int addRequest(vector<Elevator> & eList){
    // ask users for new instructions
    request newRequest;
    cout << "What level is being requested?: ";
    cin >> newRequest.levelPickUp;
    cout << "What level are you traveling to?: ";
    cin >> newRequest.levelDesired;
    requestList.push_back(newRequest);

    // adds new request to elevator's instructions
    for(int i = 0; i < eList.size(); i++)
        eList[i].elevatorBrain();

    return 0;
}

int main()
{
    // Declaring variables needed
    int userInput, numElevators, numLevels;
    bool runBool = true;
    vector<Elevator> elevatorList;

    // Creates elevators
    cout << "                                                               .---.\n"
                    "                                                              /  .  \\\n"
                    "                                                             |\\_/|   |\n"
                    "                                                             |   |  /|\n"
                    "  .----------------------------------------------------------------' |\n"
                    " /  .-.                                                              |\n"
                    "|  /   \\                  Elevator Project                           |\n"
                    "| |\\_.  |                      CS 415                                |\n"
                    "|\\|  | /|                                                            |\n"
                    "| `---' |                 By:                                        |\n"
                    "|       |         Nguyen, Swinford, Crosser                          | \n"
                    "|       |                                                           /\n"
                    "|       |----------------------------------------------------------'\n"
                    "\\       |\n"
                    " \\     /\n"
                    "  `---'\n"
                    "\n"
                    "\n"
                    " "  << endl;

    cout << "How many elevators are there?: ";
    cin >> numElevators;
    for(int i = 0; i < numElevators; i++)
        Elevator E(elevatorList);

    // Creates amount of levels building has
    cout << "How many levels does the building have?: ";
    cin >> numLevels;
    cout << endl;

    while(runBool) {
        system("cls");
        cout << "Commands: (1) Step, (2) Add request, (3) Print stats of elevator to output file, (4) Print stats of elevator to screen, (5) exit program" << endl;
        cout << "Please give a command!: " << endl;
        cin >> userInput;
        switch (userInput) {
            case 1:
                step(elevatorList);
                cout << endl;
                break;
            case 2:
                addRequest(elevatorList);
                cout << endl;
                break;
            case 3:
                elevatorList[0].outputStats(elevatorList);
                cout << "Printed elevator statistics to output file stats.txt." << endl;
                cout << endl;
            case 4:
                elevatorList[0].printStats(elevatorList);
                cout << endl;
                break;
            case 5:
                cout << endl;
                cout << "Exiting program." << endl;
                runBool = false;
                break;
        }
        system("pause");

    }

    return 0;
}