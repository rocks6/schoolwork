/*
* @file Passenger.cpp
* @author Steve Byerly
* @desc implementation for the Passenger object
*/

#include "Passenger.h"

using namespace std;

Passenger::Passenger()
{
   key = 0;
   lastName = "";
   type = ' ';
   row = 0;
}

Passenger::Passenger(int key_i, string lastName_i, string type_i, int row_i)
{
   key = key_i;
   lastName = lastName_i;
   type = type_i;
   row = row_i;
}

int Passenger::getKey()
{
   return key;
}
      
void Passenger::setKey(int newKey)
{
   key = newKey;
}
            
string Passenger::getLastName()
{
   return lastName;
}
      
void Passenger::setLastName(int newLastName)
{
   lastName = newLastName;
}
            
string Passenger::getType()
{
   return type;
}
      
void Passenger::setType(char newType)
{
   type = newType;
}
            
int Passenger::getRow()
{
   return row;
}
      
void Passenger::setRow(int newRow)
{
   row = newRow;
}

bool Passenger::operator> (const Passenger rightOperand)
{
   if (key > rightOperand.key)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Passenger::operator< (const Passenger rightOperand)
{
   if (key < rightOperand.key)
   {
      return true;
   }
   else
   {
      return false;
   }
} 

bool Passenger::operator== (const Passenger rightOperand)
{
   if (key == rightOperand.key)
   {
      return true;
   }
   else
   {
      return false;
   }
}