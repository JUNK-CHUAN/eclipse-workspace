//
// Created by 杨小川 on 2018/10/29.
//

#ifndef LLIST_CLIST_ALIST_H
#define LLIST_CLIST_ALIST_H

#include"List.h"


template <typename E>
//Array-based list implementation
class AList : public List<E>
{
private:
    // Maximum size of list
    int maxSize;
    // Number of list items now
    int listSize;
    //Position of current element
    int curr;
    //Array holding list elements
    E* listArray;

public:
    AList(int size = 0) { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList() { // Destructor
        delete [] listArray;
    }

    void clear() {                  // Reinitialize the list
        delete [] listArray;        // Remove the array
        listSize = curr = 0;        // Reset the size
        listArray = new E[maxSize]; // Recreate array
    }

    // Insert "it" at current position
    void insert(const E& it) {
        //Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--)   // Shift elements up
            listArray[i] = listArray[i-1]; //  to make room
        listArray[curr] = it;
        //increment list size
        listSize++;
    }

    // Append "it"
    void append(const E& it) {
        //Assert(listSize < maxSize, "List capacity exceeded");
        listArray[listSize++] = it;
    }

    // Remove and return the current element.
    E remove() {
        //Assert((curr>=0) && (curr < listSize), "No element");
        E it = listArray[curr];            // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--;                        // Decrement size
        return it;
    }

    void moveToStart() { curr = 0; }             // Reset position
    void moveToEnd() { curr = listSize; }        // Set at end
    void prev() { if (curr != 0) curr--; }       // Back up
    void next() { if (curr < listSize) curr++; } // Next

    // Return list size
    int length() const  { return listSize; }

    // Return current position
    int currPos() const { return curr; }

    // Set current list position to "pos"
    void moveToPos(int pos) {
        //Assert ((pos >= 0) && (pos <= listSize), "pos out of range");
        curr = pos;
    }

    const E& getValue() const {
        //Assert ((curr >= 0) && (curr < listSize), "No current element");
        return listArray[curr];
    }
};


#endif //LLIST_CLIST_ALIST_H
