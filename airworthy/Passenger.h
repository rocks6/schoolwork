/*
* @file Passenger.h
* @author Steven Byerly
* @desc header file for the Passenger class
*/


#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;

class Passenger
{
   private:
      //passenger's priority value
      int key;
      
      //passenger's last name
      string lastName;
      
      //passenger's priority type
      string type;
      
      //row where passenger is seated
      int row;

   public:
      //default constructor
      Passenger();
      
      //main constructor
      Passenger(int key_i, string lastName_i, string passengerType_i, int row_i);
      
      /* 
      * method to get the priority value of a passenger
      * @return int : the priority value of a passenger
      */
      int getKey();
      
      /*
      * method to set the priority value of a passenger
      * @params : newKey the new priority value
      */
      void setKey(int newKey);
            
      /* 
      * method to get the last name of a passenger
      * @return string : the last name of a passenger
      */
      string getLastName();
      
      /*
      * method to set the string of a passenger
      * @params : newLastName the new last name
      */
      void setLastName(int newLastName);
            
      /* 
      * method to get the type of a passenger
      * @return string : the type of a passenger
      */
      string getType();
      
      /*
      * method to set the type of a passenger
      * @params : newType the new passenger type
      */
      void setType(char newType);
            
      /* 
      * method to get the row of a passenger
      * @return int : the row of a passenger
      */
      int getRow();
      
      /*
      * method to set the row of a passenger
      * @params : newRow the new row
      */
      void setRow(int newRow);
      
      /*
      * overloaded > operator for passenger class
      * @params : rightOperand the right side of the equation
      * @return : bool whether the operation returns true
      */
      bool operator> (const Passenger rightOperand);
      
      /*
      * overloaded < operator for passenger class
      * @params : rightOperand the right side of the equation
      * @return : bool whether the operation returns true
      */
      bool operator< (const Passenger rightOperand);
      
      /*
      * overloaded == operator for passenger class
      * @params : rightOperand the right side of the equation
      * @return : bool whether the operation returns true
      */
      bool operator== (const Passenger rightOperand);
      
};

//#include "Passenger.cpp"
#endif