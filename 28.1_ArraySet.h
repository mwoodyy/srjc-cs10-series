#ifndef ARRAY_SET_H
#define ARRAY_SET_H

#include "SetInterface.h"

namespace cs_set {
    template<class ItemType>
    class ArraySet : public SetInterface<ItemType>
    {
        public:        
            class CapacityExceededError {};
            class ItemNotFoundError {};
            class DuplicateItemError {};

            ArraySet();
            ArraySet(ArraySet<ItemType>& other);
            ArraySet(int size);
            ~ArraySet();
            int size() const;
            bool empty() const;
            void insert(const ItemType& newEntry);
            void erase(const ItemType& anEntry);
            void clear();
            bool contains(const ItemType& anEntry) const;
            int count(const ItemType& anEntry) const;
            std::vector<ItemType> toVector() const;
            ArraySet<ItemType> operator=(const ArraySet<ItemType>&);
        private:
            static const int DEFAULT_CAPACITY = 6;
            ItemType *items;
            int numItems;
            int capacity;

            int getIndexOf(const ItemType& target) const;   
    };
}

//#include "ArraySet.cpp"
#endif
