/**~*~*~*
CIS 22C
Project: Queue ADT

Written by: Pratyush Shanbhag
IDE: VSCode
*~*/

#include <iostream>
#include <string>

#include "QueueADT.h"


using namespace std;

int main() {

    // Create the first queue (strings)
    Queue<string> que1;
    
    string item;
    cin >> item;
    // Write a loop to enter an unknown number of names (assume one word strings).
    // The loop stops when you enter #.
    // As you are entering names, they are to be inserted into the first queue.
    while(item != "#") {
        que1.push(item);
        cin >> item;
    }

    if(que1.isEmpty()) {
        cout << "Empty Queue!" << endl;
    }
    else {
        // Test the getLength function: - display the number of elements in the first queue
        cout << que1.getLength() << " ";
        
        // Create the second queue (doubles)
        Queue<double> que2;

        // Test the getLength function: - display the number of elements in the second queue
                                    // (it should be 0!)
        cout << que2.getLength() << endl;

        // Write another loop to enter the number of units (double) into a parallel queue.
        double num;
        for(int i = 0; i < que1.getLength(); i++) {
            cin >> num;
            que2.push(num);
        }
        
        // Display the two queues in parallel.
        for(int i = 0; i < que1.getLength(); i++) {
            cout << que1.getItem(i) << " " << que2.getItem(i) << endl;
        }        
        
        // Display the front element in the first queue
        cout << que1.peek() << endl;
        
        // Display the rear element in the second queue
        cout << que2.peekRear() << endl;
    }

    return 0;
}
