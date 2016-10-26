#include <iostream>
#include <istream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Athlete.h"
#include "Athlete.cpp"

using namespace std;

int main()
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
      
      
      Athlete testAthlete(lastname_internal, firstname_internal, rank_internal_int, earnings_internal_fl, salary_internal_fl, endorsements_internal_fl, sport_internal);
      athleteBST.add(testAthlete);
      
   }

}
/*
Athlete(const string C_lastname, const string C_firstname, const int C_rank, 
         const double C_totalearnings, const double C_salary, const double C_endorsements, const string C_sport);

*/