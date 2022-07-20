// Specification file for the LinkedList class
// Written By: A. Student
// Changed By: Pratyush Shanbhag
// IDE: VSCode

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNode.h"
class LinkedList
{
private:
  ListNode *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertNode(College);
    bool deleteNode(string);
    void displayListForw() const;
    void displayListBack() const;
    bool searchList(string, College &) const;
};

#endif

