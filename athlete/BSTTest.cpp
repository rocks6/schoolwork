/**
 * @file Project1.cpp
 * @author Steve Byerly
 * @desc tester class for Project 1
 */
#include "Menu.cpp"
#include <cstdlib>
#include <iostream>
using namespace std;


int main (void)
{
    cout << "Compiling athlete database..." << endl; 
    AthleteDatabase athleteDB;
    athleteDB.createDatabase();
    cout << "Success! Database created." << endl;
    //compile BST here
   
    //display main menu
    bool exit = false;
    while(exit == false)
    {
       exit = mainInterface();
    }
    
    
}

