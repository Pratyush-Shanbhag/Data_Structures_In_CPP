/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by: Pratyush Shanbhag
  IDE: VSCode
*~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
 
#include <string>

using std::string;

class Customer
{
    private:
        int year;
        int mileage;
        int seq;
        string name;
    
    public:
        /* Write your code here */
        Customer();
        Customer(int, int, int, string);
        void setYear(int);
        void setMileage(int);
        void setSeq(int);
        void setName(string);
        int getYear() const;
        int getMileage() const;
        int getSeq() const;
        string getName() const;
        int getPriorityNumber() const;
        int getSerialNumber() const;
        bool operator<(const Customer&);
        bool operator>(const Customer&);
        bool operator==(const Customer&);
};

#endif