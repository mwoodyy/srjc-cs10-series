// A program for a binary calculator
// Programmer name: Matthew Woody
// Assignment: Algorithm Workbench 3

#include <iostream>
using namespace std;

int main()
{
  // variables for two numbers, their result and the desired operation
  double var1;
  double var2;
  double result;
  char operation;

  // getting input of numbers and operation
  cout << "Input your first number: " << endl;
  cin >> var1;
  cout << "Input your second number: " << endl;
  cin >> var2;
  cout << "Input your operation (+ , - , * , /)" << endl;
  cin >> operation;

  // switch statement for which operation to perform
  switch (operation)
    {
      // addition
    case '+': result = var1 + var2;
    cout << "\nThe sum of " << var1 << " and " << var2 << " is " << result << "." << endl;
    break;

      // subtraction
    case '-': result = var1 - var2;
    cout << "\nThe difference of " << var1 << " and " << var2 << " is " << result << "." << endl;
    break;

      // multiplication
    case '*': result = var1 * var2;
    cout << "\nThe product of " << var1 << " and " << var2 << " is " << result << "." << endl;
    break;

      // division
      case '/': result = var1 / var2;
      cout << "\nThe quotient of " << var1 << " and " << var2 << " is " << result << "." << endl;
      break;

      // input validation
      default: cout << "Input a valid operation!" << endl;
      }
  return 0;
}