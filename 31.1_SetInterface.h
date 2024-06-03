#ifndef SET_INTERFACE
#define SET_INTERFACE
#include <vector>

namespace cs_set {
    template<class ItemType>
    class SetInterface
    {
    public:
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual void insert(const ItemType& newEntry) = 0;
        virtual void erase(const ItemType& anEntry) = 0;
        virtual void clear() = 0;
        virtual int count(const ItemType& anEntry) const = 0;
        virtual bool contains(const ItemType& anEntry) const = 0;
        virtual std::vector<ItemType> toVector() const = 0;
        virtual ~SetInterface() { }
    };
}
#endif
