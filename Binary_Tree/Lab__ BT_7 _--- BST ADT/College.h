// Specification file for the College class
// Written By: A. Student
// Changed By:
// IDE: Xcode

#ifndef COLLEGE_H
#define COLLEGE_H

  
#include<string>

using std::string;
using std::ostream;

class College; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const College &);

class College
{
    private:
        string code;
        string name;
        int rank;
        int cost;

    public:
        //constructors
        College();
        College(int, string, string, int);

        //setters
        void setCode(string cd){ code = cd;}
        void setName(string nm){ name = nm;}
        void setRank(int rk){ rank = rk;}
        void setCost(int cs){ cost = cs;}

        //getters
        string getCode() const {return code;}
        string getName() const {return name;}
        int getRank() const {return rank;}
        int getCost() const {return cost;}

        //other functions
        void hDdisplay()const;
        void vDisplay()const;
    
        // overloaded operators
        bool operator<(const College &college) { return code < college.code; }
        bool operator>(const College &college) { return code > college.code; }
        bool operator==(const College &college) { return code == college.code; }
      
        // Friends
        friend ostream &operator << (ostream &, const College &);
};

#endif
