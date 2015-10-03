//
// Created by Brian on 9/8/2015.
//

#include "elevator.h"

using namespace std;

Elevator::Elevator(vector<Elevator> & L)
{
    //Create an elevator and its starting stats
    destinationLevel = 0;
    id = L.size() +1;
    cout << "What is the elevator's initial level?: ";
    cin >> currentLevel;
    direction = "None";
    L.push_back(*this);
    cout << "An Elevator was built successfully!" << endl;

}

int Elevator::printStats(vector<Elevator> & elist)
{
    // Prints out a elevators information
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

    elist[elevatorNum-1];
    int numInstructions = instruction.size();
    cout << "Elevator ID: " << id << endl;
    cout << "Elevator Current Level: " << currentLevel << endl;
    cout << "Elevator Destination Level: " << destinationLevel << endl;
    cout << "Elevator Direction: " << direction << endl;

    if(numInstructions) {
        cout << "Elevator Instructions: ";
        for (int i = 0; i < numInstructions; i++) {
            if (i == numInstructions - 1) {
                cout << "Moving to level " << instruction[i] << endl;
                //E.level = E.instruction[i];
            }
            else {
                cout << "Moving to level " << instruction[i] << ", ";
                //E.level = E.instruction[i];
            }
        }
    }
    else
        cout << "No instructions!" << endl;
    cout << endl;

    return 0;
}

int Elevator::addInstruction() {
    int newLevel;
    string userInput;
    cout << "Is there a new level for this elevator to go to(yes/no)?: ";
    cin >> userInput;
    if(userInput == "yes")
    {
        cout << "What level is being added to the elevator's instructions?: ";
        cin >> newLevel;
        if(newLevel != currentLevel) {
            if (instruction.size() == 0) {
                if (newLevel < currentLevel)
                    direction = "down";
                else
                    direction = "up";
                destinationLevel = newLevel;
            }
            instruction.push_back(newLevel);
        }
    }
    return 0;
}

int Elevator::outputStats(vector<Elevator> & elist) {
    // Prints out a elevators information
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
        elist[j];
        int numInstructions = instruction.size();
        stats << "Elevator " << id << endl;
        stats << "---------------\n";
        stats << "Elevator Current Level: " << currentLevel << endl;
        stats << "Elevator Destination Level: " << destinationLevel << endl;
        stats << "Elevator Direction: " << direction << endl;

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
                    stats << "Moving to level " << instruction[i] << endl;
                    //E.level = E.instruction[i];
                }
                else {
                    stats << "Moving to level " << instruction[i] << ", ";
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

int Elevator::elevatorBrain()
{
    // Distributes the request list to elevator
    if(weight < MAX_WEIGHT)
    {
        for(int i = 0; i < requestList.size(); i++)
        {
            if(direction == "up" && requestList[i].direction == "up" && currentLevel < requestList[i].level) {
                instruction.push_back(requestList[i].level);
                requestList.erase(requestList.begin()+i);
                i--;
            }
            else if(direction == "down" && requestList[i].direction == "down" && currentLevel > requestList[i].level) {
                instruction.push_back(requestList[i].level);
                requestList.erase(requestList.begin() + i);
                i--;
            }
            else if(direction == "None")
            {
                instruction.push_back(requestList[i].level);
                destinationLevel = requestList[i].level;
                if(currentLevel < instruction[0])
                    direction = "up";
                else
                    direction = "down";
                requestList.erase(requestList.begin() + i);
            }
        }
    }
    return 0;
}

/*
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
 */