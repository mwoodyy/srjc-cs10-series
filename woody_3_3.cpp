// A program for finding the cost of a long distance call as well as any discounts applied
// Programmer Name: Matthew Woody
// Assignment 3.3

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  // variables for input and constants for various factors (rate, tax and discounts)
  int start_time;
  int length;
  double cost;
  const double rate = 0.35;
  const double tax = 1.04;
  const double long60 = 0.84;
  const double discount_half = .5;
  // "floater" variables for computations as well as gross and net costs
  double var1;
  double var2;
  double gross_cost;
  double net_cost;

  // getting input
  cout << "Enter start time: ";
  cin >> start_time;
  cout << "Enter length of call in minutes: ";
  cin >> length;
  // initial if statement to determine if the call should be discounted 50%
  if (start_time >=1800 || start_time < 800)
  {
    // next if statement to determine if call should get the discount for being longer than 60 minutes
    if (length > 60)
    {
      gross_cost = length * rate;
      var1 = gross_cost * discount_half;
      var2 = var1 * long60;
      net_cost = var2 * tax;
      }
      // else statement for if call is not longer than 60 minutes
    else
    {
      gross_cost = length * rate;
      var1 = gross_cost * discount_half;
      net_cost = var1 * tax;
    }
  }
    // else statement to first if statement for when call should not be discounted 50%
  else
  {
    // if statement for if call should get the discount for being longer than 60 minutes
    if (length > 60)
    {
      gross_cost = length * rate;
      var1 = gross_cost * long60;
      net_cost = var1 * tax;
      }
      // else statement for if call is not longer than 60 minutes
    else
    {
      gross_cost = length * rate;
      net_cost = gross_cost * tax;
    }
    }
  
  // outputting gross and net costs truncated to 2 decimal places
  cout << setprecision(2) << fixed << "gross cost: $" << gross_cost << endl;
  cout << "net cost: $" << net_cost << endl;
  
  return 0;
}