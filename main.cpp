#include <iostream>
#include <vector>
#include "elevator.h"

using namespace std;

const int MAX_WEIGHT = 2500;
vector<request> requestList;

int step(vector<Elevator> & eList)
{
    // moves the elevator one floor and checks to see if level is a requested level it must stop at.
    // If so, it removes level from instructions list
    for(int i = 0; i < eList.size(); i++)
    {
        if(eList[i].direction == "up") {
            eList[i].level++;
            for(int j = 0; j < eList[i].instruction.size(); j++) {
                if (eList[i].level == eList[i].instruction[j]) {
                    eList[i].instruction.erase(eList[i].instruction.begin() + j);
                    if (eList[i].instruction.size() == 0)
                        eList[i].direction = "None";
                }
            }
        }
        else if(eList[i].direction == "down") {
            eList[i].level--;
            for(int j = 0; j < eList[i].instruction.size(); j++) {
                if (eList[i].level == eList[i].instruction[j]) {
                    eList[i].instruction.erase(eList[i].instruction.begin() + j);
                    if (eList[i].instruction.size() == 0)
                        eList[i].direction = "None";
                }
            }
        }
    }

    // ask users for new instructions
    request newRequest;
    string userInput;
    cout << "Is there a new request to a level(yes/no)?: ";
    cin >> userInput;
    if(userInput == "yes")
    {
        cout << "What level is being requested?: ";
        cin >> newRequest.level;
        cout << "What direction are you going(up/down)?: ";
        cin >> newRequest.direction;
        requestList.push_back(newRequest);
    }

    // adds new request to elevator's instructions
    for(int i = 0; i < eList.size(); i++)
        eList[i].elevatorBrain(eList[i]);

    return 0;
}

int main()
{
    // Declaring variables needed
    int userInput, numElevators, numLevels;
    bool runBool = true;
    vector<Elevator> elevatorList;
    Elevator E;

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