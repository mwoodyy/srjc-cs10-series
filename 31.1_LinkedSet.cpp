/*
Matthew Woody
Dave Harden
CS10C
3/4/2024
Program to implement linked lists with templated classes
  */
#include <iostream>
#include "LinkedSet.h"
#include "Node.cpp"

namespace cs_set {

      template<class ItemType>
      LinkedSet<ItemType>::LinkedSet() {
          headPtr = nullptr;
          itemCount = 0;
      }




// modified copy constructor, just calls the copy function so we dont have to everything written twice
      template<class ItemType>
      LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {
        copy(aSet);
      }


      template<class ItemType>
    void LinkedSet<ItemType>::copy(const LinkedSet<ItemType>& aSet) {
      itemCount = aSet.itemCount;
      Node<ItemType>* origChainPtr = aSet.headPtr;

      if (origChainPtr == nullptr) {
          headPtr = nullptr;
      } else {
          // Copy first node
          headPtr = new Node<ItemType>();
          headPtr->setItem(origChainPtr->getItem());

          // Copy remaining nodes
          Node<ItemType>* newChainPtr = headPtr;
          origChainPtr = origChainPtr->getNext();

          while (origChainPtr != nullptr) {
              // Get next item from original chain
              ItemType nextItem = origChainPtr->getItem();

              // Create a new node containing the next item
              Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

              // Link new node to end of new chain
              newChainPtr->setNext(newNodePtr);

              // Advance pointer to new last node
              newChainPtr = newChainPtr->getNext();

              // Advance original-chain pointer
              origChainPtr = origChainPtr->getNext();
          }

          newChainPtr->setNext(nullptr);
      }
  }





//assignment operator, checks if calling object is equal to argument and then calls copy function to assign, returns calling object
      template<class ItemType>
      LinkedSet<ItemType> LinkedSet<ItemType>::operator=(const LinkedSet<ItemType>& aSet){
        if(this != &aSet){
          clear();
          copy(aSet);
        }
        return *this;
      }





      template<class ItemType>
      LinkedSet<ItemType>::~LinkedSet() {
         clear();
      }





      template<class ItemType>
      bool LinkedSet<ItemType>::empty() const {
          return itemCount == 0;
      }





      template<class ItemType>
      int LinkedSet<ItemType>::size() const {
          return itemCount;
      }





      template<class ItemType>
      void LinkedSet<ItemType>::insert(const ItemType& newEntry) {
          if(this->count(newEntry) >= 1){
            throw DuplicateItemError();
          }
          else{
            Node<ItemType>* nextNodePtr = new Node<ItemType>();
          nextNodePtr->setItem(newEntry);
          nextNodePtr->setNext(headPtr);

          headPtr = nextNodePtr;          // New node is now first node
          itemCount++;
          }
      }





      template<class ItemType>
      std::vector<ItemType> LinkedSet<ItemType>::toVector() const {
          std::vector<ItemType> SetContents;
          Node<ItemType>* curPtr = headPtr;
          while ((curPtr != nullptr)) {
              SetContents.push_back(curPtr->getItem());
              curPtr = curPtr->getNext();
          }

          return SetContents;
      }





      template<class ItemType>
      void LinkedSet<ItemType>::erase(const ItemType& anEntry) {
          Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
          if (entryNodePtr == nullptr) {
              throw ItemNotFoundError();
          } else {
              // replace data of node to delete with data from first node
              entryNodePtr->setItem(headPtr->getItem());

              // Delete first node
              Node<ItemType>* nodeToDeletePtr = headPtr;
              headPtr = headPtr->getNext();
              delete nodeToDeletePtr;

              itemCount--;
          }
      }





      template<class ItemType>
      void LinkedSet<ItemType>::clear() {
          Node<ItemType>* nodeToDeletePtr = headPtr;
          while (headPtr != nullptr) {
              headPtr = headPtr->getNext();
              delete nodeToDeletePtr;
              nodeToDeletePtr = headPtr;
          }

          headPtr = nullptr;
          itemCount = 0;
      }





      template<class ItemType>
      int LinkedSet<ItemType>::count(const ItemType& anEntry) const {
          int frequency = 0;
          int counter = 0;
          Node<ItemType>* curPtr = headPtr;
          while ((curPtr != nullptr) && (counter < itemCount)) {
              if (anEntry == curPtr->getItem()) {
                  frequency++;
              }

              counter++;
              curPtr = curPtr->getNext();
          }

          return frequency;
      }





      template<class ItemType>
      bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {
          return (getPointerTo(anEntry) != nullptr);
      }





      // private
      // Returns either a pointer to the node containing a given entry 
      // or nullptr if the entry is not in the Set.

      template<class ItemType>
      Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& anEntry) const {
          bool found = false;
          Node<ItemType>* curPtr = headPtr;

          while (!found && (curPtr != nullptr)) {
              if (anEntry == curPtr->getItem()) {
                  found = true;
              } else {
                  curPtr = curPtr->getNext();
              }
          }

          return curPtr;
      }
  }
