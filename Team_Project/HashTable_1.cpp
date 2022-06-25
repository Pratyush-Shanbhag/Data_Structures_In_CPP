// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Pratyush Shanbhag

#include <string>

#include "HashTable_1.h"

using namespace std;

/*~*~*~*
  A simple hash function
*~**/

int HashTable::_hash(string key) const
{
    long int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += key[i] * key[i] * key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/
bool HashTable::insert(Student &itemIn)
{
    if (isFull())
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
            rehash();
            return true;
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;      
    }   
}

/*~*~*~*
   hash delete - linear probe
   - looks for key in hash table
   - if found:
       - copies its data to itemOut 
       - replaces data in the hash node with an "empty" record
       - returns true
   - if not found - returns false
*~**/
bool HashTable::remove(Student &itemOut, string key)
{
    /* Write your code here */
    int index = _hash(key);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 1 && hashAry[index].getItem().getName() == key) {
            itemOut = hashAry[index].getItem();
            hashAry[index] = HashNode();
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
int HashTable::search(Student &itemOut, string key)
{
   /* write your code here */
    int index = _hash(key);
    int bucketsProbed = 0;

    while(bucketsProbed < hashSize) {
        if(hashAry[index].getOccupied() == 1 && hashAry[index].getItem().getName() == key) {
            itemOut = hashAry[index].getItem();
            return hashAry[index].getNoCollisions();
        }

        index = (index + 1) % hashSize;
        bucketsProbed++;
    }
     
    return -1;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - returns the number of collisions for this key 
   if not found, returns -1
*~**/
int HashTable::getNumCollisions() const {
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += hashAry[i].getNoCollisions();
    }
    return sum;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - returns the number of collisions for this key 
   if not found, returns -1
*~**/
int HashTable::getLongestColPath() const {
    int numCol = 0;
    for(int i = 0; i < count; i++) {
        if(numCol < hashAry[i].getNoCollisions())
            numCol = hashAry[i].getNoCollisions();
    }
    return numCol;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - returns the number of collisions for this key 
   if not found, returns -1
*~**/
void HashTable::rehash(HashTable &ht) {

}