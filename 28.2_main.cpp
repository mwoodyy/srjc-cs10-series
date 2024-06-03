#include <iostream>
#include <string>
#include "ArraySet.h"
#include "ArraySet.cpp"
using namespace std;
using namespace cs_set;

void displaySet(ArraySet<string>& set);
void setTester(ArraySet<string>& set);

int main()
{
    ArraySet<int> set1;
    ArraySet<int> set2;
    ArraySet<int> set3;
    int numArr1[] = {1,2,3,4,5};
    int numArr2[] = {1,7,3,10,12};
    int numArr3[] = {1,2,3,4,5};

    try {
        cout << "Insert 6 items into sets 2 and three: " << endl;
        for (int i = 0; i < 6; i++) {
            set2.insert(numArr2[i]);
            set3.insert(numArr3[i]);
        }
    } catch(ArraySet<string>::DuplicateItemError e) {
        cout << "tried to insert a duplicate value !" << endl;
    }

    try {
        set1 = set2.setUnion(set3);
        cout << "union successful" << endl;
    } catch (ArraySet<int>::CapacityExceededError e) {
    cout << "Operation exceeds the capacity of sets and therefore failed." << endl;
    }
}






void displaySet(ArraySet<string>& set) {
   cout << "The set contains " << set.size()
        << " items:" << endl;
   std::vector<string> setItems = set.toVector();

   int numEntries = setItems.size();
   for (int i = 0; i < numEntries; i++) {
      cout << setItems[i] << " ";
   }
   cout << endl << endl;
}





void setTester(ArraySet<string>& set)
{
    cout << "empty: returns " << set.empty()
         << "; should be 1 (true)" << endl;
    displaySet(set);

    std::string items[] = {"one", "two", "three", "four", "five", "one"};
    try {
        cout << "Insert 6 items into the set: " << endl;
        for (int i = 0; i < 6; i++) {
            set.insert(items[i]);
        }
    } catch(ArraySet<string>::DuplicateItemError e) {
        cout << "tried to insert a duplicate value !" << endl;
    }

    displaySet(set);

    cout << "empty: returns " << set.empty()
         << "; should be 0 (false)" << endl;

    cout << "size: returns " << set.size()
         << "; should be 6" << endl;

    try {
        cout << "Try to insert another entry: insert(\"extra\")... ";
        set.insert("extra");
        cout << "should cause exception but didn't" << endl;
    } catch (ArraySet<string>::CapacityExceededError e) {
        cout << "should cause exception and did!" << endl;
    } catch (ArraySet<string>::DuplicateItemError e) {
        cout << "caused duplicate value error!" << endl;
    }

    cout << "contains(\"three\"): returns " << set.contains("three")
         << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << set.contains("ten")
         << "; should be 0 (false)" << endl;
    cout << "count(\"one\"): returns "
         << set.count("one") << " should be 2" << endl;

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    } catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    cout << "count(\"one\"): returns "
         << set.count("one") << " should be 1" << endl;

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    } catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "should cause exception but didn't" << endl;
    } catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;

    displaySet(set);

    cout << "After clearing the set, ";
    set.clear();
    cout << "empty: returns " << set.empty()
         << "; should be 1 (true)" << endl;
}
