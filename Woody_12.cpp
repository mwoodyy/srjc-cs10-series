#include <iostream>
using namespace std;

int main ()
{
  // including the $, but not as an identifier
  char money;
  money = '$';
  
  // adding variables
double item1; //double is the same as int but works with decimals
double item2;
double item3;
double item4;
double item5;
  
  // declaring the values of the variables
item1 = 12.95;
item2 = 24.95;
item3 = 6.95;
item4 = 14.95;
item5 = 3.95;
  
  // displaying the values of the variables
cout << "Item 1: " << money << item1 << endl;
cout << "Item 2: " << money << item2 << endl;
cout << "Item 3: " << money << item3 << endl;
cout << "Item 4: " << money << item4 << endl;
cout << "Item 5: " << money << item5 << endl;
  
// getting the subtotal
double subtotal = item1 + item2 + item3 + item4 + item5; 
cout << "Subtotal: " << money << subtotal << endl;
  
// getting the sales tax
double sales_tax = subtotal * 0.06;
cout << "Sales Tax: " << money << sales_tax << endl;
  
// getting the total
double total = subtotal + sales_tax;
cout << "Total: " << money << total << endl;
}