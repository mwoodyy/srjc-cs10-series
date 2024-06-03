// A program for testing Collatz's hypothesis and manipulating the input with the conditions of the hypothesis until it reaches 1, as well as keeping track of how many steps it took to get to 1
// Programmer Name: Matthew Woody
// Assignment 5.1

#include <iostream>
using namespace std;

int main() {
  int c0;
  int count = 0; // number of steps

  cout << "Enter a non negative number greater than 0: ";
  cin >> c0;

  while (c0 <= 0) // input validation loop, includes other loop or else program would not work if an invalid input was entered twice or more
    {
    {
      cout << "Invalid value input" << endl;
      cout << "Enter a non negative number greater than 0: ";
      cin >> c0;
    }
  while (c0 > 0 && c0 != 1) // nested while loop for the hypothesis, conditional on positive and not 1
    {
      if (c0 % 2 == 0) // if statement for if c0 is even
      {
        c0 = c0 / 2;
        count++;
        }
      else // if c0 is odd
      {
        c0 = (3 * c0) + 1;
        count++;
        }
    cout << c0 << endl; // prints number then returns to beginning of loop
    }
      }
  if (c0 == 1) // leave loop once c0 = 1
    cout << "steps = " << count << endl;
  return 0;
  }
    
  