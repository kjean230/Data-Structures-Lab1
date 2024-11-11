// Kerwyn Jean
// September 27th, 2024
// C++ Code for ItemType.h




// ItemType.h
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include "Student.h"

const int MAX_ITEM = 6;
enum RelationType { LESS, EQUAL, GREATER };

class ItemType {
public:
    ItemType() {} // Default constructor

    ItemType(const Student& student) : value(student) {}

    // function that compares values
    RelationType ComparedTo(ItemType otherItem) const {
        if (value.getFIDN() < otherItem.value.getFIDN())
            return LESS;
        else if (value.getFIDN() > otherItem.value.getFIDN())
            return GREATER;
        else
            return EQUAL;
    }

    // function that prints values
    void Print() const {
        std::cout << value << std::endl;
    }

    void Initialize(const Student& student) {
        value = student;
    }

    // overloading operators
    bool operator==(const ItemType& other) const {
        return value.getFIDN() == other.value.getFIDN();
    }

    bool operator<(const ItemType& other) const {
        return value.getFIDN() < other.value.getFIDN();
    }

private:
    Student value; 
};

#endif // ITEMTYPE_H

