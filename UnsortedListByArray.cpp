// Kerwyn Jean
// September 29th, 2024
#include "UnsortedListByArray.h"
#include <iostream>

UnsortedListByArray::UnsortedListByArray() 
{ 
    length = 0;
    currentPos = -1;
}

bool UnsortedListByArray::IsFull() const 
{ 
    return (length == MAX_ITEM); 
}

int UnsortedListByArray::GetLength() const 
{ 
    return length; 
}

bool UnsortedListByArray::IsEmpty() const 
{ 
    return (length == 0); 
}

void UnsortedListByArray::InsertItem(ItemType item)
// Post: item is in the list.
{
    info[length] = item;
    length++;
}

void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
    bool moreToSearch;
    int location = 0;
    found = false;
    moreToSearch = (location < length);
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location])) {
            case LESS:
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                found = true;
                item = info[location];
                break;
        }
    }
}

void UnsortedListByArray::DeleteItem(ItemType item)
// Pre: item's key has been inititalized.
//	One and only one element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL) 
    location++;
    // move last element into position where item was located

    info[location] = info[length - 1];
    length--;  // the length of the list is decreased
}

void UnsortedListByArray::MakeEmpty()
// Pre:  N/A
// Post: the list is empty
{
    length = 0;
}

void UnsortedListByArray::ResetList()
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{
    currentPos = -1;
}

void UnsortedListByArray::GetNextItem(ItemType& item)
// Pre:  List has been initialized. Current position is
//       defined.
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
    currentPos++;
    item = info[currentPos];
}

void UnsortedListByArray::SplitList(ItemType item, UnsortedListByArray &listOne, UnsortedListByArray &listTwo)
{
for (int i = 0; i < length; ++i) 
{
    RelationType relation = info[i].ComparedTo(item);

    if (relation == LESS || relation == EQUAL) 
    {
        listOne.InsertItem(info[i]);
    }
    else if (relation == GREATER) 
    {
        listTwo.InsertItem(info[i]);
    }
}
     
}

bool UnsortedListByArray::NewInsertItem(ItemType newItem)
{
    // Check for duplicates without using existing member functions
    for (int i = 0; i < length; i++) 
    {
        if (info[i].ComparedTo(newItem) == EQUAL) // Compare based on FIDN
        { 
            return false; // Duplicate found, do not insert
        }
    }

    if (IsFull()) 
    {
        std::cout << "The list is full, you have to stop." << std::endl;
        return false; // List is full, cannot insert
    }

    info[length] = newItem;
    length++;
    return true;
}

void UnsortedListByArray::Print() const {
    for (int i = 0; i < length; i++) 
    {
        info[i].Print();
        std::cout << std::endl;
    }
}
