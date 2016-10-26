/*
* @file Airworthy.cpp
* @author Steven Byerly
* @desc implementation file for Airworthy class
*/

#include "Airworthy.h"
#include <istream>
#include <fstream>
#include <iostream>

Airworthy::Airworthy()
{
   
}

void Airworthy::loadInputToHeap(int capacity)
{
   string filename = "airworthy" + to_string(capacity) + ".txt";
   ifstream inFile (filename);
   
   /*
   //MAY NOT BE USED
   //initialize array to hold how full rows are on the plane
   int rowArray [26];
   for (i=0;i<26;i++)
   {
      rowArray[i] == 0;
   }
   */
   
   while (inFile.good())
   {
      string buffer;
      getline(inFile, buffer);
      string lastname_i = buffer.substr(0, buffer.find(" "));
      //cout << "DEBUG: LASTNAME SCRAPED: " << lastname_i << endl; 
      
      string buffer2 = buffer.substr(buffer.find(" ") + 1);
      //cout << "DEBUG: BUFFER2: " << buffer2 << endl;
      string type_i_str = buffer2.substr(0, buffer2.find(" "));
      //cout << "DEBUG: TYPE SCRAPED: " << type_i_str << endl; 
      
      string buffer3 = buffer2.substr(buffer2.find(" ") + 1);
      //cout << "DEBUG: BUFFER3: " << buffer3 << endl;
      string row_i_str = buffer3.substr(0);
      //cout << "DEBUG: ROW SCRAPED: " << row_i_str << endl; 
      
      int row_i = atoi(row_i_str.c_str());
      
      //total of 148 seats - 16 first class and 132 normal
      //naming convention for priority queue: [type+row] where types are H=3, E=2, G=1
      
      //ADD PASSENGER TO OLD BOARDING PROCEDURE PRIORITY HEAP
      
      string keybuffer = " ";
      
      //assign priority value based on passenger type and row
      //cout << "DEBUG: ROW_I_STR.LENGTH(): " << row_i_str.length() << endl;
      //check if row is single digit
      if (row_i_str.length() == 2)
      {
            row_i_str = "0" + row_i_str;
      }
      
      if (type_i_str == "H")
      {
            keybuffer = "3" + row_i_str;
      }
      else if (type_i_str == "E")
      {
            keybuffer = "2" + row_i_str;
      }
      else if (type_i_str == "G")
      {  
            //row_i_int = atoi(row_i_str);
            //row_i_int = 100 - row_i_int;
            
            keybuffer = "1" + row_i_str;
      }
      
      int key_i = atoi(keybuffer.c_str());
      
      //cout << "Writing passenger to old procedure heap: " << lastname_i << " " << type_i_str << " " << row_i_str << " " << keybuffer << endl;
      
      Passenger passenger_old(key_i, lastname_i, type_i_str, row_i);
      
      if (key_i != 0)
      {
         oldProcedureHeap.add(passenger_old);
      }
      
      //write added passenger to results file
      string craftedCapacityStr = "results" + to_string(capacity) + ".txt";
      ofstream outFile(craftedCapacityStr, fstream::app);
      
      //outFile << "OLD PROCEDURE: Adding passenger with lastname " << passenger_old.getLastName() << ", row " << to_string(passenger_old.getRow()) << ", and priority value " << to_string(passenger_old.getKey()) << endl;
         
      //ADD PASSENGER TO NEW BOARDING PROCEDURE PRIORITY HEAP
      keybuffer = " ";
      string GEN_PRIORITY = "50";
      
      if (row_i_str.length() == 2)
      {
            row_i_str = "0" + row_i_str;
      }
      if (type_i_str == "H")
      {
            keybuffer = "3" + row_i_str;
      }
      else if (type_i_str == "E")
      {
            keybuffer = "2" + row_i_str;
      }
      else if (type_i_str == "G")
      {  
            //all general boarding passengers have the same priority
            keybuffer = "1" + GEN_PRIORITY;
      }
      
      key_i = atoi(keybuffer.c_str());
      //cout << "Writing passenger to new procedure heap: " << lastname_i << " " << type_i_str << " " << row_i_str << " " << keybuffer << endl;
      Passenger passenger_new(key_i, lastname_i, type_i_str, row_i);
     
      if (key_i != 0)
      {
         newProcedureHeap.add(passenger_new);
      }
      //write added passenger to results file
      craftedCapacityStr = "results" + to_string(capacity) + ".txt";
      ofstream outFile2(craftedCapacityStr, fstream::app);
      //outFile2 << "NEW PROCEDURE: Adding passenger with lastname " << passenger_new.getLastName() << ", row " << to_string(passenger_new.getRow()) << ", and priority value " << to_string(passenger_new.getKey()) << endl;
      
       
   }
   cout << "Successfully added passengers to both priority heaps!" << endl;
   return;   
}

//old = true; new = false
void Airworthy::incrementCorrectTimeVar(int capacity, bool oldOrNew, int amount)
{
   if (oldOrNew == true)
   {
      if (capacity == 100)
      {
         oldTime100 += amount;  
      }
      else if (capacity == 85)
      {
         oldTime85 += amount;
      }
      else
      {
         oldTime70 += amount;
      }
   }
   else
   {
      if (capacity == 100)
      {
         newTime100 += amount;
      }
      else if (capacity == 85)
      {
         newTime85 += amount;
      }
      else
      {
         newTime70 += amount;
      }
   }

}
      
void Airworthy::runSimulation(int capacity)
{
    //TODO: COPY THE HEAP SO I DO NOT DELETE THE REAL ONE
    //or rebuild at end??? probably
    //old procedure section
    string craftedCapacityStr = "results" + to_string(capacity) + ".txt";
    ofstream outFile(craftedCapacityStr, fstream::app);
    cout << "Opening file " << craftedCapacityStr << " for output..." << endl;
    
    cout << "Running simulation for old procedure... " << endl;
    
    //integer to track the last passenger's row to check if they are blocked
    int previousPassengerRow = -1;
    while (!oldProcedureHeap.isEmpty())
    {
         Passenger passToRemove = oldProcedureHeap.peek();
         string stringToOutput = "OLD PROCEDURE: Removing passenger with lastname " + passToRemove.getLastName() + ", row " + to_string(passToRemove.getRow()) + ", and priority value " + to_string(passToRemove.getKey());
         outFile << stringToOutput << endl;
         cout << "OLD PROCEDURE: Removing passenger with lastname " + passToRemove.getLastName() + ", row " + to_string(passToRemove.getRow()) + ", and priority value " + to_string(passToRemove.getKey()) << endl;
         
         if (passToRemove.getRow() <= previousPassengerRow)
         {
            //passenger is blocked, increment by 25
            incrementCorrectTimeVar(capacity, true, 25);
         }
         else
         {
            incrementCorrectTimeVar(capacity, true, 1);
         } 
         previousPassengerRow = passToRemove.getRow();
         oldProcedureHeap.remove();
    }
    //choose correct time variable to output
    if (capacity == 100)
    {
      double timeInMinutes = oldTime100 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFile << "OLD PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }
    else if (capacity == 85)
    {
      double timeInMinutes = oldTime85 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFile << "OLD PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }
    else
    {
      double timeInMinutes = oldTime70 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFile << "OLD PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }
    
    //new procedure section
    string craftedCapacityStrNew = "results" + to_string(capacity) + ".txt";
    ofstream outFileNew(craftedCapacityStrNew, fstream::app);
    cout << "Opening file " << craftedCapacityStrNew << " for output..." << endl;
    
    cout << "Running simulation for new procedure... " << endl;
    
    //integer to track the last passenger's row to check if they are blocked
    int previousPassengerRowNew = -1;
    while (!newProcedureHeap.isEmpty())
    {
         Passenger passToRemove = newProcedureHeap.peek();
         string stringToOutput = "NEW PROCEDURE: Removing passenger with lastname " + passToRemove.getLastName() + ", row " + to_string(passToRemove.getRow()) + ", and priority value " + to_string(passToRemove.getKey());
         outFileNew << stringToOutput << endl;
         cout << "NEW PROCEDURE: Removing passenger with lastname " + passToRemove.getLastName() + ", row " + to_string(passToRemove.getRow()) + ", and priority value " + to_string(passToRemove.getKey()) << endl;
         if (passToRemove.getRow() <= previousPassengerRowNew)
         {
            //passenger is blocked, increment by 25
            incrementCorrectTimeVar(capacity, false, 25);
         }
         else
         {
            incrementCorrectTimeVar(capacity, false, 1);
         } 
         previousPassengerRowNew = passToRemove.getRow();
         newProcedureHeap.remove();
    }
    //choose correct time variable to output
    if (capacity == 100)
    {
      double timeInMinutes = newTime100 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFileNew << "NEW PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }
    else if (capacity == 85)
    {
      double timeInMinutes = newTime85 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFileNew << "NEW PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }
    else
    {
      double timeInMinutes = newTime70 / 60.0;
      string timeBuffer = to_string(timeInMinutes);
      string timeBuffer2 = timeBuffer.substr(0,timeBuffer.find(".")+3);
      outFileNew << "NEW PROCEDURE: Total time taken: " << timeBuffer2 << " minutes" << endl;
    }

//reload heaps
loadInputToHeap(capacity);
}
