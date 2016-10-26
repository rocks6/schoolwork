/**
 * @file StudentDatabase.cpp
 * @author Professor Gregory
 * @date  January 2, 2015
 */
#include "StudentDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;


/**
 * Saves the contents of a tree node (a student) to the text file
 */
void saveData(Student& anItem)
{
   anItem.saveData(); 
   anItem.printStudent();
}


/**
 * Displays the contents of a tree node (a student)
 */
void display(Student& anItem)
{
   anItem.printStudent();
}


void StudentDatabase::createDatabase (void)
{
   Student item1("Martin", "54-yy", "410-555-2222");  // first student to add
   Student item2("Edwards", "33-rr", "410-555-1222"); // second student to add
   Student item3("Baker", "45-tt", "410-555-2122");   // third student to add
   Student item4("George", "72-dd", "410-555-2212");  // fourth student to add
   Student item5("Rogers", "27-xx", "410-555-2221");  // fifth student to add
   Student item6("Phillips", "98-ss", "410-555-1122");// sixth student to add
   Student item7("Turner", "89-ww", "410-555-2112");  // seventh student to add
   Student item8("Smith", "13-gg", "410-555-2211");   // eighth student to add
   cout << "Adding " << item1.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item1);
   cout << "Adding " << item2.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item2);
   cout << "Adding " << item3.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item3);
   cout << "Adding " << item4.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item4);
   cout << "Adding " << item5.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item5);
   cout << "Adding " << item6.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item6);
   cout << "Adding " << item7.getName() << " to binary search tree." << endl;
   studentDatabaseBST.add (item7);
   cout << "Adding " << item8.getName() << " to binary search tree." << endl << endl;
   studentDatabaseBST.add (item8);
   
   Student item9;  // student object to input from user
   cout << "Next person added to binary search tree will be entered by the user."
        << endl;
   item9.inputStudent(); // input a ninth student to add
   cout << "Adding " << item9.getName() << " to binary search tree." << endl << endl;
   studentDatabaseBST.add (item9);
   
   // find and delete George
   Student findStudent ("George", " ", " "); // Student object required as argument
   cout << "Searching for " << findStudent.getName() << " in binary search tree." 
        << endl;
   bool success; // true if operation is successful; false otherwise
   success = studentDatabaseBST.contains(findStudent); 
   if (success)
   {
      cout << "Found " << findStudent.getName() << " in binary search tree." << endl;
      success = studentDatabaseBST.remove(findStudent);
      if (success)
         cout << findStudent.getName() << " was successfully deleted from the"
              << " binary search tree." << endl;
      else
         cout << findStudent.getName() << " was NOT successfully deleted from"
              << " the binary search tree." << endl;
   }
   else
   {
      cout << "Error: "<< findStudent.getName() << " was NOT found in the"
           << " binary search tree." << endl;
   }
}


void StudentDatabase::displayData (void)
{
   cout << endl << "Inorder traversal" << endl;
   studentDatabaseBST.inorderTraverse(display);
   cout << endl << "Preorder traversal" << endl;
   studentDatabaseBST.preorderTraverse(display);
   cout << endl << "Postorder traversal" << endl;
   studentDatabaseBST.postorderTraverse(display);
}


void StudentDatabase::saveDatabase (void)
{
   // output the data to a text file
   cout << endl << "Saving all data in the binary search tree to a file named " 
        << OUTPUT_FILENAME << "." << endl;
   studentDatabaseBST.preorderTraverse(saveData);
   Student::closeOutputFile();
}




