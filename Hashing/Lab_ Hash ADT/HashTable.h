// Specification file for the Hash class
// Written By: A. Student
// Changed by: Pratyush Shanbhag


#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

template<class ItemType>
class HashTable
{
    private:
        HashNode<ItemType>* hashAry;
        int hashSize;
        int count;
        
    public:
        HashTable() { count = 0; hashSize = 53; hashAry = new HashNode<ItemType>[hashSize]; }
        HashTable(int n)	{ count = 0; hashSize = n;	hashAry = new HashNode<ItemType>[hashSize]; }
        ~HashTable(){ delete [] hashAry; }

        int getCount() const	{ return count; }
        int getSize() const { return hashSize; }
        double getLoadFactor() const {return 100.0 * count / hashSize; }
        bool isEmpty() const	{ return count == 0; }
        bool isFull()  const	{ return count == hashSize; }
        
        bool insert( const ItemType &itemIn, int h(const ItemType &key, int size) );
        bool remove( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size));
        int  search( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size));
};

/*~*~*~*
   Insert an item into the hash table
   It does not reject duplicates
*~**/
template<class ItemType>
bool HashTable<ItemType>::insert( const ItemType &itemIn, int h(const ItemType &key, int size) )
{
    if (isFull())
        return false;
    
    /* Write your code here */
    int index = h(itemIn, hashSize);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 0) {
            hashAry[index].setItem(itemIn);
            hashAry[index].setNoCollisions(bucketsProbed);
            hashAry[index].setOccupied(1);
            count++;
            return true;
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;      
    }   
    return true;
}

/*~*~*~*
   Removes the item with the matching key from the hash table
     - copies data in the hash node to itemOut
     - replaces data in the hash node with an empty record
*~**/
template<class ItemType>
bool HashTable<ItemType>::remove( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size))
{
    /* Write your code here */
    int index = h(key, hashSize);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 1 && hashAry[index].getItem() == key) {
            itemOut = hashAry[index].getItem();
            hashAry[index] = HashNode<ItemType>();
            count--;
            return true;
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;
    }
    return false;
}

/*~*~*~*
   hash search - linear probe
   if found:
      - copy data to itemOut
      - returns the number of collisions for this key
   if not found, returns -1
*~**/
template<class ItemType>
int HashTable<ItemType>::search(ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size))
{
   
    /* Write your code here */
    int index = h(key, hashSize);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 1 && hashAry[index].getItem() == key) {
            itemOut = hashAry[index].getItem();
            return hashAry[index].getNoCollisions();
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;
    }
     
    return -1;
}

#endif // HASHTABLE_H_