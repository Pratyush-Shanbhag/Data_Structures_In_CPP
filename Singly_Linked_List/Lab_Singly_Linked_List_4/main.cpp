/*
 CIS 22C  // Student is a class, Linked List Node is a class
 
 This program builds and displays a sorted list
 The list is sorted in ascending order by name
 
 Modified by: Pratyush Shanbhag
 IDE: VSCode
 */

#include <iostream>
#include <string>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);
void deleteTestDriver(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;
    
    buildList(list); // insert data into the list
    
    list.displayList();
    string answer;
    cout << "Test Delete [Y/N]?\n";
    cin >> answer;
    if (answer == "Y" || answer == "y")
    {
        deleteTestDriver(list);
        list.displayList();
    }
    return 0;
}

// This function builds a sorted linked list with data from an array
// The Linked list is sorted in ascending order by name
void buildList(StudentList &list)
{
    // Define and initialize an array of Student objects
    Student s[10] = {Student(2.3, "Tom"), Student(2.5, "John"), Student(3.1, "Paul"), Student(3.9, "Linda"), Student(3.6, "Bob"),
                     Student(2.7, "Ann"), Student(4.0, "Mary"), Student(3.2, "Andy"), Student(0, "#")};
        
    //Insert data from array into the linked list
    for (int i = 0; s[i].getName() != "#" ; i++)
    {
        list.insertNode(s[i]);
    }
}

// This function is a test driver for the linked list delete function
void deleteTestDriver(StudentList &list)
{
    string toDelete[] = {"", "Tom", "Andy", "Susan", "Alex", "Zoltan", "Mary", "#"};
    
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, toDelete[0]);
    
    for (int i = 0; toDelete[i] != "#"; i++)
    {
        cout << "   " << toDelete[i];
        if (list.deleteNode(toDelete[i])) // call the deleteNode member function 
            cout << " - deleted\n";
        else
            cout << " - not found\n";
    }
    cout << endl;
}
