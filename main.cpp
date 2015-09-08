#include <iostream>
#include <vector>

using namespace std;

struct elevator
{
    int id;
    int level;
    string direction;
    vector<int> instruction;
 };

int createElevator(vector<elevator> & L)
{
    //Create an elevator and its starting stats
    elevator elevator;
    elevator.id = L.size() +1;
    elevator.level = 1;
    elevator.direction = "up";
    L.push_back(elevator);
    cout << "An Elevator was built successfully!" << endl;

    return 0;
}

int printStats(vector<elevator> & elist)
{
    // Prints out a elevators information
    elevator E;
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

int addInstruction(vector<elevator> & elist)
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

int main()
{
    int userInput;
    bool runBool = true;
    vector<elevator> elevatorList;
    createElevator(elevatorList);
    while(runBool) {
        cout << "Commands: (1) Add a level, (2) Add an elevator, (3) Print stats of elevator, (4) exit program" << endl;
        cout << "Please give a command!: " << endl;
        cin >> userInput;
        switch (userInput) {
            case 1:
                addInstruction(elevatorList);
                break;
            case 2:
                createElevator(elevatorList);
                break;
            case 3:
                printStats(elevatorList);
                break;
            case 4:
                runBool = false;
                break;
        }
    }

    return 0;
}