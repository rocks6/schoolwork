/*
* @file Menu.cpp
* @author Steven Byerly
* @desc act as an interface for the Athlete project
*/

#include <iostream>
#include <string>
#include "AthleteDatabase.h"

using namespace std;

bool mainInterface(AthleteDatabase ath);

bool describe();

bool maintainInterface(AthleteDatabase ath);

bool reportsInterface(AthleteDatabase ath);

bool saveAndClose(AthleteDatabase ath);



bool mainInterface(AthleteDatabase ath)
{
   cin.clear();
   bool retVal = false;
   //set retVal to result of method being used to decide if the user wants to continue
   
   cout << "WORLD'S HIGHEST PAID ATHLETES MAIN MENU" << endl;
   cout << "D - Describe the program" << endl;
   cout << "M - Maintain the database" << endl;
   cout << "R - Reports" << endl;
   cout << "S - Save and close the database" << endl;
   cout << "E - Exit the program" << endl;
   cout << "Enter Selection ->";
  
  char selection = ' ';
  cin.get(selection);
  cout << endl;
  cin.clear();
  cin.ignore(10,'\n');
  selection = toupper(selection);
  if ((selection != 'D')&(selection != 'M')&(selection != 'R')&(selection != 'S')&(selection != 'E'))
  {
   cout << "Unable to understand selection " << selection << ". Please try again" << endl;
   selection = ' ';
   
   return false;
  }
  else
  {
   cout << "You selected " << selection << "." << endl;
   
   if (selection == 'D')
   {
      //cout << "placehodler" << endl;
      retVal = describe();
   }
   else if (selection == 'M')
   {
      //cout << "placeholder - selected maintain interface" << endl;
      retVal = maintainInterface(ath);
   }
   else if (selection == 'R')
   {
      //cout << "PLACEHOLDER- SELECTED REPORTS INTERFACE" << endl;
      retVal = reportsInterface(ath);
   }
   else if (selection == 'S')
   {
      saveAndClose(ath);
      return false;
   }
   else if (selection == 'E')
   {
     cout << "Exiting..." << endl;
     retVal = true;
   }
   
  
  }
  return retVal;
  
}

bool describe()
{
   cout << "This is a program designed to interact with and keep " << endl;
   cout << "track of a database of Athletes, each with attributes " << endl;
   cout << "such as Name, Rank, and Sport. The Binary Search Tree data type is " << endl;
   cout << "used to store this database, and the athletes are " << endl;
   cout << "loaded from a text file." << endl;
   cout << "Returning to menu..." << endl << endl;
   
   return false;
}

bool maintainInterface(AthleteDatabase ath)
{
   cout << "WORLD'S HIGHEST PAID ATHLETES MAINTENANCE MENU" << endl;
   cout << "I - Insert new record" << endl;
   cout << "D - Delete existing record" << endl;
   cout << "R - Return to main menu" << endl;
   cout << "Enter Selection ->";
   
  char selection = '\0';
  cin.get(selection);
  cout << endl;
  cin.clear();
  cin.ignore(10,'\n');
  selection = toupper(selection);
  if ((selection != 'I')&(selection != 'D')&(selection != 'R'))
  {
   cout << "Unable to understand selection " << selection << ". Please try again" << endl;
   selection = '\0';
   
   maintainInterface(ath);
  }
  else
  {
   cout << "You selected " << selection << "." << endl;
   
   if (selection == 'I')
   {
      ath.insertRecord();
   }
   else if (selection == 'D')
   {
      ath.deleteEntryFromDb();
   }
   else if (selection == 'R')
   {
      cout << "Returning to main menu..." << endl;
      
      return false;
   }
   }

}

bool reportsInterface(AthleteDatabase ath)
{
   cout << "WORLD'S HIGHEST PAID ATHLETES REPORTS MENU" << endl;
   cout << "S - Sort by key name report" << endl;
   cout << "O - Order by rank report" << endl;
   cout << "R - Return to main menu" << endl;
   cout << "Enter Selection ->";
   
  char selection = ' ';
  cin.get(selection);
  cout << endl;
  cin.clear();
  cin.ignore(10,'\n');
  selection = toupper(selection);
  if ((selection != 'S')&(selection != 'O')&(selection != 'R'))
  {
   cout << "Unable to understand selection " << selection << ". Please try again" << endl;
   selection = ' ';
   
   reportsInterface(ath);
   
  }
  else
  {
   cout << "You selected " << selection << "." << endl;
   
   if (selection == 'S')
   {
      ath.displayKeyReport();
   }
   else if (selection == 'O')
   {
      ath.displayRankReport();
   }
   else if (selection == 'R')
   {
      cout << "Returning to main menu..." << endl;
      return false;
   }
   }

}

bool saveAndClose(AthleteDatabase ath)
{
   ath.saveDbToFile();
   return false;
}