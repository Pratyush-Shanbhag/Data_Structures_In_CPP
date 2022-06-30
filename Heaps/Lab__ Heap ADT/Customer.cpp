/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by: Pratyush Shanbhag
IDE: VSCode
*~**/
#include <iostream>
#include <string> 
#include "Customer.h"

using namespace std;

/* Write your code here */
Customer::Customer() {
    year = 0;
    mileage = 0;
    seq = 0;
    name = "";
}

Customer::Customer(int y, int m, int s, string n) {
    year = y;
    mileage = m;
    seq = s;
    name = n;
}

void Customer::setYear(int y) {
    year = y;
}

void Customer::setMileage(int m) {
    mileage = m;
}

void Customer::setSeq(int s) {
    seq = s;
}

void Customer::setName(string n) {
    name = n;
}

int Customer::getYear() const {
    return year;
}

int Customer::getMileage() const {
    return mileage;
}

int Customer::getSeq() const {
    return seq;
}

string Customer::getName() const {
    return name;
}

int Customer::getPriorityNumber() const {
    return mileage/1000 + year - seq;
}

int Customer::getSerialNumber() const {
    return getPriorityNumber() * 100 + (100 - seq);
}

bool Customer::operator<(const Customer& c) {
    return getSerialNumber() < c.getSerialNumber();
}

bool Customer::operator>(const Customer& c) {
    return getSerialNumber() > c.getSerialNumber();
}

bool Customer::operator==(const Customer& c) {
    return getSerialNumber() == c.getSerialNumber();
}