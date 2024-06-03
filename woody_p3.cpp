// A program for taking 10 scores, by user input or file input and analyzing them through user choices
// Programmer Name: Matthew Woody
// Project 3

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function prototypes
int menuSwitch(int choice, int score[], int size); //menu options
void getIntegers(int score[], int size); //read integers from user
void getScores_file(int score[], int size); //read scores from scores.txt
void printScores(int score[], int size); //printing the scores
void printHighest(int score[], int size); //highest score
void printLowest(int score[], int size); //lowest score
void printAverage(int score[], int size); //average score
void printEntry(int score[], int size, int entry); //printing a score based on the entry number entered
void displayMenu(); // cout statements

int main()
{
int score[10] = {0,0,0,0,0,0,0,0,0,0}; // initialized to 0 so nothing gets messed up if options 1 or 2 are not chosen first
int size = 10; //array size
int choice; // variable for what option to choose

do
{
displayMenu();
cin >> choice;

while (choice <= 0 || choice >= 9) // input validation loop
{
  cin.ignore();
  cin.clear();
  cout << "INVALID CHOICE ...please retype" << endl;
  displayMenu();
  cin >> choice;
}
menuSwitch(choice, score, size); // getting to switch statement for each option
}while (choice != 8); //overall input loop, making sure input is valid, repeating program if not (or not equal to 8) and if input is good then doing the desired option

if (choice == 8)
  {
    cout << "\nArray processing test now concluded. Exiting program ....." << endl;
    return 0;
  }
}

int menuSwitch(int choice,int score[], int size) // function containing switch statement calling the corresponding function
{
int entry = 0;
switch (choice)
{
case 1:getIntegers(score, size); //read integers from user
break;
  
case 2:getScores_file(score, size); //reading from file
break;

case 3:printScores(score, size); //printing the scores
break;

case 4:printHighest(score, size); //printing highest score
break;

case 5:printLowest(score, size); //printing lowest score
break;

case 6:printAverage(score, size); //printing average
break;

case 7:printEntry(score, size, entry); //printing entered entry number score
break;
}
return choice;
}

//function for getting scores from user
void getIntegers(int score[], int size)
{
int count = 1;
cout << "\n";
for(int i = 0; i < size ; i++) // loop allows us to put in an individual score with each index of the array
{
cout << "Score #" << count << ": ";
cin >> score[i];
count++;
}
}

//function for reading scores from txt file
void getScores_file(int score[], int size)
{
  int i = 0; 
  int num;
  string filename;
  
cout << "\nEnter filename: ";
  cin >> filename;

  while (filename != "scores.txt") // file input validation
  {
    cin.ignore();
    cin.clear();
    cout << "Input the correct filename (scores.txt): ";
    cin >> filename;
    }
  
  ifstream File;
  File.open("scores.txt"); 
  while(!File.eof()) // loop for extracting the elements of the file into the elements of the array
  {
    File >> score[i]; // with each index, take from the file and put into element of array
    i++;
    }
    File.close();
  cout << "File has successfully opened and 10 scores have been read and stored.\nPlease select the print all scores menu option to view the scores" << endl;
  }

//function to print scores
void printScores(int score[], int size)
{
cout << "\nPrinting the scores...\n";
int count = 1; // count here is just for the cout statements to keep track of which score is being output

for(int i = 0; i < size; i++)
{
cout << "score #" << count << ":       " << score[i] << endl; // with each index of the array, print a new numbered line and the element corresponding to that line
  count++;
}
cout << endl;
}

//function to get highest score
void printHighest(int score[], int size)
{
int high = 0;

cout << "\nThe highest score is ";

for(int i = 0; i < size; i++)
{
if(score[i] > high) //logic comparing each indexed element of the array with the current "highest" variable, and updating the variable with the highest number
high = score[i]; 
}
cout << high << endl;
}

//function to get lowest score
void printLowest(int score[], int size)
{
int low = score[0];

for(int i = 1; i < size; i++)
{
if(score[i] < low) // same logic as highest, but opposite if that makes sense
low = score[i];
  }
cout << "\nThe lowest scores is " << low << endl;
  }

//function to print average
void printAverage(int score[], int size)
{
int sum = 0;
double avg = 0;
for (int i = 0; i < size; i++)
{
   sum += score[i]; // getting the sum of the elements of the array by keeping a running total with each index
 }
avg = ((float)sum) / size;
cout << "\nThe average score is: " << avg << endl;
}

//function to print entry score
void printEntry(int score[], int size, int entry)
{
cout << "\nPlease enter entry or row # of score you want:";
cin >> entry;
  
int actual = entry - 1; // for example, if the user inputs entry 7, then without this part the program would take from entry 8
int entryscore = score[actual];
int count = 0;

cout << "Entry #" << entry << " score:" << entryscore << endl;

for(int i = 0; i < size; i++)
{
if(entryscore < score[i]) // comparing scores to see if there are any higher than the desired score and keeping count of them to output later
count++;
}
cout << "Score statistics:" << count << " higher" << endl;
}

//function to display all options with cout statements
void displayMenu()
{
  cout << "\n---------------------------------------------------\n1-D ARRAY PROCESSING MENU OPTIONS\n---------------------------------------------------\n";
cout << "1. Read in 10 scores from user.\n";
cout << "2. Read in 10 scores from the file, scores.txt.\n";
cout << "3. Print all scores.\n";
cout << "4. Print the highest score.\n";
cout << "5. Print the lowest score.\n";
cout << "6. Print the average score.\n";
cout << "7. Print one score (give its entry number).\n";
cout << "8. Quit program.\n";
cout << "\nEnter your choice:";
}