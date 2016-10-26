/*3
* @author Steven Byerly
* @date November 29
* @desc Driver class for the simulation project
* @TODO : description
*/


#include "Airworthy.h"
#include <iostream>

using namespace std;

void printDescription();

int main()
{
   //clean up previous files
   remove("results100.txt");
   remove("results85.txt");
   remove("results70.txt");
   
   printDescription();
   
   Airworthy airSim;
   airSim.loadInputToHeap(100);
   airSim.runSimulation(100);
   
   airSim.loadInputToHeap(85);
   airSim.runSimulation(85);
   
   airSim.loadInputToHeap(70);
   airSim.runSimulation(70);


}

void printDescription()
{
   cout << "DESCRIPTION PLACEHOLDER" << endl;
   
}