/*
* @file Athlete.cpp
* @author Steve Byerly
* @desc Provide an Athlete object to be used
*/
#include "Athlete.h"
#include <iostream>

Athlete::Athlete()
{
   lastname == "null";
   firstname = "null";
   rank = 10000;
   totalearnings = 999.99;
   salary = 999.99;
   endorsements = 999.99;
   sport = "null";
   
}

Athlete::Athlete(string C_lastname, string C_firstname, int C_rank, 
         double C_totalearnings, double C_salary, double C_endorsements, string C_sport)
         {
         lastname = C_lastname;
         firstname = C_firstname;
         rank = C_rank;
         totalearnings = C_totalearnings;
         salary = C_salary;
         endorsements = C_endorsements;
         sport = C_sport;

}

/*Athlete::Athlete()
{
   
   lastname = "null";
   firstname = "null";
   rank = 10000;
   totalearnings = 999.99;
   salary = 999.99;
   endorsements = 999.99;
   sport = "null";
   
}*/

string Athlete::getLastName ()
{
return lastname;
}

void Athlete::setLastName (string newLastName)
{
   lastname = newLastName;
}

int Athlete::getRank ()
{
return rank;
}

void Athlete::setRank (int newRank)
{
rank = newRank;
}

string Athlete::getFirstName ()
{
return firstname;
}

void Athlete::setFirstName (string newFirstName)
{
firstname = newFirstName;
}

double Athlete::getEarnings ()
{
return totalearnings;
}

void Athlete::setSalary (double newSalary)
{
salary = newSalary;
}

double Athlete::getSalary ()
{
return salary;
}

void Athlete::setEndorsements (double newEndorsements)
{
endorsements = newEndorsements;
}

double Athlete::getEndorsements ()
{
return endorsements;
}

void Athlete::setEarnings (double newEarnings)
{
totalearnings = newEarnings;
}

string Athlete::getSport ()
{
return sport;
}

void Athlete::setSport (string newSport)
{
sport = newSport;
}

bool Athlete::operator> (const Athlete rightOperand)
{
   if (lastname > rightOperand.lastname)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Athlete::operator< (const Athlete rightOperand)
{
   if (lastname < rightOperand.lastname)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Athlete::operator== (const Athlete rightOperand)
{
   if (lastname == rightOperand.lastname)
   {
      return true;
   }
   else
   {
      return false;
   }
}
