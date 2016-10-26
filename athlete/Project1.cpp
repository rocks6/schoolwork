/*****84eeeeeweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
 * @file Project1.cpp
 * @author Steve Byerly
 * @desc tester class for Project 1
 * @todo : [x] done [ ] not done 
 * [ ] fix bug where newline stays in cin stream after returning from input
 * [x] when inserting new entries, use the same type of method i used in deleting an entry to check the database
 *    for an existing athlete with that keyname and if so prompt stuff inside of the helper method 
 */
#include "Menu.cpp"
#include "AthleteDatabase.h"
#include <cstdlib>
#include <iostream>
using namespace std;


int main (void)
{
    cout << "Compiling athlete database..." << endl; 
    AthleteDatabase athleteDB2;
    athleteDB2.createDatabase();
    cout << "Success! Database created." << endl;
    //compile BST here
   
    //display main menu
    bool exit = false;
    while(exit == false)
    {
       exit = mainInterface(athleteDB2);
    }
    
    
}

