// Kerwyn Jean
// September 29th, 2024
// ItemType.h file

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student{

public: 

    //constructors
    Student();
    Student(string fidn);

    // setters    
    void setFN(string fn);
    void setLN(string ln);
    
    // getters
    string getFIDN() const;
    string getFN() const;
    string getLN() const;
    
    friend ostream& operator<<(ostream& os, const Student& s); //output: "Hanks,Tom: A000"

private:

   string FIDN; //the format should be "A000
   string FN;
   string LN;

};
#endif
