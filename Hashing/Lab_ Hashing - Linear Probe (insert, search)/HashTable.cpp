// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Pratyush Shanbhag

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/
bool HashTable::insert( Student &itemIn )
{
    if ( count == hashSize)
        return false;
    /* write your code here */
    int index = _hash(itemIn.getName());
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
   hash delete - linear probe
*~**/
bool HashTable::remove( Student &itemOut )
{
    return false;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - copy number of collisions for this key to noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search( Student &itemOut, int &noCol, string key)
{
    /* write your code here */
    int index = _hash(key);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 1 && hashAry[index].getItem().getName() == key) {
            itemOut = hashAry[index].getItem();
            noCol = hashAry[index].getNoCollisions();
            return true;
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;
    }
     
    return false;
}