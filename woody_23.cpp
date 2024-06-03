// A program for making change with number of cents entered
// Programmer Name: Matthew Woody
// Assignment 2.3

#include <iostream>
using namespace std;

int main()
{
  // getting input of cents
  int cents;
  cout << "Please enter number of cents: ";
  cin >> cents;

  // variables for the types of coins
  int quarters;
  int dimes;
  int nickels;
  int pennies;
  // calculating number of quarters to give
  quarters = cents / 25;
  cents = cents % 25; // the hardest part of this assignment was figuring out that the 'cents' integer should change every time a computation was performed so that the values would be correct for the next type of coin in the program.

  // calculating number of dimes to give
  dimes = cents / 10;
  cents = cents % 10;

  // calculating number of nickels to give
  nickels = cents / 5;
  cents = cents % 5;

  // calculating pennies to give
  pennies = cents; // we can set the int pennies equal to the int cents, since they are the same thing after the amounts of the other coins have been computed

  // change in ascending order
   cout << "\nChange displayed in ascending order" << endl;
  cout << "-------------------------------" << endl;
  cout << "pennies: " << pennies << endl;
  cout << "nickels: " << nickels << endl;
  cout << "dimes: " << dimes << endl;
  cout << "quarters: " << quarters << endl;
  
  // change in descending order
  cout << "\nChange displayed in descending order" << endl;
  cout << "-------------------------------" << endl;
  cout << "quarters: " << quarters << endl;
  cout << "dimes: " << dimes << endl;
  cout << "nickels: " << nickels << endl;
  cout << "pennies: " << pennies << endl;
  
return 0;
}