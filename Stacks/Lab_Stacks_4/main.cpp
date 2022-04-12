/**~*~*~*
CIS 22C
Project: Stack ADT

Written by: Pratyush Shanbhag
IDE: VSCode
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "StackADT.h"

using namespace std;

void printInfo();
bool processInput(Stack<int>*, string);
void printStack(Stack<int>*, int);


int main()
{
   printInfo();
   
   cout << "Enter input file name: " << endl;
   string filename;
   getline(cin, filename); // assume valid
    
   Stack<int> s;
   
   if(processInput(&s, filename)) {
      cout << "Stack: ";
      if(s.isEmpty())
         cout << "Empty" << endl;
      else
         printStack(&s, s.getLength());
   }

    return 0;
}


/**~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}


/**~*~*~*~*~
This function displays the project's title
*~*/
bool processInput(Stack<int> *s, string filename) {
   int num;
   ifstream infile;
   infile.open(filename);

   while(infile >> num) {
      if(num == 0)
         cout << "Count: " << s->getLength() << endl;
      else if(num == 1)
         cout << "Top: " << s->peek() << endl;
      else if(num > 1)
         s->push(num);
      else {
         printStack(s, abs(num));
      }
   }
   if(s->isEmpty())
      cout << "Empty" << endl;
   else
      printStack(s, s->getLength());
}


/**~*~*~*~*~
This function displays the project's title
*~*/
void printStack(Stack<int> *s, int num) {
   if(s->getLength() < num)
      cout << "Error" << endl;
   else {
      cout << "Stack: ";
      for(int i = 0; i < num; i++) {
         cout << s->pop() << " ";
      }
      cout << endl;
   }
}