//
// Created by 杨小川 on 2018/10/29.
//

#ifndef LLIST_CLIST_CLIST_H
#define LLIST_CLIST_CLIST_H

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include "List.h"
#include "LList.h"


// Linked list implementation
template <typename E> class CList: public List<E> {
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
    CList() { init(); }                      // Constructor
    ~CList() { removeall(); }                // Destructor
    void print() const;                      // Print list contents
    void clear() { removeall(); init(); }    // Clear list

    // Insert "it" at current position
    void insert(const E& it) {
        if (cnt == 0){
            curr->next = head->next = tail = new Link<E>(it);
            tail->next = head->next;
            cnt++;
        }else{
            curr->next = new Link<E>(it, curr->next);
            if (tail == curr)
                tail = curr->next;
            cnt++;
        }
    }

    // Append "it" to the list
    void append(const E& it) {
        if (cnt == 0){
            curr->next = head->next = tail = new Link<E>(it);
            tail->next = head->next;
            cnt++;
        }else{
            tail = tail->next = new Link<E>(it, head->next);
            cnt++;
        }
    }

    // Remove and return current element
    E remove() {
        if(curr->next != head->next){
            E it = curr->next->element;    // Remember value
            Link<E>* ltemp = curr->next;   // Remember link node
            if (tail == curr->next){
                tail = curr;               // Reset tail
                tail->next = head->next;
            }
            curr->next = curr->next->next; // Remove from list
            delete ltemp;                  // Reclaim space
            cnt--;                         // Decrement the count
            return it;
        }else{
            E it = curr->next->element;    // Remember value
            head->next = head->next->next; // Reset head
            curr->next = curr->next->next; // Remove from list
            cnt--;                         // Decrement the count
            return it;
        }
    }

    // Place current position at list start
    void moveToStart() { curr = head; }

    // Place current position at list end
    void moveToEnd() { curr = tail; }

    // Move current position one step left; no change if already at front
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
        curr = head;
        for(int i=0; i<pos; i++)
            curr = curr->next;
    }

    // Return current element
    const E& getValue() const {
        //Assert (curr->next != NULL, "No value");
        assert(curr->next != NULL);
        return curr->next->element;
    }
};

#endif //LLIST_CLIST_CLIST_H
