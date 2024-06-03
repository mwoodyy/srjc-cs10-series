// A program for converting U.S. dollars into Japanese yen, South African rand, Israeli shekel and European euros
// Programmer Name: Matthew Woody
// Assignment 2.4

#include <iostream>
#include <iomanip>
using namespace std;
int main()
 
{
  // constants for exchange rates
  // I found these rates on https://markets.ft.com/data/currencies and google finance (only shekel)
  const double YEN_PER_DOLLAR = 144.091;
  const double RAND_PER_DOLLAR = 17.5057;
  const double SHEKEL_PER_DOLLAR  = 0.2911;
  const double EUROS_PER_DOLLAR = 1.0002;
  
  // variable for dollars
  double dollars;
  
  // asking for input
  cout << "Amount of U.S currency to convert: $";
  cin >> dollars;
  cout << endl;

  // calculating amounts of foreign currency
  double yen = dollars * YEN_PER_DOLLAR;
  double rand = dollars * RAND_PER_DOLLAR;
  double shekel = dollars * SHEKEL_PER_DOLLAR;
  double euros = dollars * EUROS_PER_DOLLAR;
  
  // displaying converted values
  char money = '$';
  cout << "\nFOREIGN CURRENCIES CONVERTED";
  cout << "\n----------------------------\n";
  cout << endl;
  cout << fixed << setprecision(2) << money << dollars << " = " << yen <<  " Yen (JAPAN)" << endl;
  cout << money << dollars << " = " << rand <<  " Rand (SOUTH AFRICA)" << endl;
  cout << money << dollars << " = " << shekel <<  " Shekel (ISRAEL)" << endl;
  cout << money << dollars << " = " << euros <<  " Euros (EUROPEAN UNION)" << endl;
  
}