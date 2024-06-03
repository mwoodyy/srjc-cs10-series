// A program utilizing functions to improve mathematical skills in algebra, geometry and statistics
// Project 2
// Programmer Name: Matthew Woody
#include <iostream>
#include <cstdlib>       //for srand
#include <ctime>         //to seed the random number
#include <cmath>         //for geometric expressions
#include <iomanip>       //formatted display
using namespace std;

//program user interface in main
void programInfo();
void mathSkillBuilderMenu (/*out*/ int& choice);
void processProbSets (/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect);
void printReport (/*in*/ int choice,/*in*/ int numProbSets,/*in*/ int numCorrect);

//overloaded functions accessed by Math Builder Skill set modules for random number generation
void generateOperands (/*out*/ double& num1);
void generateOperands (/*out*/ double& num1, /*out*/ double& num2);
void generateOperands (/*out*/ double& num1, /*out*/double& num2,/*out*/double& num3);

//various modules to process Math Builder Skill sets
void arithmeticProbSet (/*in*/ int numProbSets, /*out*/ int& numCorrect);
void geometryProbSet (/*in*/ int numProbSets, /*out*/ int& numCorrect);
void statisticsProbSet (/*in*/ int numProbSets, /*out */ int& numCorrect);//for extra credit only
int getNumSets ();

//remaining function prototypes and related descriptions
void checkAnswer(/*in*/ double userAnswer, /*in*/ double correctAnswer, /*out*/ int& numCorrect);

//global constants
const int PROBSPERSET = 4;           //Number of Problems in each set
const int MIN_NUM = 1, MAX_NUM = 10; //preset range for random numbers
const double PI = 3.141593;          // use for geometry problems

int main()
{
 cout << showpoint << fixed <<setprecision(2); // formatted number display
    srand(time(0));                               // seed the random number generator

    int choice = 0, numProbSets = 0, numCorrect = 0;

    programInfo();
    mathSkillBuilderMenu (choice);

    while (choice!=4)
    {
        processProbSets (choice,numProbSets,numCorrect);
        printReport (choice,numProbSets,numCorrect);
        mathSkillBuilderMenu (choice);
     }

    cout << "\n\nNow exiting MATH SKILL BUILDER program ...." << endl;

  return 0;
  }
void arithmeticProbSet (/*in*/ int numProbSets, /*out*/ int& numCorrect)
{
  double num1 = 0, num2 = 0, userAnswer = 0, correctAnswer = 0;
  numCorrect = 0;
   //algorithm: display four arithmetic problems using calls to generateOperands
   //update algorithm to use numProbSets incoming parameter value to allow user 1-5 attempts on the current skill set.
  cout << "\nArithmetic skill sets" << endl;
  // a for loop will probably work the best here
  for (int doSets = 1 /*doSets is the number of times that the set will be performed*/; doSets <= numProbSets; doSets++) // what the loop is doing is first creating the doSets variable, and incrementing with each iteration of the loop until it reaches the desired number of sets done, in numProbSets
    // doSets is also useful for displaying which set # the user is currently on
{
  cout << "\nArithmetic Problem Set #" << doSets << "\n---------------------\n";
  generateOperands (num1, num2);
  cout << num1 << " + " << num2 << " = ";
  correctAnswer = num1 + num2;
  cin >> userAnswer;

  checkAnswer(userAnswer, correctAnswer, numCorrect);

  generateOperands (num1, num2);
  cout << num1 << " - " << num2 << " = ";
  correctAnswer = num1 - num2;
  cin >> userAnswer;

  checkAnswer(userAnswer, correctAnswer, numCorrect);

  generateOperands (num1, num2);
  cout << num1 << " * " << num2 << " = ";
  correctAnswer = num1 * num2;
  cin >> userAnswer;

  checkAnswer(userAnswer, correctAnswer, numCorrect);

generateOperands (num1, num2);
  cout << "Type a response rounded to two decimal places below..." << endl;
  cout << num1 << " / " << num2 << " = ";
  correctAnswer = num1 / num2;
  cin >> userAnswer;

  checkAnswer(userAnswer, correctAnswer, numCorrect);
   //process the binary operations-store calculated correctAnswer 
   //get userResponse-compare answers and display appropriate message
   //increment numCorrect if correct user answer
  }
  }
int getNumSets ()
{
     int numProbSets  = 1; //default setting

    //algorithm: get user input for numProbSets and include appropriate input validation
  cout << "How many times you wish to attempt this current set (enter 1-5) : ";
  cin >> numProbSets;
  while (numProbSets < 1 || numProbSets > 5) // input validation for if the number of sets desired is in the acceptable range
    {
      cout << "\nOOPS, Invalid input?\nHow many times you wish to attempt this current set (enter 1-5) : ";
      cin.clear();
      cin >> numProbSets;
    }
  
  return numProbSets; // returns an integer value for the function
}
void generateOperands (/*out*/ double& num1)
{
   //algorithm: generate one random numbers using the reference parameter.
  num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}
void generateOperands (/*out*/ double& num1, /*out*/ double& num2)
{
   //algorithm: generate two random numbers using the reference parameter.
  num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM; 
  
}
void generateOperands (/*out*/ double& num1, /*out*/ double& num2, /*out*/ double& num3)
{
   //algorithm: generate three random numbers using the reference parameter.
  num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num3 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}
void geometryProbSet (/*in*/ int numProbSets, /*out*/ int& numCorrect)
{
  double num1 = 0, num2 = 0, num3 = 0, userAnswer = 0, correctAnswer = 0;
   numCorrect = 0;

  cout << "\nGeometry skill sets" << endl;
   //process four geometric operations-store calculated correctAnswer 
  for(int doSets = 1; doSets <= numProbSets; doSets++) // same logic as arithmetic sets
    {
      generateOperands (num1, num2);
      cout << "Geometry Problem Set #" << doSets << "\n---------------------\nCalculate the area of a triangle using the given base and height: Base = " << num1 << ", Height = " << num2 << endl;
      correctAnswer = (num1 * num2) / 2;
    cout << "Area of Triangle is: ";
      cin >> userAnswer;

      checkAnswer(userAnswer, correctAnswer, numCorrect);

    generateOperands (num1, num2, num3);
  cout << "Permeter of a Triangle with three sides: side1 = " << num1 << ", side2 = " << num2 << ", side3 = " << num3 << endl;
      correctAnswer = num1 + num2 + num3;
  cout << "Perimeter of a Triangle is: ";
      cin >> userAnswer;

    checkAnswer(userAnswer, correctAnswer, numCorrect);

      generateOperands(num1, num2);
    cout << "Calculate the perimeter of a rectangle: Length = " << num1 << " and Width = " << num2 << endl;
      correctAnswer = 2 * (num1 + num2);
      cout << "Perimeter of Rectangle is: ";
      cin >> userAnswer;

    checkAnswer(userAnswer, correctAnswer, numCorrect);

  generateOperands(num1);
  cout << "Calculate the area of a circle given radius: Radius = " << num1 << " and PI (π) is 3.141593\nType a response rounded to two decimal places below..." << endl;
  correctAnswer = PI * (pow(num1, 2));
  cin >> userAnswer;
  
 checkAnswer(userAnswer, correctAnswer, numCorrect);
    }
   //get userResponse-compare answers and display appropriate message
   //increment numCorrect if correct user 
}
void statisticsProbSet (/*in*/ int numProbSets,/*out*/ int& numCorrect) // I wasn't sure of any statistical problems that could be done beyond the basics of mean and median with 3 variables between 1 and 10, so the 3rd and 4th ones are more of "applied aritmetic" problems
{
  double num1 = 0, num2 = 0, num3 = 0, userAnswer = 0, correctAnswer = 0;
   numCorrect = 0;
  
  cout << "\nStatistics skill sets" << endl;
for(int doSets = 1; doSets <= numProbSets; doSets++) // same as previous loops, just different problems
  {
    generateOperands (num1, num2, num3);
    cout << "\nBusiness Statistics Problem Set #" << doSets << "\n-------------------------\nFind the mean(average) of: " << num1 << ", " << num2 << ", " << num3 << endl;
    correctAnswer = (num1 + num2 + num3) / 3;
    cout << "The mean is: ";
      cin >> userAnswer;
    
   checkAnswer(userAnswer, correctAnswer, numCorrect);

    generateOperands(num1, num2, num3);
cout << "\nWhat is the median of: " << num1 << ", " << num2 << ", " << num3 << endl;
    // logic to determine median of 3 numbers
    if (num2 > num1 && num1 > num3 || num3 > num1 && num1 > num2)
        correctAnswer = num1;
    else if (num1 > num2 && num2 > num3 || num3 > num2 && num2 > num1)
        correctAnswer = num2;
    else if (num1 > num3 && num3 > num2 || num2 > num3 && num3 > num1)
        correctAnswer = num3;
    
    cout << "The median is: ";
      cin >> userAnswer;
    
   checkAnswer(userAnswer, correctAnswer, numCorrect);

    generateOperands(num1);
    cout << "\nFind the time (in hours) it will take for someone who makes $" << num1 << " an hour to make $100" << endl;
    correctAnswer = 100 / num1;
    cout << "How many hours will it take? ";
    cin >> userAnswer;
    
   checkAnswer(userAnswer, correctAnswer, numCorrect);

    generateOperands(num1, num2, num3);
    cout << "\nAssume the given values are the dollar values that an individual child has: " << num1 << ", " << num2 << ", " << num3 << ". And they would like to pool their money to buy something that costs $50, how much do they need to ask each of their parents for in order to get what they want? Assume that the parents will split the necessary amount evenly." << endl;
    correctAnswer = (50 - (num1 + num2 + num3)) / 3;
    cout << "They need to ask for $";
    cin >> userAnswer;
    
   checkAnswer(userAnswer, correctAnswer, numCorrect);
  }
  
}
void programInfo()
{
    cout << "                       MATH IS FUN                                            " << endl;
    cout << "The Math Skill Builder program will assess basic mathematics skills.          " << endl;
    cout << "Each Math skill builder set generates four problems using randomly            " << endl;
    cout << "generated numbers in the range of 1 to 10, stored as double values.\n         " << endl;
    cout << "The randomly generated numbers are to be used as operands or arguments        " << endl;
    cout << "for the various arithmetic, geometry or other problem types to be generated   " << endl;
    cout << "in each Math skill builder set. User response to a problem is compared to the " << endl;
    cout << "correct answer and an appropriate message is displayed.\n                     " << endl;

    cout << "A menu driven interface provides the user an opportunity to select a specific " << endl;
    cout << "Math Builder Skill set to try and the program interface design algorithms are " << endl;
    cout << "built with expandability in mind to allow for (1) additional problem sets or  " << endl;
    cout << "modules to be added or (2) additional different problem types in each set or  " << endl;
    cout << "(3) a larger random number range.\n                                           " << endl;

    cout << "Program Assertions: When comparing two double values with precision (for eg., " << endl;
    cout << "in comparing user response to the correct answer for a double quotient result " << endl;
    cout << "or mixed type calculation the user is reminded to provide a response rounded  " << endl;
    cout << "to two decimal places, as a precision criteria of less than .01 will be used  " << endl;
    cout << "to determine equality. Expect a few floating point representational errors.   " << endl; 
}
void mathSkillBuilderMenu (/*out*/ int& choice)
{
     cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++ " << endl;
     cout << setw(50) << "- MATH SKILL BUILDER SETS - Select one -   " << endl;
     cout << setw(50) << "* 1. BASIC ARITHMETIC *                    " << endl;
     cout << setw(9) << "π" << " 2. BASIC GEOMETRY "<< "π" <<endl;
     cout << setw(50) << "% 3. BASIC STATISTICS %                    " << endl;
     cout << setw(50) << "\\ 4. EXIT MATH IS FUN \\                  " << endl;
     cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++ " << endl;
     
     cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
     cin >> choice;

     while(choice < 1 || choice > 4 || !cin){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "OOPS, Invalid choice? " << endl;
        cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
        cin >> choice;
     }
}
void processProbSets (/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect)
{
    //algorithm: move the following calls from main completed in phase 4
numProbSets = getNumSets();    //Number of attempts on a Math Skill Builder set     
  // Next add a switch statement and set choice as the argument. Now you can move each
     // set header and calls to arithmeticProbSet, geometryProbSet and statisticsProbSet
  // from main and into respective case label as they relate to a menu choice
switch (choice)
  {
    case 1:
    arithmeticProbSet (numProbSets, numCorrect);
    break;
    case 2:
    geometryProbSet (numProbSets, numCorrect);
    break;
    case 3:
    statisticsProbSet (numProbSets, numCorrect);
    break;
  }
}
void printReport (/*in*/ int choice,/*in*/ int numProbSets,/*in*/ int numCorrect)
{
   //algorithm: Based on current value in choice use selection control structures to
   //generate appropriate assessment report for each skill set
  if (choice == 1) // arithmetic set
  {
    cout << "\n=================================================================" << endl;
 cout << "Basic Arithmetic Skill Set: You got " << numCorrect << " correct out of "
 << PROBSPERSET * numProbSets << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "%\n" << "=================================================================" << endl;
  }
  if (choice == 2) // geometry set
  {
 cout << "\n=================================================================" << endl;
    cout << "Basic Geometry Skill Set: You got " << numCorrect << " correct out of "
 << PROBSPERSET * numProbSets << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "%\n" << "=================================================================" << endl;
  }
  if (choice == 3) // stats set
  {
    cout << "\n=================================================================" << endl;
cout << "Business Statistics Skill Set: You got " << numCorrect << " correct out of "
 << PROBSPERSET * numProbSets << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "%\n" << "=================================================================" << endl;
  }
}
void checkAnswer(/*in*/ double userAnswer, /*in*/ double correctAnswer, /*out*/ int& numCorrect)
{
  if (fabs(correctAnswer - userAnswer) < .01)
{
  cout << "Correct\n-------------------------\n";
  numCorrect++;
}
else
  cout << "Incorrect. Correct answer displayed with precision of .01 = " << correctAnswer  << "\n---------------------" << endl;
}