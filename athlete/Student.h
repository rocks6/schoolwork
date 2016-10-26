/**
 * @file Student.h
 * @author Professor Gregory
 * @date  January 2, 2015
 * @class Student
 * Node type to be stored in the ADT binary search tree. It consists of
 * the name (the key), id number, phone number, and the output filename. 
 */
#ifndef STUDENT_H

#include <string>
#include <fstream>
using namespace std;

/**
 * Name of file in which to save all output data
 */
const string OUTPUT_FILENAME = "studentOutFile.txt";


class Student
{
private:
   /** 
    * Student's name, the key 
    */
   string name;
   
   /** 
    * Student's id number 
    */
   string idNum;
   
   /** 
    * Student's telephone number, including area code and dashes 
    */
   string phoneNumber;

   /**
    * Output file to store the data for a student. Note this is a
    * static data member, so there is only one copy of it for all
    * Student objects. It MUST be defined and intialized (opened)
    * in the implementation file.
    */
   static ofstream outFile;

public:
   /**
    * Default constructor
    */
   Student();

   /**
    * Overloaded constructor
    * @param name - student's name; value for search key
    * @param newIdNum - value for student's idnum
    * @param newPhoneNumber - value for student's phone number
    */
   Student(const string& name,
          const string& newIdNum,
          const string& newPhoneNumber);
          
   /**
    * Accessor for the name.
    * @return name of this person, the key
    */
   string getName(void);

   /**
    * Displays all the data stored for a student.
    */
   void printStudent(void);

   /**
    * Inputs data for a student object, providing specific instructions
    * for the user and validating the input data.
    */
   void inputStudent(void);

   /**
    * Outputs the data to the output file. 
    */
   void saveData();

   /**
    * Defines the > operator for a Student object. 
    * @param right - right hand Student object for comparison 
    *                to the this Student object using >
    */
   bool operator> (const Student &right);

   /**
    * Defines the < operator for a Student object. 
    * @param right - right hand Student object for comparison 
    *                to the this Student object using <
    */
   bool operator< (const Student &right);

   /**
    * Defines the == operator for a Student object. 
    * @param right - right hand Student object for comparison 
    *                to the this Student object using ==
    */
   bool operator== (const Student &right);

   /**
    * Closes the output file. This method MUST be called before the
    * program terminates.
    */
   static void closeOutputFile();
}; // end Student
#define STUDENT_H
#endif
