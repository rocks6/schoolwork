/**
 * @file StudentDatabase.h
 * @author Professor Gregory
 * @date January 2, 2015
 * @class StudentDatabase
 * This class creates a database using a BinarySearchTree to store
 * items of the Student class type. It creates some Student objects, 
 * adds them to a binary search tree, inputs data for a Student object
 * and adds that student to the tree. It searches for a Student object,
 * removing that Student object if it was found. Next, it displays the 
 * data using all three types of tree traversals, and then saves the 
 * data to a text file using a preorder traversal.
 */
#ifndef STUDENTDATABASE_H
#include "BinarySearchTree.h"
#include "Student.h"
using namespace std;

class StudentDatabase
{
private:
   /**
    * binary search tree to store Person data
    */
   BinarySearchTree<Student> studentDatabaseBST;

public:
   /**
    * Creates a database consisting of Student objects.
    */
   void createDatabase (void);

   /**
    * Displays the data in the database using inorder,
    * preorder, and postorder traversals.
    */
   void displayData (void);

   /**
    * Saves the database to an output file using a preorder
    * traversal.
    */
   void saveDatabase (void);
};

#define STUDENTDATABASE_H
#endif



