# CS415_Project_1

Implementation
------------

We want to solve the optimization problem: given that a building has n floors and m elevators,
how could we most efficiently move people up/down the floors?

The elevators travel in a single direction until the last request in that direction or it reaches the first or top floor.
If there is no request, stop and proceed towards the other direction, if there is any request from other direction.

Each elevators can take multiple requests. The requests are then sorted in the the direction the elevator is heading.
When the elevator reaches a request from a level, it pops it from the list and continues to the next level.

Each elevator has a maximum weight of 2500 lbs. Each request (a passenger) is given a random weight and if the load
becomes too heavy for the maximum weight of the elevator, the elevator continues until the passenger is let off
(a request to a destination level), then proceeds.

 --------------------------------------------- --------------------------------------------- -----------------------------------
Features :
 --------------------------------------------- --------------------------------------------- -----------------------------------

 Core:
    1. direction- the elevator will continue in its current direction until it hits the top/bottom floor or there if there
    are no levels with pickups of drop offs for the elevator to stop at in its current direction
    2. if a elevator does not have instructions, it checks to see if there are request
    3.
 Important:
    1. user gets information about elevators
    2. if a elevator does not have instructions and there are no request, it moves to a smart level to wait at

 Extra:
    1. weight- if elevator reaches max weight capacity, the elevator will not stop to pick more people up

---------------------------------------------- --------------------------------------------- -----------------------------------
BACKLOG :

Swinford - Work on sort algorithm (built-in library if you want), to sort the Elevator.Instructions/Elevator.Requests
Crosser - Work on step function, to call the movement
Nick - Movement based of sorted Elevator.Instruction/Elevator.Requests

 --------------------------------------------- --------------------------------------------- -----------------------------------
Bugs   9/13/15
 --------------------------------------------- --------------------------------------------- -----------------------------------

1. Instructions not correctly being deleted once level reached

 --------------------------------------------- --------------------------------------------- -----------------------------------
Need to do   9/13/15
 --------------------------------------------- --------------------------------------------- -----------------------------------

 1. implement weight into elevators
 2. implement time into request waiting
 3. fix bugs
 4. set bounds so elevators cannot go to non-existing levels
 5. add functionality that allows person to tell elevator what level they want to go to once elevator picks them up

 --------------------------------------------- --------------------------------------------- -----------------------------------
Functions that need implementation   9/10/15
 --------------------------------------------- --------------------------------------------- -----------------------------------
1. Sort
2. Step
3. Movement

 --------------------------------------------- ---------------------------------------------
 Function Implementation 9/10/15
  --------------------------------------------- ---------------------------------------------
  
  ElevatorMovement(Vector<Elevator> & E)
  Descend (Vector<Elevator> & E)
  Ascend (Vector<Elevator> & E) *** do this one first.
