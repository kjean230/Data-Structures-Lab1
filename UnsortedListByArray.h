// Kerwyn Jean
// September 29th, 2024
// SPECIFICATION FILE		( UnsortedType.h )
#ifndef UNSORTEDLISTBYARRAY_H
#define UNSORTEDLISTBYARRAY_H

#include "ItemType.h"

class UnsortedListByArray
        // declares a class data type
{
   public:
    // default constructor
    UnsortedListByArray();  
    
    // 10 public member functions
    void MakeEmpty( ); // empty list
    void InsertItem( ItemType  item ); 	// places item in the list
    void DeleteItem( ItemType  item ); 	// deletes item in list

    bool IsFull( ) const; // checks to see if list is full
    bool IsEmpty( ) const; // checks to see if list is empty             
    int  GetLength( ) const;  // returns length of list
    void RetrieveItem( ItemType &  item, bool&  found ); // takes an item from the list

    void ResetList( ); // sets the list to empty
    void GetNextItem( ItemType&  item ); // receives the next item in the list

    bool NewInsertItem(ItemType newItem); // Inserts the item in the list if the list does not have it
    void SplitList(ItemType item, UnsortedListByArray & listOne, UnsortedListByArray & listTwo); // separates the list into two lists
    void Print() const;


   protected:
    int length;
    ItemType info[MAX_ITEM];
    int currentPos;
};

#endif

