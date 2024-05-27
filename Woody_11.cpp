#include <iostream>
#include <string>
using namespace std;

int main ()
{
 // string for first and last rows of diamond
  string one_seven;
  one_seven = "   *   " ;
  // string for 2nd and 6th rows of diamond
 string two_six;
  two_six = "  ***  " ;
  // string for 3rd and 5th rows of diamond
  string three_five;
  three_five = " ***** " ;
  // string for 4th row of diamond
  string four;
    four = "*******" ;

// print lines of diamond
  cout << one_seven << endl;
  cout << two_six << endl;
  cout << three_five << endl;
  cout << four << endl;
  cout << three_five << endl;
  cout << two_six << endl;
  cout << one_seven << endl;
}