// A program for finding the sum of two numbers and then waiting for user input to display the answer
// Programmer Name: Matthew Woody
// Assignment 2.2

#include <iostream>
#include <iomanip> // needed for setw
using namespace std;

int main()  

{
  
  // create variables to store input values in
  int var1;
  int var2;
  // get input of the two numbers
  cin >> var1;
  cin >> var2;

  // displaying the addition of the two numbers
  cout << "\n";
  cout << setw(5) << var1 << endl; 
  cout << "+" << setw(4) << var2 << endl;
  cout << "-------" << endl;
  cout << "\n";
  int answer = var1 + var2;

  // getting input to show answer
  cout << "\nPress Enter to see the answer...\n";
    cin.ignore();
    cin.get();

  // showing answer
  cout << setw(5) << var1 << endl; 
  cout << "+" << setw(4) << var2 << endl;
  cout << "-------" << endl;
  cout << setw(5) << answer << endl;

  return 0;
    
}

