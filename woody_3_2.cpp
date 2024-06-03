// A program for calculating a users monthly bill of 3 different internet service packages
// Programmer Name: Matthew Woody
// Assignment 3.2

#include <iostream>
using namespace std;

int main() 
{
  // selecting package
  char package;
  cout << "Select a subscription package:" << endl;
  cout << "1. Package A" << endl;
  cout << "2. Package B" << endl;
  cout << "3. Package C" << endl;
  cout << "4. Quit\n" << endl;
  cin >> package;
  
  // variables for computing the total amount due
  int hours;
  double total1;
  double total2;
  double total3;
  const double pack1rate = 9.95;
  const double pack2rate = 14.95;
  const int pack1hours = 10;
  const int pack2hours = 20;
  const int add1 = 2;

  // switch statement
  switch (package)
    {
      // package A
      case '1': cout << "PACKAGE A:" << endl << "============" << endl;
      cout << "How many hours were used? ";
        cin >> hours;
      cout << "Package A: $9.95 per month 10 hours of access are provided." << endl << "Additional are $2.00 per hour." << endl << "Usage quota not to exceed 730 hours" << endl;
        // if/else statement for if hours > 10 then determining the total and if hours < 10 then displaying the base package with no additional fees.
        if (hours > 10)
        {
          total1 = hours - pack1hours;
          total2 = total1 * add1;
          total3 = total2 + pack1rate;
      cout << "The total amount due is $" << total3 << endl;
          }
      else
        {
        cout << "The total amount due is $" << pack1rate << endl;
          }
      break;

      // package B
      case '2': cout << "PACKAGE B:" << endl << "============" << endl;
      cout << "How many hours were used? ";
        cin >> hours;
      cout << "Package A: $14.95 per month 20 hours of access are provided." << endl << "Additional are $1.00 per hour." << endl << "Usage quota not to exceed 730 hours" << endl;
        if (hours > 10)
        {
          total1 = hours - pack2hours;
          total2 = total1 + pack2rate;
      cout << "The total amount due is $" << total2 << endl;
          }
      else
        {
        cout << "The total amount due is $" << pack2rate << endl;
          }
      break;

      // Package C
      case '3': cout << "PACKAGE C:" << endl << "============" << endl;
      cout << "How many hours were used? ";
        cin >> hours;
      cout << "Package C: $19.95 per month, a flat rate." << endl << "Usage quota not to exceed 730 hours" << endl << "The total amount due is $19.95" << endl;
      break; 

      // quitting the program
      case '4': return 0;
      break;
      
      // input validation of 1 through 4
      default: cout << "The valid choices are 1 through 4." << endl << "Run the program again and select one of those." << endl;
      }
  
  return 0;
}