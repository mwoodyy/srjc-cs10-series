// a program for displaying ratings of 6 movies from 4 reviewers and options to find the highest, lowest, and average reviews as well as input new reviews
// Project 4
// Programmer Name: Matthew Woody
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// global constants
const int NUM_ROWS = 4;
const int NUM_COLS = 6;

// function prototypes
void displayRatings(const int[][NUM_COLS], const int[], int);
void displayMenu();
void showAverageRatings(const int[][NUM_COLS],  const int[], int);
void showReviewersHighestRating(const int[][NUM_COLS], const int[], int);
void showReviewersLowestRating(const int[][NUM_COLS], const int[], int);
void getNewRatings(int[][NUM_COLS], const int[],  int);

int main() 
{
  // Variable declarations
  // 2D array to store initial ratings
  int movieReviews[NUM_ROWS][NUM_COLS] = 
{
{3, 1, 5, 2, 1, 5},
{4, 2, 1, 4, 2, 4},
{3, 1, 2, 4, 4, 1},
{5, 1, 4, 2, 4, 2}
};
  // 1D array to store movie numbers
  int movieNum[NUM_COLS] = {100, 101, 102, 103, 104, 105};
  int choice; 

do 
{
displayMenu();
  cin >> choice;
  while (!cin || choice < 1 || choice > 6)
    {
    cin.clear();
    cin.ignore(200,'\n');
    cout << "Please enter a choice from 1 to 6." << endl;
    cin >> choice;
    }
  cout << "\n";
  
switch (choice) // switch statement for which option is chosen
{
case 1:
displayRatings(movieReviews, movieNum, NUM_ROWS);
break;
  
case 2:
showAverageRatings(movieReviews, movieNum, NUM_ROWS);
break;

case 3:
showReviewersHighestRating(movieReviews, movieNum, NUM_ROWS);
break;
  
case 4:showReviewersLowestRating(movieReviews, movieNum, NUM_ROWS);
break;
  
case 5:
getNewRatings(movieReviews, movieNum, NUM_ROWS);
break;
  
case 6:
cout << "Array processing test now concluded. Exiting program ....." << endl;
return 0;
break;
  
default:
cout << "Please enter a choice from 1 to 6." << endl;
  }
} while (choice != 6); // do while loop for choice
  return 0;
}

// function definitions
void displayRatings(const int ratings[][NUM_COLS], const int movie[], int rows) // displaying ratings
{
  cout << "\n********************* MOVIE RATINGS ****************" << endl;
cout << "REVIEWER|  MV#100 MV#101 MV#102 MV#103 MV#104 MV#105" << endl;
cout << "****************************************************" << endl;

for(int i = 0; i < NUM_ROWS; i++) // outer for loop to show reviewer number
{
cout << "#" << (i + 1) << "      ";

for(int j = 0; j < NUM_COLS; j++) // inner loop showing ratings for each movie
{
cout << ratings[i][j] << "   ";
}
cout << endl;
} // loop repeats until 4 reviewers
cout << endl;
}

void displayMenu() // function with cout statements as not to clutter up main
{
  cout << "---------------------------------------------------" << endl;
    cout << "2-D ARRAY PROCESSING MENU OPTIONS" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1. Display current movie ratings" << endl;
    cout << "2. Show the average rating for each movie." << endl;
    cout << "3. Show a reviewers highest rated movie. (enter reviewer# 1-4)" << endl;
    cout << "4. Show a movies lowest rating. (enter movie# 100-105)" << endl;
    cout << "5. Enter new ratings (1-5) for movie# 100-105 for four reviewers" << endl;
    cout << "6. Quit program" << endl;
    cout << endl << "Enter your choice:";
}

void showAverageRatings(const int ratings[][NUM_COLS], const int movie[], int rows) // function for average rating
{
  displayRatings(ratings, movie, rows);
  
  cout << "Average rating for each movie:" << endl;

  for (int j = 0; j < NUM_COLS; j++) 
  {
    int sum = 0; // set sum to 0 for each column
    for (int i = 0; i < rows; i++)
    sum = sum + ratings[i][j]; // keeping a running total by adding the sum to whatever the rating is and assigning that to be the new sum
    cout << "Movie #" << movie[j] << setw(6) << float(sum) / rows << endl;
  }
  cout << endl;
}

void showReviewersHighestRating(const int ratings[][NUM_COLS], const int movie[], int rows) // function for highest rating
{
  displayRatings(ratings, movie, rows); 
  int j;                                
  int reviewer = 0; // variable for user input for which reviewer they want to see      
  int count = 0;                        

  cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest:";
  cin >> reviewer;

  while (!cin || reviewer < 1 || reviewer > 4) // condition to make sure input is an integer in acceptable range
  {
    cin.clear();
    cin.ignore(200,'\n');
    cout << "That is an invalid reviewer number." << endl;
    cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest:";
    cin >> reviewer;
  }

  cout << "Reviewer #" << reviewer << " rated Movie #";
  int highest = ratings[reviewer - 1]/* reviewer -1 is to avoid "off by one" errors when working with arrays*/[0]; // assigning the variable for highest rating to the first entry so it can be redefined if need be later

  for (j = 0; j < NUM_COLS; j++) 
  {
    if (ratings[reviewer - 1][j] > highest)
      highest = ratings[reviewer - 1][j]; // logic to see if most recently checked rating is higher than the current highest rating, and assigning it to the variable if so
  }

  // loop counting the number of times the highest appears (there may be 2 ratings that are equally high)
  count = 0;
  for (j = 0; j < NUM_COLS; j++) 
  {
    if (ratings[reviewer - 1][j] == highest)
      count++; // if the current rating is equal to the highest, increase the count of the highest ones
  }

// loop keeping track of highest count
  for (j = 0; j < NUM_COLS; j++) 
  {
    if (ratings[reviewer - 1][j] == highest) // if the rating is the highest, print the movie and take 1 away from the count
    {
      cout << movie[j];
      count--;
      
      if (count == 1)
        cout << " and "; // only applicable if the count is one for proper formatting, for example, so and so rated movie#100 and 105 as the highest.
        
      else if (count > 1)
        cout << ", "; // if count is more than one this logic will list off the movies with commas
        
      else if (count == 0) // if there is only one highest, then just one movie is printed
        cout << " as the highest." << endl << endl;
    }
  }
}

void showReviewersLowestRating(const int ratings[][NUM_COLS], const int movie[], int rows) // function to show lowest ratings
{
  displayRatings(ratings, movie, rows);
  int movieNum; // input variable
  int j; // loop variable
  
  cout << "Enter a movie number (100-105), to find the lowest rating:";
  cin >> movieNum;

  // input validation loop for integer in correct range
  while (!cin || movieNum < 100 || movieNum > 105) 
  {
    cin.clear();
    cin.ignore(200,'\n');
    cout << "That is an invalid movie number." << endl;
    cout << "Enter a movie number (100-105), to find the lowest rating:";
    cin >> movieNum;
  }

  for (j = 0; j < NUM_COLS; j++) // incrementing along each column first
    if (movieNum == movie[j])
    break;
  
  cout << "Movie #" << movieNum << " lowest rating is "; // cout statement for output, continued on line 221

  int lowest = ratings[0][j]; // initialized the lowest rating to the first entry so that any new entries can be tested and possibly stored if they are lower

  for (int i = 0; i < rows; i++) 
  {
    // logic for finding lowest value, if the new rating that were just checked are lower than the current lowest rating, it becomes the new lowest
    if (ratings[i][j] < lowest)
      lowest = ratings[i][j]; 
  }
  cout << lowest << "\n" << endl; // continued full cout statement with lowest 
}

void getNewRatings(int ratings[][NUM_COLS], const int movie[], int rows) // function for user input of new ratings for each reviewer
{
  cout << "********DATA ENTRY FOR NEW MOVIE RATINGS ***********" << endl;

  // loop cycling through reviewers first
  for (int i = 0; i < rows; i++) 
  {
    cout << "****************************************************" << endl;
    cout << "REVIEWER# " << i + 1 << endl; // it is i + 1 instead of just i (or i++) because there is a nested loop inside of this one, and that loop would be skewed if it was just i, so a "one time" change in the variable is better
    cout << "****************************************************" << endl;
    
    // nested loop going along each column/movie
    for (int j = 0; j < NUM_COLS; j++) 
    {
      cout << "Enter rating (1-5) for movie #" << movie[j] << ": ";
      cin >> ratings[i][j];
      
      // validate user input range
      while (ratings[i][j] < 1 || ratings[i][j] > 5) 
      {
        cin.clear();
    cin.ignore(200,'\n');
        cout << "Invalid rating.  It must be from 1-5." << endl;
        cout << "Enter rating (1-5) for movie #" << movie[j] << ": ";
        cin >> ratings[i][j];
      }
    }
  }
  cout << endl;
}
