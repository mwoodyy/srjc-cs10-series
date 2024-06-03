// A program for finding the mean and standard deviation of 10 test scores
// Programmer Name: Matthew Woody
// Assignment: Algorithm Workbench 2

#include <iostream>
#include <cmath> // had to include <cmath> because of sqrt function, was able to do everything else without cmath
using namespace std;

int main() 
{
  // setting up variables for scores to be stored in
int score1;
int score2;
int score3;
int score4;
int score5;
int score6;
int score7;
int score8;
int score9;
int score10;
  
  // prompting for scores and storing them in the previously created variables
cout << "Input the first score: ";
cin >> score1;
cout << "Input the second score: ";
cin >> score2;
cout << "Input the third score: ";
cin >> score3;
cout << "Input the fourth score: ";
cin >> score4;
cout << "Input the fifth score: ";
cin >> score5;
cout << "Input the sixth score: ";
cin >> score6;
cout << "Input the seventh score: ";
cin >> score7;
cout << "Input the eighth score: ";
cin >> score8;
cout << "Input the ninth score: ";
cin >> score9;
cout << "Input the tenth score: ";
cin >> score10;

// finding the mean score
int score_combined = score1 + score2 + score3 + score4 + score5 + score6 + score7 + score8 + score9 + score10;
int mean = score_combined / 10;
cout << "The mean score was " << mean << endl;

// finding the standard deviation (population)
  // first creating variables for deviations of each value
int dev1 = score1 - mean;
int dev2 = score2 - mean;
int dev3 = score3 - mean;
int dev4 = score4 - mean;
int dev5 = score5 - mean;
int dev6 = score6 - mean;
int dev7 = score7 - mean;
int dev8 = score8 - mean;
int dev9 = score9 - mean;
int dev10 = score10 - mean;

  // then square each of the individual deviations
int sqdev1 = dev1 * dev1;
int sqdev2 = dev2 * dev2;
int sqdev3 = dev3 * dev3;
int sqdev4 = dev4 * dev4;
int sqdev5 = dev5 * dev5;
int sqdev6 = dev6 * dev6;
int sqdev7 = dev7 * dev7;
int sqdev8 = dev8 * dev8;
int sqdev9 = dev9 * dev9;
int sqdev10 = dev10 * dev10;

  // find the sum of squares of the deviations
int sum_sq = sqdev1 + sqdev2 + sqdev3 + sqdev4 + sqdev5 + sqdev6 + sqdev7 + sqdev8 + sqdev9 + sqdev10;

  // finding variance (divide sum of squares by 10)
int variance = sum_sq / 10;

  // taking sqaure root of variance and getting standard deviation
int std_dev = sqrt(variance);

cout << "The standard deviation was " << std_dev << endl;

return 0;
  }