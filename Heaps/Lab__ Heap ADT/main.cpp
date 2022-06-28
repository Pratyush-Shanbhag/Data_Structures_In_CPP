/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By: Pratyush Shanbhag
  IDE: VSCode
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

#include "Customer.h"
#include "Heap.h"

using namespace std;

/* Write your code here */
int compareMin(Customer&, Customer&);
int compareMax(Customer&, Customer&);

int main()
{
    string inputFileName;
    cout << "Input file name: ";
    getline(cin, inputFileName);
    
    ifstream inFile(inputFileName);
    if (!inFile) {
        cout << "Error opening the input file: \"" << inputFileName << "\"" << endl;
        exit(EXIT_FAILURE);
    }
    
    /* Write your code here */
    Heap<Customer> heap;

    string border = " ==== =======   =============\n";
    cout << border << " Year Mileage   Name\n" << border;

    string line;
    string status;
    int y;
    int m;
    int s = 1;
    string n;
    int served = 0;
    int overbooked;
    while(getline(inFile, line)) {
        stringstream ss(line);
        ss >> status;
        if(status == "A") {
           ss >> y;
           ss >> m;
           getline(ss, n);
           Customer c(y, m, s, n);
           heap.insertHeap(c, compareMax);
           s++;
        }
        else if(status == "S") {
           Customer rc;
           heap.deleteHeap(rc, compareMax);
           cout << right << setw(4) << rc.getYear() << "  " << left << setw(9) << rc.getMileage();
           cout << rc.getName() << endl;
           served++;
        }
    }

    inFile.close();
    
    /* Write your code here */
    overbooked = heap.getCount();
    cout << border << "Served overbooked customers: " << served << "\n\n";
    cout << border << " Year Mileage   Name\n" << border;
    while(!heap.isEmpty()) {
      Customer rc;
      heap.deleteHeap(rc, compareMax);
      cout << right << setw(4) << rc.getYear() << "  " << left << setw(9) << rc.getMileage();
      cout << rc.getName() << endl;
    }
    cout << border << "Rejected overbooked customers: " << overbooked << endl;
   
    return 0;
}

/* Write your code here */ 
/*
  compare two data items: needed to build a min-heap
*/
int compareMin(Customer &x, Customer &y)
{
    if (x < y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}

/*
  compare two data items: needed to build a max-heap
*/
int compareMax(Customer &x, Customer &y)
{
    if (x > y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}