// Kerwyn Jean
// September 29th, 2024
// ItemType.h file
#include "Student.h"
#include <iostream>
using namespace std;

// Default constructor
Student::Student() : FIDN(""), FN(""), LN("") {}

// Parameterized constructor
Student::Student(string fidn) : FIDN(fidn), FN(""), LN("") {}

// setters

// setting the first name
void Student::setFN(string fn) {
    FN = fn;
}

// setting the last name
void Student::setLN(string ln) {
    LN = ln;
}

// getters

//getting the id number
string Student::getFIDN() const {
    return FIDN;
}

// getting the first name
string Student::getFN() const {
    return FN;
}

// getting the last name
string Student::getLN() const {
    return LN;
}

// overloaded << operator for output
ostream& operator<<(ostream& os, const Student& s) {
    os << s.LN << "," << s.FN << ": " << s.FIDN;
    return os;
}
