//
// Created by 杨小川 on 2018/10/29.
//

#ifndef LLIST_CLIST_LLIST_H
#define LLIST_CLIST_LLIST_H

#include <iostream>
#include <cstdio>
#include <assert.h>
#include "List.h"
using namespace std;


//Singly linked list node with freelist support
template<typename E>
class Link
{
	static Link<E>* freelist; // Reference to freelist head
public:
    // Value for this node
    E element;
    // Pointer to next node in list
    Link *next;

    // Constructors
    Link(const E& elemval, Link* nextval = NULL) {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval = NULL) {
        next = nextval;
    }

    // Overload new operator
    void* operator new(size_t) {
    	if (freelist == NULL) return ::new Link; // Create space
    	Link<E>* temp = freelist;                // Can take from freelist
    	freelist = freelist->next;
    	return temp;                             // Return the link
    }

    void operator delete(void* ptr) {
    	((Link<E>*)ptr)->next = freelist;
    	freelist = (Link<E>*)ptr;
    }
};

// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;


// Linked list implementation
template <typename E>
class LList: public List<E> {
private:
    // Point to list header
    Link<E>* head;
    // Point to last element
    Link<E>* tail;
    // Access to current element
    Link<E>* curr;
    int cnt;// Size of list

    // Intialization helper method
    void init() {
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    // Return link nodes to free store
    void removeall() {
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList() { init(); }  // Constructor
    ~LList() { removeall(); }                  // Destructor
    void print() const;                        // Print list contents
    void clear() { removeall(); init(); }      // Clear list

    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr)
            tail = curr->next;
        cnt++;
    }

    // Append "it" to the list
    void append(const E& it) {
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }

    // Remove and return current element
    E remove() {
        //Assert(curr->next != NULL, "No element");
        assert(curr->next != NULL);
        /*if (curr->next == NULL) {
            cout << "No element" << endl;
            return NULL;
        }*/
        E it = curr->next->element;    // Remember value
        Link<E>* ltemp = curr->next;   // Remember link node
        if (tail == curr->next)
            tail = curr;               // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement the count
        return it;
    }

    // Place current position at list start
    void moveToStart() { curr = head; }

    // Place current position at list end
    void moveToEnd() { curr = tail; }

    // Move current position one step left; nochange if already at front
    void prev() {
        if (curr == head)  // No previous element
            return;
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next != curr)
            temp = temp->next;
        curr = temp;
    }

    // Move current position one step right; No change if already at end
    void next() {
        if (curr != tail)
            curr = curr->next;
    }

    //return length
    int length() const  { return cnt; }

    // Return the position of the current element
    int currPos() const  {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }

    // Move down list to "pos" position
    void moveToPos(int pos) {
        //Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        if (pos<0||pos>cnt) {
            cout << "Position out of range" << endl;
            return;
        }
        curr = head;
        for(int i=0; i<pos; i++)
            curr = curr->next;
    }

    // Return current element
    const E& getValue() const {
        //Assert (curr->next != NULL, "No value");
        assert(curr->next != NULL);
        /*if (curr->next == NULL) {
            cout << "No value" << endl;
            return NULL;
        }*/
        return curr->next->element;
    }
};

#endif //LLIST_CLIST_LLIST_H
