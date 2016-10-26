/**
 * @file Student.cpp
 */
#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

ofstream Student::outFile(OUTPUT_FILENAME.c_str());  // define and open static
                                                     // output file
Student::Student()
{
}


Student::Student(const string& newName,
       const string& newIdNum,
       const string& newPhoneNumber)
       : name(newName), idNum(newIdNum),
      phoneNumber(newPhoneNumber)
{
}


string Student::getName(void)
{
   return name;
}


void Student::printStudent(void)
{
     cout << left << "Name: " << setw(10) << name << "  IdNum: " << setw(5) 
          << idNum << "  Phone: " << phoneNumber << endl;
}


void Student::inputStudent(void)
{
   string inputData;
   bool validInput = false;
   
   while (!validInput)
   {
      cout << "Enter last name for new person. Use uppercase for only the" << endl
           << "first letter:" << endl;
      getline(cin, inputData);
      if (isupper(inputData[0]))
      {
         name = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid name. Please try again." << endl;
   }
   
   validInput = false;
   while (!validInput)
   {
      cout << "Enter id number for new student, in the form ##-aa," << endl
           << "(i.e., two numbers, a dash, and two letters):" << endl;
      getline(cin, inputData);
      if (inputData.length() == 5 
          && isdigit(inputData[0]) && isdigit(zinputData[1]) && inputData[2] == '-'
          && isalpha(inputData[3]) && isalpha(inputData[4]))
      {
         idNum = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid id number. Please try again." << endl;
   }
   
   validInput = false;
   while (!validInput)
   {
      cout << "Enter phone number for new student in the form ###-###-####:" << endl;
      getline(cin, inputData);
      if (inputData.length() == 12
          && isdigit(inputData[0]) && isdigit(inputData[1]) && isdigit(inputData[2])
          && inputData[3] == '-' && isdigit(inputData[4]) && isdigit(inputData[5])
          && isdigit(inputData[6]) && inputData[7] == '-' && isdigit(inputData[8])
          && isdigit(inputData[9]) && isdigit(inputData[10]) && isdigit(inputData[11]))
      {
         phoneNumber = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid phone number. Please try again." << endl;
   }
}


void Student::saveData()
{
   if (outFile)
      outFile << name << "," << idNum << "," << phoneNumber << endl;
   else
       cout << "Error: Output file " << OUTPUT_FILENAME 
            << " is not ready for output." << endl << endl;
}


bool Student::operator> (const Student &right)
{
   return (name > right.name);
}



bool Student::operator< (const Student &right)
{
   return (name < right.name);
}


bool Student::operator== (const Student &right)
{
   return (name == right.name);
}

void Student::closeOutputFile()
{
   outFile.close();
}

