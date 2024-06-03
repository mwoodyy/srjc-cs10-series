/*
Matthew Woody
Dave Harden
2/5/24
Program to use a linked list to print out items on a shopping list
  */
#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main () {
   list<ListItem> shoppingList;

   string item;

  getline(cin, item);
  while (item != "-1"){ //while input is not -1 keep adding elements to list
    shoppingList.push_back(item);
    getline(cin, item);
  }

  //while the list has multiple elements, print the node at the current element
  for (auto i = shoppingList.begin(); i != shoppingList.end(); i++){
    i->PrintNodeData();
  }

  return 0;
}
