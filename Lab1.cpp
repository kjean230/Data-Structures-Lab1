// Kerwyn Jean
// September 29th, 2024
// Lab1.cpp

// Lab1.cpp
#include <iostream>
#include "UnsortedListByArray.h"
#include "Student.h"
#include "ItemType.h"

using namespace std;

// Function checking if the user chooses 'Y' or 'y'
bool isYes(char choice) {
    return (choice == 'Y' || choice == 'y');
}

int main() {
    // Create an UnsortedListByArray
    const int MAX_CAPACITY = 6;
    UnsortedListByArray studentList;

    char choice = 'Y';
    int studentCount = 0;

    // asks the user to begin before the while loop
    cout << "Do you want to begin/continue? (Y/N)" << endl;
    cin >> choice;

    while (isYes(choice) && studentCount < MAX_CAPACITY) 
    {
        if (!isYes(choice)) {
            break; // checks to see if the user actually puts in Y or y
        }

        if (studentCount >= MAX_CAPACITY) {
            cout << "The list is full, you have to stop." << endl; // does not give the user to put anymore students in array that is full
            break;
        }

	// getting the students' information
        studentCount++;
        cout << "Student No." << studentCount << ":" << endl;

        string fidn, firstName, lastName;

        cout << "Student FIDN:" << endl;
        cin >> fidn;

        cout << "Student First Name:" << endl;
        cin >> firstName;

        cout << "Student Last Name:" << endl;
        cin >> lastName;

	// setting the students' information
        Student student(fidn);
        student.setFN(firstName);
        student.setLN(lastName);

        ItemType item(student);

        bool inserted = studentList.NewInsertItem(item);
        if (inserted) {
            cout << "A new item is inserted." << endl;
        }
        else {
            cout << "The item is not inserted since it is a duplicate." << endl;
            studentCount--; // since there was a duplicate, the student count goes down one
        }

        // Check if list is full
        if (studentList.IsFull()) {
            cout << "The list is full, you have to stop." << endl;
            break;
        }

	// check to see if the list has space
        if (studentCount < MAX_CAPACITY) {
            cout << "Do you want to continue? (Y/N)" << endl;
            cin >> choice;
        }
    }

    // output
    cout << "You have entered " << studentList.GetLength() << " students into the database." << endl;
    cout << "This is the list:" << endl;
    studentList.Print();

    // splitting the list
    cout << "Please enter the FIDN as the key value to split the student list:" << endl;
    string splitFIDN;
    cin >> splitFIDN;

    Student splitStudent(splitFIDN);
    ItemType splitItem(splitStudent);

    UnsortedListByArray listOne;
    UnsortedListByArray listTwo;

    cout << "Split the previous list with ,: " << splitFIDN << endl; // user puts in the id number to split the list with
    studentList.SplitList(splitItem, listOne, listTwo);

    cout << "After split:" << endl;

    // prints out list one
    cout << "list one is :" << endl;
    listOne.Print();

    // ptints out list two
    cout << "list two is :" << endl;
    listTwo.Print();

    cout << "After split, original list is :" << endl;
    studentList.Print();

    cout << "exit" << endl;

    return 0;
}
