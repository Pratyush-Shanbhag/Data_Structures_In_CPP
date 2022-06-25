// Specification file for the Hash class
// Written By: A. Student
// Changed by: Pratyush Shanbhag


#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode_1.h"
#include <string>

class HashTable
{
    private:
        HashNode* hashAry;
        int hashSize;
        int count;
        
    public:
        HashTable() { count = 0; hashSize = 27; hashAry = new HashNode[hashSize]; }
        HashTable(int n)	{ count = 0; hashSize = n;	hashAry = new HashNode[hashSize]; }
        ~HashTable(){ delete [] hashAry; }

        int getCount() const { return count; }
        int getSize() const { return hashSize; }
        double getLoadFactor() const { return 100.0 * count / hashSize; }
        int getNumCollisions() const;
        int getLongestColPath() const;
        bool isEmpty() const { return count == 0; }
        bool isFull()  const { return count == hashSize; }
        
        bool insert(Student &itemIn);
        bool remove(Student &itemOut, std::string key);
        int search(Student &itemOut, std::string key);

        void rehash(HashTable &ht);
        
    private:
        int _hash(std::string key) const;
};

#endif // HASHTABLE_H_