// A program in which the user inputs answers and a small story is created using those answers
// Programmer Name: Matthew Woody
// Assignment 2.5

#include <iostream>
#include <string>
using namespace std;
int main() 
{
// create int/strings for input to be stored
  string NAME;
  int AGE;
  string CITY;
  string COLLEGE;
  string PROFESSION;
  string ANIMAL;
  string PETNAME;

  // getting string/int inputs
  cout << "Name: ";
  cin >> NAME;
  cout << "\nAge: ";
  cin >> AGE;
  cout << "\nCity: ";
  cin >> CITY;
  cout << "\nCollege: ";
  cin >> COLLEGE;
  cout << "\nProfession: ";
  cin >> PROFESSION;
  cout << "\nAnimal: ";
  cin >> ANIMAL;
  cout << "\nPet Name: ";
  cin >> PETNAME;

  // displaying paragraph with string/int inside of it
  cout << "There once was a person named " << NAME;
  cout << ", who lived in " << CITY;
  cout << ". At the age of " << AGE;
  cout << ", " << NAME;
  cout << " went to college at " << COLLEGE;
  cout << ". " << NAME;
  cout << " graduated and went to work as a " << PROFESSION;
  cout << ". Then, " << NAME;
  cout << " adopted a(n) " << ANIMAL;
  cout << " named " << PETNAME;
  cout << ". They both lived happily ever after!";

return 0;
}