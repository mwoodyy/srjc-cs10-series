// A program for drawing squares (actually, rectangles) using the +, - and | characters, for any input between 3 and 20.
// Programmer Name: Matthew Woody
// Assignment 5.2

#include <iostream>
using namespace std;

int main() {

  int size = 0;
  char again = 'Y'; // initalized so that loop will run once without user input then the user takes over

  cout << "**************** Drawing Squares Program ******************************\n * Algorithm generates a hollow square, using the character +, - and | * \n * Acceptable size dimension: Any value from 3 to 20. Choose carefully.* \n ***********************************************************************" << endl;

  while (again == 'Y')
    {
  cout << "Side size = ";
    while (!(cin >> size) || (size < 3 || size > 20)) // making sure it is an acceptable data type (int) and within desired range
      {
        cout << "OOPS! Looks like you typed some bad data here!" << endl << "The acceptable dimension should range from 3 to 20, so choose carefully..." << endl << "Side size = ";
        cin.clear(); // clears cin value so that loop does not run over and over again
        cin.ignore(100, '\n'); // skip over 100 characters until a newline is started (enter pressed)
      }

  if (size >= 3 && size <= 20) // loop for printing square in desired range
  {
cout << '+'; // corner
for (int i = 0; i < (size - 2); i++) // set variable for loop to run, in this case 'i', and conditon for it (i < (size -2)), and add 1 to i to keep count of row)
cout << '-'; // 
cout << '+' << endl;
  
for(int i = 0; i < (size - 2); i++) // same thing as before, just for the middle rows
{
cout << '|'; // print 1 character since there will always be one as long as the input value is in correct range
  
for (int j = 0; j < (size - 2); j++) // new int, j, this one is for the middle rows, so uses '|' and a space
cout << ' ';
cout << '|' << endl;
}
cout << '+';
  
for (int i = 0; i < (size - 2); i++) // same as first for statement, just for the bottom row
cout << '-';
cout << '+' << endl;
    }
      cout << "To try my shape generator program again type Y for Yes and N for No: "; // go again question to repeat initial while loop or not
      cin >> again;
      }
      
  cout << "Now exiting the shape generator program......." << endl; // printed when N is input
return 0; // and quits program

  // additional paragraph
  // Using while loops and for and if statement(s) I was able to draw the "squares". The while loops were for making sure the inputs were correct for the conditions required, and the for statements were "for" making the squares themselves. Within the for statements, the variable is set (i or j = 0) and will keep going (puntil the condition (int < (size - 2)) no longer becomes true, keeping a running total in accordance with the rows. With each iteration of the loops, the leftmost character is being printed, then the middle, and so on for each row. Once done printing, the program asks to go again and if the right input is entered, either restarts the program or exits.
  }