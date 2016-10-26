/*
* @author Steven Byerly
* @file AthleteDatabase.cpp
* @desc provide a data type for the athlete database
*/
#include "AthleteDatabase.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

AthleteDatabase::AthleteDatabase()
{
   //BinarySearchTree<Athlete> athleteDB;
   //createDatabase();
}

//Athlete AthleteDatabase::foundEntry("null","null",999.99,999.99,999.99,"null");

void AthleteDatabase::createDatabase()
{
   ifstream inFile ("WorldsHighestPaidAthletes.csv");
   while (inFile.good())
   {
      
      string buffer;
      getline(inFile, buffer);
      string lastname_internal = buffer.substr(0, buffer.find(","));
      
      string buffer2 = buffer.substr(buffer.find(",")+1,buffer.length());
      string firstname_internal = buffer2.substr(0, buffer2.find(","));
      
      string buffer3 = buffer2.substr(buffer2.find(",")+1,buffer2.length());
      string rank_internal_str = buffer3.substr(0, buffer3.find(","));
      int rank_internal_int = atoi(rank_internal_str.c_str());
      
      string buffer4 = buffer3.substr(buffer3.find(",")+1,buffer3.length());
      string earnings_internal_str = buffer4.substr(0, buffer4.find(","));
      double earnings_internal_fl = atof(earnings_internal_str.c_str());
      
      string buffer5 = buffer4.substr(buffer4.find(",")+1,buffer4.length());
      string salary_internal_str = buffer5.substr(0, buffer5.find(","));
      double salary_internal_fl = atof(salary_internal_str.c_str());
      
      string buffer6 = buffer5.substr(buffer5.find(",")+1,buffer5.length());
      string endorsements_internal_str = buffer6.substr(0, buffer6.find(","));
      double endorsements_internal_fl = atof(endorsements_internal_str.c_str());
      
      string buffer7 = buffer6.substr(buffer6.find(",")+1,buffer6.length());
      string sport_internal = buffer7.substr(0, buffer7.find(","));
      
      if (rank_internal_int != 0)
      {
         Athlete testAthlete(lastname_internal, firstname_internal, rank_internal_int, earnings_internal_fl, salary_internal_fl, endorsements_internal_fl, sport_internal);
         athleteDB.add(testAthlete);
      }
   }
}

void AthleteDatabase::insertRecord()
{
   string lastname_i;
   string firstname_i;
   int rank_i;
   double earnings_i;
   double salary_i;
   double endorsements_i;
   string sport_i;
   bool valid = false;
   while (valid == false)
   {
      
     cout << "Please enter last name of new Athlete:" << endl;
     cin >> lastname_i;
     if (cin.fail() || lastname_i.length() > 20)
     {
        cout << "Please enter a string of length < 20.  " << endl;
        cin.clear();
        //cin. ignore(100000, '\n');
        
     }
     else
     {
        valid = true;
     }
   }
        
   valid = false;
   while (valid == false)
   {   
     cout << "Please enter first name of new Athlete:" << endl;
     cin >> firstname_i;
     if (cin.fail() || firstname_i.length() > 20)
     {
        cout << "Please enter a string of length < 20.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
        valid = true;
     }
   }
   
   valid = false;
   while (valid == false)
   {  
     cout << "Please enter the athlete's rank: " << endl;
     cin >> rank_i;
     if (cin.fail() || (rank_i > 10000))
     {
        cout << "Please enter an integer less than 10000.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
        valid = true;
     }
   } 
    
   valid = false;
   while (valid == false)
   {  
     cout << "Please enter the athlete's total earnings in millions: " << endl;
     cin >> earnings_i;
     if (cin.fail() || (earnings_i > 1000000))
     {
        cout << "Please enter a double less than 1000000.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
        valid = true;
     }
   }
   valid = false;
   while (valid == false)
   {
     cout << "Please enter the athlete's salary/winnings in millions: " << endl;
     cin >> salary_i;
     if (cin.fail() || (salary_i > 1000000))
     {
        cout << "Please enter a double less than 1000000.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
        valid = true;
     }
   }
   valid = false;
   while (valid == false)
   {  
     cout << "Please enter the athlete's endorsements in millions: " << endl;
     cin >> endorsements_i;
     if (cin.fail() || (endorsements_i > 1000000))
     {
        cout << "Please enter a double less than 1000000.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
     valid = true;
     }
   }
   valid = false;
   while (valid == false)
   {
     
     cout << "Please enter the athlete's sport: " << endl;
     cin >> sport_i;
     if (cin.fail() || (sport_i.length() > 20))
     {
        cout << "Please enter a string with length < 20.  " << endl;
        cin.clear();
        cin. ignore(100000, '\n');
        
     }
     else
     {
     valid = true;
     }
   }
     
     cout << "You entered: " << endl;
     cout << "Last name: " << lastname_i << endl;
     cout << "First name: " << firstname_i << endl;
     cout << "Rank: " << to_string(rank_i) << endl;
     cout << "Total earnings: " << to_string(earnings_i) << endl;
     cout << "Salary/Winnings: " << to_string(salary_i) << endl;
     cout << "Endorsements: " << to_string(endorsements_i) << endl;
     cout << "Sport: " << sport_i << endl;
     cout << "Input y to confirm addition to database" << endl;
     
     string selection;
     cin >> selection;
     if ((selection != "y") && (selection != "Y"))
     {
        cout << "Insertion to database aborted. Exiting..." << endl;
        valid = true;
        cin.clear();
        return;
     }
     else
     {  
        //compile keynames to file
        compileKeynames();
        //load keynames into vector for comparison
        vector<string> keynameVector;
        ifstream keynameFile;
        keynameFile.open("tempKeynameDump.txt");
        string buffer;
        while (getline(keynameFile, buffer))
        {
            keynameVector.push_back(buffer);
        }
        
        bool flag = false;
        //check keyname vector for existing athlete with that keyname
        if (find(keynameVector.begin(), keynameVector.end(), lastname_i) != (keynameVector.end())) 
        {
            cout << "Athlete with keyname (last name) " << lastname_i << " found in database." << endl;
            cout << "Would you like to delete it and continue (y) or abort (any other entry)?" << endl;
            string sel;
            cin >> sel; 
            if (sel == "y")
            {
               flag = true;
               deleteEntryByKeyname(lastname_i);               
            }
            else 
            {
               cout << "Aborting... " << endl;
               cin.clear();
               return;
            }
        }
        
        //append the deleted athlete entry to the csv file if necessary
        if (flag)
        {
           string craftedAthleteLine = lastname_i + "," + firstname_i + "," + to_string(rank_i) + "," + to_string(earnings_i) + "," + to_string(salary_i) + "," + to_string(endorsements_i) + "," + sport_i;
           cout << "DEBUG: " << craftedAthleteLine << endl;
           ofstream temp;
           temp.open("WorldsHighestPaidAthletes.csv", ofstream::app);
           temp << craftedAthleteLine << endl;
        }
        
        //continue with insertion
        cout << "Creating athlete object..." << endl;
        Athlete newAthlete(lastname_i, firstname_i, rank_i, earnings_i, salary_i, endorsements_i, sport_i);
      
        cout << "Adding entry to database..." << endl;
        athleteDB.add(newAthlete);
        
        cout << "Insertion successful! Returning..." << endl;
        valid = true;
        
        cout << "Cleaning up keyname file..." << endl;
        keynameFile.close();
        remove("tempKeynameDump.txt");
        cin.clear();
        
        return;
     }
     
     
   
}


/*
* helper method for compileKeynames that adds a single last name of an athlete to file
* @params : waldo the keyname to add
*/
void addKeynameToFile(Athlete& waldo)
{
   ofstream temp;
   temp.open("tempKeynameDump.txt", ofstream::app);
   temp << waldo.getLastName() << endl;
   temp.close();
}

void AthleteDatabase::compileKeynames()
{
   cout << "Compiling keyname list for comparisons..." << endl;
   athleteDB.preorderTraverse(addKeynameToFile);
   cout << "Keyname list compiled successfully to tempKeynameDump.txt!" << endl;
   
}

//Athlete AthleteDatabase::getFoundEntry()
//{
//   return foundEntry;
//}

//void AthleteDatabase::setFoundEntry(Athlete newObject)
//{
//  foundEntry = newObject;
//}
/*
void AthleteDatabase::deleteEntryFromDb2(Athlete& athleteToDelete)
{
   athleteDB.remove(athleteToDelete);
}
*/

void checkForTargetDelete(Athlete& waldo)
{
   ifstream inputFile;
   inputFile.open("temp.txt");
   string target;
   getline(inputFile,target);
   
   if (waldo.getLastName() == target)
   {
      cout << "Target found! Data of target: " << endl;
      cout << waldo.getLastName() << "," << waldo.getFirstName() << "," << to_string(waldo.getRank()) << "," << to_string(waldo.getEarnings()) << "," << to_string(waldo.getSalary()) << "," << to_string(waldo.getEndorsements()) << "," << waldo.getSport() << endl;
      cout << "Please confirm deletion: (y)" << endl;
      string selection;
      cin >> selection;
      if ((selection == "y") ||(selection == "Y"))
      {
         ifstream inFile ("WorldsHighestPaidAthletes.csv");
         ofstream temp("temporaryAthleteStorage.txt");
               
         while (inFile.good())
         {
            string buffer;
            getline(inFile, buffer);
            string lastname_internal = buffer.substr(0, buffer.find(","));
            if (!(lastname_internal == target))
            {
               temp << buffer << endl;
            }
         }
         remove("WorldsHighestPaidAthletes.csv");
         rename("temporaryAthleteStorage.txt", "WorldsHighestPaidAthletes.csv");
         
         
         cout << "Deletion successful!" << endl;   
         return;
      }
      else
      {
         cout << "Deletion aborted." << endl;
         return;
      }
      
      /*
      ofstream outputFile;
      outputFile.open("found.txt");
      outputFile << waldo.getLastName() << "," << waldo.getFirstName() << "," << waldo.getEarnings() << "," << waldo.getSalary() << "," << waldo.getEndorsements() << "," << waldo.getSport() << endl;
      outputFile.close();
      */   
   }
   inputFile.close();
}

void AthleteDatabase::searchForTarget(string target)
{
   ofstream outputFile;
   outputFile.open("temp.txt");
   outputFile << target << endl;
   outputFile.close();
   //targetKey = target;
   //foundEntry.setLastName("null");
   athleteDB.preorderTraverse(checkForTargetDelete);
   
   athleteDB.clear();
   createDatabase();
   
   /*if (foundEntry.getLastName() == "null")
   {
      return false;
   }
   else
   {
      foundEntry.setLastName("null");
      return true;
   }*/
}

/*
* helper method to save the athlete db to a file
*/
void saveAthleteToFile(Athlete& waldo)
{
   ofstream opfile;
   opfile.open("UpdatedAthletes.txt", ofstream::app);
   //cout << "DEBUG: FOUND ATHLETE WITH KEYNAME " << waldo.getLastName() << endl;
   opfile << waldo.getLastName() << "," << waldo.getFirstName() << "," << to_string(waldo.getRank()) << "," << to_string(waldo.getEarnings()) << "," << to_string(waldo.getSalary()) << "," << to_string(waldo.getEndorsements()) << "," << waldo.getSport() << endl;
   opfile.close();
}

void AthleteDatabase::saveDbToFile()
{
   cout << "Cleaning up old UpdatedAthletes.txt file, if it exists..." << endl;
   remove("UpdatedAthletes.txt");
   cout << "Saving Athlete database to file UpdatedAthletes.txt..." << endl;
   athleteDB.preorderTraverse(saveAthleteToFile);
   cout << "File save success! Cleaning up BST..." << endl;
   //athleteDB.
}

/*
void AthleteDatabase::initializeFoundEntry()
{
   foundEntry.setLastName("null");
   foundEntry.setFirstName("null");
   foundEntry.setEarnings(10000);
   foundEntry.setSalary(999.99);
   foundEntry.setEndorsements(999.99);
   foundEntry.setSport("null");
}*/

/*
* helper method for the displayKeyReport class
* params : waldo an athlete to display
*/
void displayByKey(Athlete& waldo)
{
   if (waldo.getEarnings() != 0.0)
   {
      cout << waldo.getLastName() << ", " << waldo.getFirstName() << ", " << to_string(waldo.getRank()) << ", " << to_string(waldo.getEarnings()) << ", " << to_string(waldo.getSalary()) << ", " << to_string(waldo.getEndorsements()) << ", " << waldo.getSport() << endl; 
   }
}

void AthleteDatabase::displayKeyReport()
{
   cout << "Athlete entries will be displayed in the format below sorted by keyname (last name):" << endl;
   cout << "Last name, First name, Rank, Earnings, Salary, Endorsements, Sport" << endl;
   athleteDB.inorderTraverse(displayByKey);
   return;
   
}

/*
* helper method for displayRankReport method
* @params : waldo an athlete to display
*/
void displayByRank(Athlete& waldo)
{
   ifstream inputFile;
   inputFile.open("temp.txt");
   string iterator;
   int iterator_int;
   getline(inputFile,iterator);
   iterator_int = stoi(iterator);
   
   if (iterator_int == waldo.getRank())
   {
      cout << waldo.getLastName() << ", " << waldo.getFirstName() << ", " << to_string(waldo.getRank()) << ", " << to_string(waldo.getEarnings()) << ", " << to_string(waldo.getSalary()) << ", " << to_string(waldo.getEndorsements()) << ", " << waldo.getSport() << endl; 
   }
   inputFile.close();
}

void AthleteDatabase::displayRankReport()
{
   cout << "Athlete entries will be displayed in the format below sorted by rank:" << endl;
   cout << "Last name, First name, Rank, Earnings, Salary, Endorsements, Sport" << endl;
   athleteDB.clear();
   createDatabase();
   for (int i=1;i<101;i++)
   {
      
      ofstream outputFile;
      outputFile.open("temp.txt");
      outputFile << i << endl;
      athleteDB.preorderTraverse(displayByRank);
      outputFile.close();
      remove("temp.txt");
   }  
}

void AthleteDatabase::deleteEntryByKeyname(string keyname)
{ 
   searchForTarget(keyname);
}

void AthleteDatabase::deleteEntryFromDb()
{
   //initializeFoundEntry();
   bool valid = false;
   while (valid == false)
   {
      cout << "Please entry the key name (last name) of the athlete you would like to delete." << endl;
      string selection;
      cin >> selection;
      if (cin.fail())
      {
         cout << "Error: Please enter a string." << endl; 
      }
      else
      {
         //ATTEMPT 2
         cout << "Searching for entry. If no further output, no entry was found with that keyname." << endl;
         searchForTarget(selection);
         valid = true;
         /*
         //ATTEMPT 1
         cout << "Searching for entry with keyname " << selection << endl;
         if (searchForTarget(keyname) == false)
         {
            cout << "Entry not found. Please try again" << endl;
         }
         else 
         {
            
            

            cout << "Entry found with: " << endl;
            cout << "Last name: " << keyname << endl;
            cout << "First name: " << foundEntry.getFirstName() << endl;
            cout << "Rank: " << to_string(foundEntry.getRank()) << endl;
            cout << "Earnings: " << to_string(foundEntry.getEarnings()) << endl;
            cout << "Salary/Winnings: " << to_string(foundEntry.getSalary()) << endl;
            cout << "Endorsements: " << to_string(foundEntry.getEndorsements()) << endl;
            cout << "Sport: " << foundEntry.getSport() << endl;
            cout << "Please confirm deletion (y)" << endl;
            string selection2;
            cin >> selection2;
            
            if ((selection2 == "y") || (selection2 == "Y"))
            {
               foundEntry.setLastName(keyname);
               bool success;
               success = athleteDB.remove(foundEntry);
               if (success)
               {
                  cout << "Deletion successful." << endl;
                  foundEntry.setLastName("null");
                  return;
               }
               else
               {
                  cout << "Deletion failed." << endl;
                  foundEntry.setLastName("null");
                  return;
               }
            }
            else
            {
               cout << "Deletion aborted. Exiting" << endl;
               return;
            }
            
         }
      */
      }
      
   }
   //reinitialize database
   createDatabase();
}

/*
string AthleteDatabase::getTargetKey()
{
   return targetKey;
}

string AthleteDatabase::setTargetKey(string newTargetKey)
{
   targetKey = newTargetKey;
}
*/