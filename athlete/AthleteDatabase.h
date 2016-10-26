/*
* @author Steven Byerly
* @file AthleteDatabase.h
* @desc provide a header for the athlete database type to store athlete objects
*/
#ifndef ATHLETEDATABASE_H
#include <iostream>
#include "BinarySearchTree.h"
#include "Athlete.h"

using namespace std;

const string INPUT_FILE = "WorldsHighestPaidAthletes.csv";

class AthleteDatabase
{
private:

friend class BinarySearchTree<Athlete>;


/*
* second foundEntry object to store internal, non static found entry - may or may not be used
*/
//Athlete foundEntry;

/*
* boolean variable to help with finding objects and the contains method
*/
bool targetKeyFound;

public:

/*
* binary search tree to hold athlete objects
*/
BinarySearchTree<Athlete> athleteDB;

/*
* default constructor
*/
AthleteDatabase();

/*
* keyname that is currently being searched for, to be checked against with visit()
*/
static string targetKey;

/*
* second foundEntry object to store internal, non static found entry - may or may not be used
*/
//static Athlete foundEntry;

/*
* helper variable to store a found Athlete - may or may not be used 
*/
//static Athlete foundEntry; //("null","null",10000,999.99,999.99,999.99,"null");

/*
* method to get the found entry
* return the found entry stored statically
*/
Athlete getFoundEntry();

/*
* set the found entry to an athlete object
* @params : the athlete object to set to
*/
static void setFoundEntry(Athlete newObject);

/*
* method to return the current target key 
*/
static string getTargetKey();

/*
* method to set the current target key 
* @params : newTargetKey the target key to change to
*/
string setTargetKey(string newTargetKey);

/*
* helper method to find an entry by keyname - use with traversals
* @params : waldo the athlete being visited
*/
//void checkForTarget(Athlete& waldo);

/*
* method to search for target athlete entry by keyname
* @params : target to search for
*/
void searchForTarget(string target);

/*
* add an athlete record to the database
*/
void insertRecord();

/*
* create a database to hold athlete objects
*/
void createDatabase();

/*
* print out entries sorted by rank
*/
void displayRankReport();

/*
* print out entries sorted by key
*/
void displayKeyReport();

/*
* helper method to compile keynames into a list for checking purposes
*/
void compileKeynames();

/*
* save database entries to an output file 
*/
void saveDbToFile();

/*
* helper method to initalize the found entry athlete object
*/
//void initializeFoundEntry();

/*
* method to delete an entry by keyname
* params : keyname - the key name of the athlete entry to be deleted
*/
void deleteEntryByKeyname(string keyname);

/*
* remove an entry from the database with user input
*/
void deleteEntryFromDb();

};

#define ATHLETEDATABASE_H
#endif