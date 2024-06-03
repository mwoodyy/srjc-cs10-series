// A program for rotating a letter forward or backward 13 places in the alphabet
// Programmer Name: Matthew Woody
// Assignment 3.1

#include <iostream>
using namespace std;

int main() {
  // input for character
  char letter;
  cout << "Enter a letter (A - Z): ";
  cin >> letter;
  
  // switch statement
  switch (letter)
    {
      // cases for each letter
    case 'A': cout << "ROT13 Caesar Cipher for A - > N" << endl;
    break;
    case 'B': cout << "ROT13 Caesar Cipher for B - > O" << endl;
    break;
    case 'C': cout << "ROT13 Caesar Cipher for C - > P" << endl;
    break;
    case 'D': cout << "ROT13 Caesar Cipher for D - > Q" << endl;
    break;
    case 'E': cout << "ROT13 Caesar Cipher for E - > R" << endl;
    break;
    case 'F': cout << "ROT13 Caesar Cipher for F - > S" << endl;
    break;
    case 'G': cout << "ROT13 Caesar Cipher for G - > T" << endl;
    break;
    case 'H': cout << "ROT13 Caesar Cipher for H - > U" << endl;
    break;
    case 'I': cout << "ROT13 Caesar Cipher for I - > V" << endl;
    break;
    case 'J': cout << "ROT13 Caesar Cipher for J - > W" << endl;
    break;
    case 'K': cout << "ROT13 Caesar Cipher for K - > X" << endl;
    break;
    case 'L': cout << "ROT13 Caesar Cipher for L - > Y" << endl;
    break;
    case 'M': cout << "ROT13 Caesar Cipher for M - > Z" << endl;
    break;
    case 'N': cout << "ROT13 Caesar Cipher for N - > A" << endl;
    break;
    case 'O': cout << "ROT13 Caesar Cipher for O - > B" << endl;
    break;
    case 'P': cout << "ROT13 Caesar Cipher for P - > C" << endl;
    break;
    case 'Q': cout << "ROT13 Caesar Cipher for Q - > D" << endl;
    break;
    case 'R': cout << "ROT13 Caesar Cipher for R - > E" << endl;
    break;
    case 'S': cout << "ROT13 Caesar Cipher for S - > F" << endl;
    break;
    case 'T': cout << "ROT13 Caesar Cipher for T - > G" << endl;
    break;
    case 'U': cout << "ROT13 Caesar Cipher for U - > H" << endl;
    break;
    case 'V': cout << "ROT13 Caesar Cipher for V - > I" << endl;
    break;
    case 'W': cout << "ROT13 Caesar Cipher for W - > J" << endl;
    break;
    case 'X': cout << "ROT13 Caesar Cipher for X - > K" << endl;
    break;
    case 'Y': cout << "ROT13 Caesar Cipher for Y - > L" << endl;
    break;
    case 'Z': cout << "ROT13 Caesar Cipher for Z - > M" << endl;
    break;

    // input validation
      default: cout << letter << " not found in the ROT13 coding scheme." << endl;
      }

    return 0;
}