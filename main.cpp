#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "elevator.h"

using namespace std;

const int MAX_WEIGHT = 2500;
int numLevels;
vector<request> requestList;

void removeWeight(Elevator & E)
{
    if(E.instruction.empty())
        E.weight = 0;
    else
        E.weight -= rand() % E.weight + 60;

}

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
                    removeWeight(eList[i]);
                    j--;
                    for(int m = 0; m < eList[i].instruction.size(); m++)
                        if(eList[i].instruction[m] > eList[i].currentLevel) {
                            sameDirection = true;
                            if(eList[i].instruction[m] > eList[i].destinationLevel)
                                eList[i].destinationLevel = eList[i].instruction[m];
                        }
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
                    removeWeight(eList[i]);
                    j--;
                    for(int m = 0; m < eList[i].instruction.size(); m++)
                        if(eList[i].instruction[m] < eList[i].currentLevel){
                            sameDirection = true;
                            if(eList[i].instruction[m] < eList[i].destinationLevel)
                                eList[i].destinationLevel = eList[i].instruction[m];
                        }
                    if (eList[i].instruction.size() == 0 || !sameDirection)
                        eList[i].direction = "None";
                    eList[i].addInstruction();
                }
            }
        }
    }
    // adds new request to elevator's instructions
    for(int i = 0; i < eList.size(); i++)
        eList[i].checkElevatorStats();

    return 0;
}

bool checkRequestExist(request newRequest, vector<Elevator> & eList)
{
    for (int i = 0; i < requestList.size(); i++)
        if (newRequest.levelPickUp == requestList[i].levelPickUp && newRequest.direction == requestList[i].direction)
            return false;
    for (int i = 0; i < eList.size(); i++) {
        for (int j = 0; j < eList[i].instruction.size(); j++)
            if (newRequest.levelPickUp == eList[i].instruction[j] && newRequest.direction == eList[i].direction)
                return false;
    }
    return true;
}

int addRequest(vector<Elevator> & eList){
    // ask users for new instructions
    request newRequest;
    cout << "What level is being requested?: ";
    cin >> newRequest.levelPickUp;
    cout << "What level are you traveling to?: ";
    cin >> newRequest.levelDesired;
    if(newRequest.levelPickUp != newRequest.levelDesired && isValidLevel(newRequest.levelPickUp, newRequest.levelDesired)) {
        if (newRequest.levelPickUp < newRequest.levelDesired)
            newRequest.direction = "up";
        else
            newRequest.direction = "down";
        if (checkRequestExist(newRequest, eList))
            requestList.push_back(newRequest);
    }
    // adds new request to elevator's instructions
    for(int i = 0; i < eList.size(); i++)
        eList[i].elevatorBrain();

    return 0;
}

void show(vector<Elevator> elevatorList, int numFloors)
{
    cout << "Floor:" << setw(12);
    for(int i = 0; i < numFloors; i++) {
        cout << "     " << i + 1;
    }
    cout << endl;
    cout << endl;
    for(int i = 0; i < elevatorList.size(); i++){
        cout << "Elevator #: " << elevatorList[i].id;
        cout << setw(6 * elevatorList[i].currentLevel - 1) << "[" << elevatorList[i].weight << "]" << endl;
    }
    cout << endl;
}

int main()
{
    // Declaring variables needed
    int userInput, numElevators;
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
        show(elevatorList, numLevels);
        cout << "Commands: (1) Step, (2) Add request, (3) Print stats of elevator to output file," << endl;
        cout << setw(10) << "(4) Print stats of elevator to screen, (5) exit program" << endl;
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
        //system("pause");
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
    }

    return 0;
}