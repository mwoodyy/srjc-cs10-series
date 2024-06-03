// A program for printing out the data of a file and counting the number of words in the file
// Programmer Name: Matthew Woody
// Assignment 6.1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

ifstream file_read;
string filename;

// variables to store previous character read, current character being read and the word count
char prevch = ' ';
char ch;
int wordcount;

// start of program
cout << "\n      *** A SIMPLE FILE PROCESSING PROGRAM ***\n";

// prompting for filename input
cout << "\n Enter file name or type quit to exit: ";
cin >> filename;

// loop until quit is input
do
{
// checking to see if filename is quit to leave loop
if (filename.compare("quit") == 0)
break;

// opening file
file_read.open(filename.c_str());

// making sure it is able to be read
if (!file_read)
{
// printing for new file input
cout << "\n File not found. Enter the correct filename: ";
cin >> filename;
}

else // loop for if file successfully opens
{
wordcount = 0; // sets the word count to 0 for each file
  
cout << filename << " data";
cout << "\n*********************\n";

// looping until the reading of the file is finished
while (!file_read.eof())
{
  
file_read.get(ch); // reading one character at a time, then printing it as per the requirements to print out the whole file
cout << ch;

// making sure that character read is part of a word, not a space or newline/return
if ((ch == ' ' || ch == '\n' || ch == '\r') && (prevch != ' ' && prevch != '\n' && prevch != '\r' ))

wordcount++;
prevch = ch;
}
  // additional logic for if the last character is not a space or newline/return, and adds to wordcount (only applicable for file1 and file2)
if (ch != ' ' && ch != '\n' && ch != '\r')
{
  wordcount++;
  }
// closing the read file
file_read.close();

// printing results of program
cout << "\n************************\n";
cout << filename <<" has " << wordcount << " words." << endl;

  // asking for input again to repeat program
cout << "\n Enter another file name or type quit to exit: ";
cin >> filename;
}
} while(1); // end of do-while loop for quitting
  cout << "Now exiting the program........" << endl;
  return 0;
}