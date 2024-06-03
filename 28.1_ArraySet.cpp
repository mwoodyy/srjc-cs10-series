/*
Matthew Woody
Dave Harden
CS10C Project 28.1
2/12/24
Program for a Set class with dynamic arrays disallowing duplicate elements
  */

#include "ArraySet.h"
namespace cs_set {

    template<class ItemType>
    void ArraySet<ItemType>::insert(const ItemType& newEntry) {
        if (numItems >= capacity) {
            throw CapacityExceededError();
        } else if(this->count(newEntry) >= 1) { // if the entry already exists then throw the error
            throw DuplicateItemError();
        } else {
            items[numItems] = newEntry;
            numItems++;
        }  
    }  


    template<class ItemType> // destructor
    ArraySet<ItemType>::~ArraySet() {
        delete [] items;
    }

    template<class ItemType>
    ArraySet<ItemType>::ArraySet() {
        numItems = 0;
        capacity = DEFAULT_CAPACITY;
        items = new ItemType[capacity];
    }

    template<class ItemType>
    ArraySet<ItemType>::ArraySet(int size) {
        numItems = 0;
        capacity = size;
        items = new ItemType[capacity];
    }

    template<class ItemType> // copy constructor
    ArraySet<ItemType>::ArraySet(ArraySet<ItemType>& other) {
        numItems = other.numItems; //copy data members into new object
        capacity = other.capacity;
        items = new ItemType[capacity]; // new dynamic array with elements copied in with a for loop
        for(int i = 0; i < numItems; i++) {
            items[i] = other.items[i];
        }
    }

    template<class ItemType> // assignment operator
    ArraySet<ItemType> ArraySet<ItemType>::operator=(const ArraySet<ItemType>& right) {
        if(this->items != right.items) { // if the two objects are not equal then copy the right object into the left
            numItems = right.numItems;
            capacity = right.capacity;
            delete [] items;
            items = new ItemType[capacity];
            for(int i = 0; i < numItems; i++) {
                items[i] = right.items[i];
            }
        }
        return *this;
    }





    template<class ItemType>
    int ArraySet<ItemType>::size() const {
        return numItems;
    }





    template<class ItemType>
    bool ArraySet<ItemType>::empty() const {
        return numItems == 0;
    }




    template<class ItemType>
    std::vector<ItemType> ArraySet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        for (int i = 0; i < numItems; i++) {
            setContents.push_back(items[i]);
        }

        return setContents;
    }




    template <class ItemType>
    bool ArraySet<ItemType>::contains(const ItemType& anEntry) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == anEntry) {
                return true;
            }
        }
        return false;
    }    





    template<class ItemType>
    void ArraySet<ItemType>::clear() {
        numItems = 0;
    }





    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.

    template<class ItemType>
    int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == target) {
                return i;
            }
        }

        return -1;
    }






    template<class ItemType>
    void ArraySet<ItemType>::erase(const ItemType& anEntry) {
        int locatedIndex = getIndexOf(anEntry);
        if (locatedIndex > -1) {
            numItems--;
            items[locatedIndex] = items[numItems];
        } else {
            throw ItemNotFoundError();
        }
    }







    template<class ItemType>
    int ArraySet<ItemType>::count(const ItemType& anEntry) const {
        int frequency = 0;
        int curIndex = 0;
        while (curIndex < numItems) {
            if (items[curIndex] == anEntry) {
                frequency++;
            }
            curIndex++;
        }
        return frequency;
    }
}
