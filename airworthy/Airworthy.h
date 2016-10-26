/*
* @file Airworthy.h
* @author Steve Byerly
* @desc a header file for an Airworthy airplane object
*/

#ifndef AIRWORTHY_H
#define AIRWORTHY_H
#include "Heap_PriorityQueue.h"
#include "Passenger.h"

class Airworthy
{     
   public:
      //a priority queue to represent Airworthy's old procedure
      Heap_PriorityQueue<Passenger> oldProcedureHeap;
      
      //a priority queue to represent Airworthy's new procedure
      Heap_PriorityQueue<Passenger> newProcedureHeap;   
      
      //the amount of time required to board a 100% capacity plane using old procedure
      double oldTime100;
      
      //the amount of time required to board a 85% capacity plane using old procedure
      double oldTime85;
      
      //the amount of time required to board a 70% capacity plane using old procedure
      double oldTime70;
      
      //the amount of time required to board a 100% capacity plane using new procedure
      double newTime100;
      
      //the amount of time required to board a 85% capacity plane using new procedure
      double newTime85;
      
      //the amount of time required to board a 70% capacity plane using new procedure
      double newTime70;
      
      //default constructor
      Airworthy();
      
      /*
      * helper method to increment the time variables based on three factors
      * @return void
      * @params : capacity which capacity plane to increment the time of
      *         : amount the amount of time to increment by
      *         : oldOrNew whether the user wants to increment the old procedure time or the new procedure time, true = old; false = new
      */
      void incrementCorrectTimeVar(int capacity, bool oldOrNew, int amount);
      
      /*
      * method to load input files into both heaps
      * @return void
      * @params : capacity the capacity of the plane to load from input files (100, 70 or 85)
      */
      void loadInputToHeap(int capacity);    
      
      /*
      * method to run the simulation for a specific capacity
      * @return void
      * @params : capacity the capacity of the plane to run the simulation with (either 100, 70, or 85)
      */
      void runSimulation(int capacity);
      
};



//#include "Airworthy.cpp"
#endif