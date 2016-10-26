/*
* @file Athlete.h
* @author Steve Byerly
* @desc Provide implementation for an athlete object
*/
#ifndef ATHLETE_H

#include <iostream>


using namespace std;

const string inputFilename = "WorldsHighestPaidAthletes.csv";
const string outputFilename = "HighestPaidAthletesOut.csv";

class Athlete
{
private:

/*
* athlete's last name 
*/
string lastname;

/*
* athlete's first name 
*/
string firstname;

/*
* athlete's rank 
*/
int rank;
/*
* athlete's total earnings 
*/
double totalearnings;

/*
* athlete's salary 
*/
double salary;

/*
* athlete's total endorsements 
*/
double endorsements;

/*
* athlete's sport 
*/
string sport;

public:


/*
* @param lastname - athletes last name, key ID
* @param firstname - athletes first name
* @param rank - athletes rank
* @param totalearnings - athlete's total earnings
* @param salary - athlete's current salary
* @param endorsements - amount athlete has been paid to endorse products
* @param sport - what sport the athlete plays
*/
Athlete(string C_lastname, string C_firstname, int C_rank, 
         double C_totalearnings, double C_salary, double C_endorsements, string C_sport);

/*
* default constructor
*/
Athlete();

/*
* get the first name of an athlete
*/         
string getFirstName();

/*
* set the first name of an athlete
* @params : newFirstName the first name to change to
*/         
void setFirstName(string newFirstName);


/*
* get the sport of an athlete
*/         
string getSport();

/*
* set the sport of an athlete
* @params : newSport the sport to change to
*/         
void setSport(string newSport);

/*
* get the last name of an athlete
*/         
string getLastName();

/*
* set the last name of an athlete
* @params : newLastName the last name to change to
*/         
void setLastName(string newLastName);

/*
* get the rank of an athlete
*/
int getRank();

/*
* set the rank of an athlete
* params : newRank the new rank
*/
void setRank(int newRank);

/*
* set the earnings of an athlete
* params : newEarnings the new earnings
*/
void setEarnings(double newEarnings);

/*
* get the earnings of an athlete
* return the earnings of an athlete
*/
double getEarnings();

/*
* set the salary of an athlete
* params : newSalary the new salary
*/
void setSalary(double newSalary);

/*
* get the salary of an athlete
* return the athlete's salary
*/
double getSalary();

/*
* set the endorsements of an athlete
* params : newEndorsements the new total endorsement amount
*/
void setEndorsements(double newEndorsements);

/*
* get the endorsements of an athlete
* return the athlete's total endorsements
*/
double getEndorsements();


/*
*input an athlete object into the database
*/
bool inputAthlete();

/*
* define the < (less than) operator for Athlete objects
* @param rightOperand - right side of the < operator
*/
bool operator< (const Athlete rightOperand);


/*
* define the > (greater than) operator for Athlete objects
* @param rightOperand - right side of the > operator
*/
bool operator> (const Athlete rightOperand);


/*
* define the == (equal to) operator for Athlete objects
* @param rightOperand - right side of the == operator
*/
bool operator== (const Athlete rightOperand);

/*
* method to save current loaded athlete database to file
*/
bool saveToFile ();
};

#define ATHLETE_H
#endif