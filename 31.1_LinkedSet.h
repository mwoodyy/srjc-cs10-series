#ifndef LINKED_SET
#define LINKED_SET

#include "SetInterface.h"
#include "Node.h"

namespace cs_set {

    template<class ItemType>
    class LinkedSet : public SetInterface<ItemType>
    {   
        public:
            class ItemNotFoundError {};
            class DuplicateItemError {};
            LinkedSet();
            LinkedSet(const LinkedSet<ItemType>& aSet);
            LinkedSet operator=(const LinkedSet& aSet);
            virtual ~LinkedSet();
            int size() const;
            bool empty() const;
            void insert(const ItemType& newEntry);
            void erase(const ItemType& anEntry);
            void clear();
            bool contains(const ItemType& anEntry) const;
            int count(const ItemType& anEntry) const;
            std::vector<ItemType> toVector() const;
        private:
            void copy(const LinkedSet<ItemType>& aSet);
            Node<ItemType>* headPtr;
            int itemCount;

            // Returns either a pointer to the node containing a given entry
            // or nullptr if the entry is not in the Set.
            Node<ItemType>* getPointerTo(const ItemType& target) const;
    };
}

#endif
