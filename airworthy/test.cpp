#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>

using namespace std;


int main()
{
   double test = 10.0/3.0;
   string testStr = to_string(test);
   cout << testStr.substr(0,testStr.find(".")+3);
}