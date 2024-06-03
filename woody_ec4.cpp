#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  
  const int MIN = 1;
  const int MAX = 20;
  int guess = 0;
  int count = 0;
  int num;
  
  unsigned seed = time(0);
  srand(seed);
  
  num = (rand() % (MAX - MIN + 1)) + MIN;

  cout << "random number between 1 and 20 generated... input your guess: ";
  cin >> guess;

  cout << num << endl;

  while (guess <= 20 && guess >= 1)
    {
     if (guess <= 20 && guess > num)
      {
        cout << "Too high, try again: ";
        count++;
        cin >> guess;
        }
    else if (guess >= 1 && guess < num)
      {
        cout << "Too low, try again: ";
        count++;
        cin >> guess;
      }
    else if (guess == num)
      {
        count++;
        cout << "Congradulations, you figured out my number. (guesses: " << count << ")" << endl;
      return 0;
      }
      }
  }