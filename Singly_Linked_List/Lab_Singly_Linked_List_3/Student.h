// Specification file for the Student class
// Modified by: Pratyush Shanbhag
// IDE: VSCode

#ifndef STUDENT_H
#define STUDENT_H

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!

using std::string;

class Student
{
    private:
        double gpa;
        string name;

        
    public:
        Student() {
            gpa = 0.0;
            name = "";
        }

        Student(double num, string str) {
            gpa = num;
            name = str;
        }
        
        // Setters and getters
        void setGPA(double num) { gpa = num; }

        double getGPA() { return gpa; }

        void setName(string str) { name = str; }

        string getName() { return name; }
};
#endif