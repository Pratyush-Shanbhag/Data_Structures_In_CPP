// Specification file for the HashNode class
// Written By: Pratyush Shanbhag

#ifndef _HASH_NODE
#define _HASH_NODE

// convert to template
template<class ItemType>
class HashNode
{
    private:
        ItemType item;
        int occupied;    // 1 -> occupied, 0 -> empty from start, -1 -> empty after removal 
        

    public:
        // constructors
        HashNode() {occupied = 0;}
        HashNode(ItemType anItem) {item = anItem; occupied = 1;}
        HashNode(ItemType anItem, int ocp,)
                {item = anItem; occupied = ocp;}
        // setters
        void setItem(const ItemType & anItem) {item = anItem;}
        void setOccupied(int ocp) {occupied = ocp;}
        
        // getters
        ItemType getItem() const {return item;}
        int getOccupied() const {return occupied;}
};

#endif